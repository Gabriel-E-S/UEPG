# Comparação de Algoritmos: Categorical Naive Bayes vs IREP

Este projeto realiza uma avaliação de desempenho e comparação estatística entre os algoritmos **Categorical Naive Bayes** e **IREP** (Incremental Reduced Error Pruning) utilizando a base de dados clássica de Xadrez (King-Rook vs. King-Pawn) do repositório UCI Machine Learning.

## 📋 Descrição do Projeto

O script em Python foi desenhado para lidar com atributos puramente categóricos. Ele executa as seguintes etapas:
1. **Carregamento dos Dados:** Obtém a base diretamente do `ucimlrepo`.
2. **Pré-processamento:** Prepara os dados especificamente para cada algoritmo (Ordinal Encoding para o Naive Bayes e dados textuais originais para o IREP).
3. **Validação Cruzada:** Aplica o método *Repeated Stratified 10-Fold Cross-Validation* (3 repetições, totalizando 30 partições) garantindo uma avaliação robusta.
4. **Análise Estatística:** Utiliza o Teste T Pareado (*Paired T-Test*) para verificar se a diferença de acurácia entre os modelos é estatisticamente significativa (p-value < 0.05).
5. **Visualização:** Gera tabelas descritivas no console e plota um *Boxplot* (com *Swarmplot*) ilustrando a distribuição das acurácias.

## 🛠️ Pré-requisitos

Para rodar este código, você precisará do Python instalado em sua máquina e das seguintes bibliotecas de análise de dados e *Machine Learning*:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn scipy wittgenstein ucimlrepo
```

## Como Executar

Salve o código principal em um arquivo Python, por exemplo: comparacao_chess.py.

Abra o seu terminal (ou prompt de comando) e navegue até a pasta onde o arquivo está salvo.

Execute o script:

```Bash
python3 comparacao_chess.py
```

Se você estiver usando o Jupyter Notebook ou Google Colab, basta colar o código em uma célula e executar.

## O que esperar na saída (Outputs)

Ao rodar o script, você verá as seguintes saídas no seu console:

O progresso da validação cruzada.

Resultados Estatísticos: A estatística T e o Valor-p, seguidos da conclusão se há ou não diferença significativa entre os algoritmos.

Tabela Descritiva: Uma tabela detalhada mostrando contagem, média, desvio padrão, mínimos e máximos da acurácia de cada modelo.

Além disso, uma janela será aberta exibindo um Gráfico de Boxplot, permitindo a comparação visual da dispersão e consistência das predições de ambos os algoritmos nas 30 rodadas de teste.