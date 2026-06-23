import pandas as pd
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report, f1_score
from sklearn.pipeline import Pipeline

import warnings
warnings.filterwarnings('ignore') 

url = "https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv"
data = pd.read_csv(url, sep=';')

X = data.drop('quality', axis=1)
y = data['quality']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

pipeline = Pipeline([
    ('scaler', StandardScaler()),
    ('mlp', MLPClassifier(max_iter=1000, random_state=42))
])

param_grid = {
    'mlp__hidden_layer_sizes': [(50,), (100,), (50, 50), (100, 50)], 
    'mlp__activation': ['relu', 'tanh'],
    'mlp__solver': ['adam'], 
    'mlp__alpha': [0.0001, 0.001, 0.01], 
    'mlp__learning_rate_init': [0.001, 0.01]
}

grid_search = GridSearchCV(
    pipeline, 
    param_grid, 
    cv=5, 
    scoring='f1_weighted', 
    n_jobs=-1, 
    verbose=1
)

print("Iniciando o treinamento ...")
grid_search.fit(X_train, y_train)

print("\n--- Resultados ---")

print(f"Melhores Hiperparâmetros: {grid_search.best_params_}")

best_model = grid_search.best_estimator_
y_pred = best_model.predict(X_test)

f1_final = f1_score(y_test, y_pred, average='weighted')
print(f"\nF1-Score no Conjunto de Teste: {f1_final:.4f}")

print("\nRelatório de Classificação:")
print(classification_report(y_test, y_pred, zero_division=0))