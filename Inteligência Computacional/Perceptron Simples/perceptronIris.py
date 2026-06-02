# Importando as bibliotecas necessárias
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Perceptron
from sklearn import metrics

# 1. Carregando os dados embutidos
iris = load_iris()
X = iris.data
Y = iris.target  # Classes: 0, 1 e 2

# 2. Dividindo os dados (70% para treino e 30% para teste)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=42)

# 3. Normalizando os dados (Sempre importante para o Perceptron)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 4. Configurando e Treinando o modelo Perceptron
p = Perceptron(random_state=42, max_iter=5000, 
               tol=0.001, shuffle=True, n_iter_no_change=100)
p.fit(X_train, Y_train)

# 5. Fazendo previsões
Y_pred = p.predict(X_test)

# 6. Avaliando o Modelo
print("--- Resultados no Dataset IRIS (Multiclasse) ---")

# Matriz de Confusão
cnf_matrix = metrics.confusion_matrix(Y_test, Y_pred)
print("\nMatriz de Confusão (3x3):")
print(cnf_matrix)

# Acurácia
acuracia = metrics.accuracy_score(Y_test, Y_pred)

# Sensibilidade (Recall) usando média Macro para problemas Multiclasse
sensibilidade = metrics.recall_score(Y_test, Y_pred, average='macro')

print("\n--- Métricas ---")
print(f"Acurácia: {acuracia:.4f}")
print(f"Sensibilidade (Macro Recall): {sensibilidade:.4f}")
print("Especificidade: Não calculada globalmente para > 2 classes.")