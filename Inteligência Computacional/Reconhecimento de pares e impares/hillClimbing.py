import pandas as pd
import numpy as np
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import KFold
from sklearn.metrics import accuracy_score
import wittgenstein as lw
import warnings

# Ignora avisos chatos de compatibilidade
warnings.filterwarnings("ignore")

# 1. Carregar dataset
print("Carregando dataset...")
df = pd.read_csv('semeion_par_impar.csv', header=None)
X = df.iloc[:, :256]  # Os 256 pixels
y = df.iloc[:, 256]   # 0 (Par) ou 1 (Ímpar)

# --- NOVA FUNÇÃO DE AVALIAÇÃO SEGURA ---
def avaliacao_segura(modelo, X_subset, y, cv=3):
    """
    Faz a validação cruzada manualmente para evitar erros de 
    incompatibilidade da biblioteca wittgenstein com o sklearn moderno.
    """
    kf = KFold(n_splits=cv, shuffle=True, random_state=42)
    scores = []
    
    for train_index, test_index in kf.split(X_subset):
        X_train, X_test = X_subset.iloc[train_index], X_subset.iloc[test_index]
        y_train, y_test = y.iloc[train_index], y.iloc[test_index]
        
        # Treina e prevê de forma padrão
        modelo.fit(X_train, y_train)
        preds = modelo.predict(X_test)
        
        # O Wittgenstein as vezes retorna booleanos, garantimos que sejam ints
        if isinstance(preds[0], bool):
            preds = [int(p) for p in preds]
            
        scores.append(accuracy_score(y_test, preds))
        
    return np.mean(scores)
# ---------------------------------------

# 2. Wrapper com Hill-Climbing
def hill_climbing_wrapper(X, y, modelo, max_pixels=10):
    pixels_selecionados = []
    pixels_restantes = list(X.columns)
    melhor_acuracia_global = 0.0
    
    print(f"\nIniciando Hill-Climbing para {modelo.__class__.__name__}...")
    
    while pixels_restantes and len(pixels_selecionados) < max_pixels:
        melhor_acuracia_local = 0.0
        melhor_pixel_local = None
        
        for pixel in pixels_restantes:
            subconjunto_atual = pixels_selecionados + [pixel]
            X_subset = X[subconjunto_atual]
            
            # Usamos a nova função aqui!
            acuracia = avaliacao_segura(modelo, X_subset, y, cv=3)
            
            if acuracia > melhor_acuracia_local:
                melhor_acuracia_local = acuracia
                melhor_pixel_local = pixel
                
        if melhor_acuracia_local > melhor_acuracia_global:
            melhor_acuracia_global = melhor_acuracia_local
            pixels_selecionados.append(melhor_pixel_local)
            pixels_restantes.remove(melhor_pixel_local)
            print(f"-> Pixel {melhor_pixel_local} adicionado. Acurácia subiu para: {melhor_acuracia_global:.4f}")
        else:
            print("-> Nenhuma melhoria encontrada. Pico local atingido!")
            break
            
    print(f"\nBusca finalizada! {len(pixels_selecionados)} pixels selecionados.")
    return pixels_selecionados, melhor_acuracia_global

# 3. Modelos
modelo_id3 = DecisionTreeClassifier(criterion='entropy', random_state=42)
modelo_ripper = lw.RIPPER(random_state=42)

# 4. Execução
print("==========================================")
pixels_id3, acc_id3 = hill_climbing_wrapper(X, y, modelo_id3, max_pixels=10)

print("==========================================")
# Nota: O RIPPER vai demorar bem mais que o ID3
pixels_ripper, acc_ripper = hill_climbing_wrapper(X, y, modelo_ripper, max_pixels=10)

print("\n=== RESUMO FINAL ===")
print(f"ID3: {acc_id3*100:.2f}% de acurácia com os pixels {pixels_id3}")
print(f"RIPPER: {acc_ripper*100:.2f}% de acurácia com os pixels {pixels_ripper}")