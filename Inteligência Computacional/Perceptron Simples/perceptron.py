import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import Perceptron
from sklearn import metrics


url = "https://archive.ics.uci.edu/ml/machine-learning-databases/undocumented/connectionist-bench/sonar/sonar.all-data"

df = pd.read_csv(url, header=None)

# O dataset tem 61 colunas. As primeiras 60 são as leituras do sonar (X).
# A última coluna (índice 60) é a resposta (Y): 'M' para Mina ou 'R' para Rocha.

X = df.iloc[:, :-1]  # Pega todas as linhas e todas as colunas, exceto a última

Y_texto = df.iloc[:, -1] # Pega apenas a última coluna


# Mina ('M') = 1 (Positivo) e Rocha ('R') = 0 (Negativo)
Y = (Y_texto == 'M').astype(int)

# 3. Dividindo em treino (70%) e teste (30%)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=42)

# 4. Normalizando os dados (Novamente, essencial para o Perceptron)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 5. Treinando o modelo
p = Perceptron(random_state=42, max_iter=5000, tol=0.001, shuffle=True)

p.fit(X_train, Y_train)

# 6. Fazendo a previsão no conjunto de teste
Y_pred = p.predict(X_test)

# letra d)

cnf_matrix = metrics.confusion_matrix(Y_test, Y_pred)

print("Matriz de Confusão:")
print(cnf_matrix)

# Extraindo VN, FP, FN, VP
VN, FP, FN, VP = cnf_matrix.ravel()

acuracia = metrics.accuracy_score(Y_test, Y_pred)

# Sensibilidade (Taxa de acerto para Minas)
sensibilidade = VP / (VP + FN) if (VP + FN) > 0 else 0

# Especificidade (Taxa de acerto para Rochas)
especificidade = VN / (VN + FP) if (VN + FP) > 0 else 0

print("\n--- Resultados no Dataset SONAR ---")
print(f"Acurácia: {acuracia:.4f}")
print(f"Sensibilidade (Acertar Minas): {sensibilidade:.4f}")
print(f"Especificidade (Acertar Rochas): {especificidade:.4f}")