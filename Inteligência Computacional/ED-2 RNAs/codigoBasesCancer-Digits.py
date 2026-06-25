import pandas as pd
from sklearn.datasets import load_breast_cancer, load_digits
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report, f1_score
import warnings
from sklearn.exceptions import ConvergenceWarning

warnings.filterwarnings("ignore", category=ConvergenceWarning)

def treinar_e_avaliar_modelo(X, y, nome_dataset):

    print(f"Treinando Rede Neural para: {nome_dataset}")
    
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)
    
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)
    
    mlp = MLPClassifier(max_iter=1000, random_state=42)
    
    param_grid = {
        'hidden_layer_sizes': [(50,), (100,), (50, 50)], 
        'activation': ['relu', 'tanh'],                  
        'alpha': [0.0001, 0.01],                         
        'learning_rate_init': [0.001, 0.01]              
    }
    
    grid_search = GridSearchCV(mlp, param_grid, cv=3, scoring='f1_weighted', n_jobs=-1, verbose=0)
    grid_search.fit(X_train_scaled, y_train)
    
    melhor_modelo = grid_search.best_estimator_
    
    print(f"Melhores Hiperparâmetros: {grid_search.best_params_}")
    
    y_pred = melhor_modelo.predict(X_test_scaled)
    
    f1 = f1_score(y_test, y_pred, average='weighted')
    
    print(f"\nDesempenho no conjunto de teste: {f1:.4f}")
    print("\nRelatório de Classificação:")
    print(classification_report(y_test, y_pred))
    print("\n")

cancer_data = load_breast_cancer()
X_cancer = cancer_data.data
y_cancer = cancer_data.target

treinar_e_avaliar_modelo(X_cancer, y_cancer, "Breast Cancer Wisconsin")

digits_data = load_digits()
X_digits = digits_data.data
y_digits = digits_data.target

treinar_e_avaliar_modelo(X_digits, y_digits, "Optical Recognition of Handwritten Digits")