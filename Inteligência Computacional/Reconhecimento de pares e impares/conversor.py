import pandas as pd
import numpy as np

# 1. Carregar o arquivo local '.data'
# O sep='\s+' diz ao Pandas que os dados são separados por espaços
print("Carregando o arquivo semeion.data...")
df = pd.read_csv('semeion.data', sep='\s+', header=None)

# O dataset original tem 256 colunas de pixels e 10 colunas para as classes (0 a 9).
# O Pandas pode criar uma coluna extra vazia no final devido aos espaços, então pegamos os índices exatos:

# 2. Separar as features (pixels) das labels (classes)
X = df.iloc[:, 0:256]        # Colunas de 0 a 255 (os 256 pixels)
y_onehot = df.iloc[:, 256:266] # Colunas de 256 a 265 (o vetor com 10 posições)

# 3. Descobrir qual é o dígito original (0 a 9)
# O argmax encontra a posição do número '1' no vetor, que corresponde exatamente ao dígito.
digitos = np.argmax(y_onehot.values, axis=1)

# 4. Criar a nova classificação: Par ou Ímpar
# Usamos o resto da divisão por 2 (%).
# Se for par, o resultado é 0. Se for ímpar, o resultado é 1.
# Portanto: 0 = Par, 1 = Ímpar
y_par_impar = digitos % 2

# 5. Juntar os pixels com a nova classificação
novo_df = X.copy()
novo_df['label'] = y_par_impar # Adiciona a nova coluna no final

# 6. Salvar o novo arquivo para usar no AIMA
# Vamos salvar como um arquivo CSV (separado por vírgulas) que o código do AIMA lê facilmente
nome_novo_arquivo = 'semeion_par_impar.csv'
novo_df.to_csv(nome_novo_arquivo, index=False, header=False)

print(f"Sucesso! O novo dataset foi salvo como: {nome_novo_arquivo}")
print(f"O novo arquivo possui {novo_df.shape[1]} colunas (256 de pixels + 1 de label Par/Ímpar).")
