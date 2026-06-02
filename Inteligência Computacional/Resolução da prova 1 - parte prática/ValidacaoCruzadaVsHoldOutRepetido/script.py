import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import RepeatedStratifiedKFold
from sklearn.naive_bayes import CategoricalNB
from sklearn.metrics import accuracy_score
from scipy.stats import ttest_rel
import wittgenstein
from sklearn.preprocessing import OrdinalEncoder

# 1. Carregar a base de dados
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/chess/king-rook-vs-king-pawn/kr-vs-kp.data"
df = pd.read_csv(url, header=None)

# Separar atributos
X = df.iloc[:, :-1].astype(str)
y = df.iloc[:, -1].astype(str)

# 2. Preparar dados para o Naive Bayes
oe = OrdinalEncoder()
X_encoded = oe.fit_transform(X)

#Descobrir o número exato de categorias possíveis por coluna
n_categories = [len(cats) for cats in oe.categories_]

# 3. Configurar a Validação
cv = RepeatedStratifiedKFold(n_splits=10, n_repeats=3, random_state=42)

scores_nb = []
scores_irep = []

print("Executando a validação cruzada")

for train_idx, test_idx in cv.split(X, y):
    # Naive Bayes
    X_train_enc, X_test_enc = X_encoded[train_idx], X_encoded[test_idx]
    y_train, y_test = y.iloc[train_idx], y.iloc[test_idx]

    # Treinar e avaliar Naive Bayes
    nb = CategoricalNB(min_categories=n_categories)
    nb.fit(X_train_enc, y_train)
    preds_nb = nb.predict(X_test_enc)
    scores_nb.append(accuracy_score(y_test, preds_nb))

    # IREP
    X_train_cat, X_test_cat = X.iloc[train_idx], X.iloc[test_idx]

    # Treinar e avaliar IREP/RIPPER
    irep = wittgenstein.RIPPER(random_state=42)
    irep.fit(X_train_cat, y_train, pos_class='won')
    preds_irep = irep.predict(X_test_cat)

    # Mapear os retornos (True/False) de volta para o texto original ('won'/'nowin')
    preds_irep_mapped = ['won' if p else 'nowin' for p in preds_irep]
    scores_irep.append(accuracy_score(y_test, preds_irep_mapped))

# 4. Análise Estatística (Teste T P)
t_stat, p_val = ttest_rel(scores_nb, scores_irep)

# 5. Parte Estatística
summary = pd.DataFrame({
    'Métrica': ['Acurácia Média', 'Desvio Padrão'],
    'Naive Bayes': [np.mean(scores_nb), np.std(scores_nb)],
    'IREP (RIPPER)': [np.mean(scores_irep), np.std(scores_irep)]
})

print("\n=== Resumo ===")
print(summary)

print(f"\npvalor teste T: {p_val:.4e}")
if p_val < 0.05:
    print("A diferença é estatisticamente significativa.")
else:
    print("A diferença NÃO É estatisticamente significativa.")

# 6. Geração do Gráfico
plt.figure(figsize=(8, 6))
sns.boxplot(data=[scores_nb, scores_irep], palette="Set2")
plt.xticks([0, 1], ['Naive Bayes', 'IREP (RIPPER)'], fontsize=12)
plt.ylabel('Acurácia', fontsize=12)
plt.title('Comparação de Desempenho Base: Chess (King-Rook vs. King-Pawn)', fontsize=13)
plt.grid(axis='y', linestyle='--', alpha=0.7)