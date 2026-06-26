import os
import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.applications import DenseNet121, ResNet50V2
from tensorflow.keras.layers import Dense, Flatten, Dropout
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam
import matplotlib.pyplot as plt

CAMINHO_DO_DATASET = '/home/gabriel/.cache/kagglehub/datasets/vipoooool/new-plant-diseases-dataset/versions/2/New Plant Diseases Dataset(Augmented)/New Plant Diseases Dataset(Augmented)/train'

TAMANHO_IMAGEM = (224, 224)
TAMANHO_LOTE = 32 
EPOCAS = 10

print("Carregando imagens de:", CAMINHO_DO_DATASET)

datagen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=20,
    zoom_range=0.2,
    horizontal_flip=True,
    validation_split=0.2 
)

print("\n--- Carregando Dados de Treino ---")
train_generator = datagen.flow_from_directory(
    CAMINHO_DO_DATASET,
    target_size=TAMANHO_IMAGEM,
    batch_size=TAMANHO_LOTE,
    class_mode='categorical',
    subset='training'
)

print("\n--- Carregando Dados de Validação ---")
validation_generator = datagen.flow_from_directory(
    CAMINHO_DO_DATASET,
    target_size=TAMANHO_IMAGEM,
    batch_size=TAMANHO_LOTE,
    class_mode='categorical',
    subset='validation'
)

NUM_CLASSES = train_generator.num_classes

# 3. MODELO 1: DENSENET121

print("\n==========================================")
print("INICIANDO TREINAMENTO: DENSENET121")
print("==========================================")

base_densenet = DenseNet121(weights='imagenet', include_top=False, input_shape=(224, 224, 3))
base_densenet.trainable = False 

x1 = Flatten()(base_densenet.output)
x1 = Dense(256, activation='relu')(x1)
x1 = Dropout(0.2)(x1)
saida_densenet = Dense(NUM_CLASSES, activation='softmax')(x1)

modelo_densenet = Model(inputs=base_densenet.inputs, outputs=saida_densenet)
modelo_densenet.compile(loss='categorical_crossentropy', optimizer=Adam(learning_rate=0.0001), metrics=['accuracy'])

historico_densenet = modelo_densenet.fit(
    train_generator,
    validation_data=validation_generator,
    epochs=EPOCAS
)

# 4. MODELO 2: RESNET50V2

print("\n==========================================")
print("INICIANDO TREINAMENTO: RESNET50V2")
print("==========================================")

base_resnet = ResNet50V2(weights='imagenet', include_top=False, input_shape=(224, 224, 3))
base_resnet.trainable = False 

x2 = Flatten()(base_resnet.output)
x2 = Dense(256, activation='relu')(x2)
x2 = Dropout(0.2)(x2)
saida_resnet = Dense(NUM_CLASSES, activation='softmax')(x2)

modelo_resnet = Model(inputs=base_resnet.inputs, outputs=saida_resnet)
modelo_resnet.compile(loss='categorical_crossentropy', optimizer=Adam(learning_rate=0.0001), metrics=['accuracy'])

historico_resnet = modelo_resnet.fit(
    train_generator,
    validation_data=validation_generator,
    epochs=EPOCAS
)

# ==========================================
# 5. COMPARAÇÃO E RESULTADOS VISUAIS
# ==========================================
print("\nGerando gráficos de comparação...")

plt.figure(figsize=(12, 5))

# Gráfico de Acurácia
plt.subplot(1, 2, 1)
plt.plot(historico_densenet.history['val_accuracy'], label='DenseNet121 - Validação', color='blue', marker='o')
plt.plot(historico_resnet.history['val_accuracy'], label='ResNet50V2 - Validação', color='red', marker='x')
plt.title('Comparação de Acurácia (Validação)')
plt.xlabel('Época')
plt.ylabel('Acurácia')
plt.legend()
plt.grid(True)

# Gráfico de Perda (Loss)
plt.subplot(1, 2, 2)
plt.plot(historico_densenet.history['val_loss'], label='DenseNet121 - Validação', color='blue', marker='o')
plt.plot(historico_resnet.history['val_loss'], label='ResNet50V2 - Validação', color='red', marker='x')
plt.title('Comparação de Perda / Loss (Validação)')
plt.xlabel('Época')
plt.ylabel('Loss')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

print("\nTreinamento finalizado! Avalie os gráficos gerados para decidir o melhor modelo.")