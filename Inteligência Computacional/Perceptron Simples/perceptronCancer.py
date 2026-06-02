# Importando as bibliotecas necessárias
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Perceptron
from sklearn import metrics

# 1. Carregando os dados embutidos (equivalente ao link fornecido)
dados_cancer = load_breast_cancer()
X = dados_cancer.data
Y = dados_cancer.target  # 0: Maligno, 1: Benigno

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
print("--- Resultados no Dataset Breast Cancer Wisconsin ---")

# Matriz de Confusão
cnf_matrix = metrics.confusion_matrix(Y_test, Y_pred)
print("\nMatriz de Confusão (2x2):")
print(cnf_matrix)

# Extraindo os valores: Verdadeiro Negativo, Falso Positivo, Falso Negativo, Verdadeiro Positivo
VN, FP, FN, VP = cnf_matrix.ravel()

# Calculando as métricas
acuracia = metrics.accuracy_score(Y_test, Y_pred)

# Sensibilidade: Capacidade de identificar corretamente os casos positivos (Benignos, neste contexto do sklearn)
sensibilidade = VP / (VP + FN) if (VP + FN) > 0 else 0

# Especificidade: Capacidade de identificar corretamente os casos negativos (Malignos)
especificidade = VN / (VN + FP) if (VN + FP) > 0 else 0

print("\n--- Métricas ---")
print(f"Acurácia: {acuracia:.4f}")
print(f"Sensibilidade (Recall): {sensibilidade:.4f}")
print(f"Especificidade: {especificidade:.4f}")