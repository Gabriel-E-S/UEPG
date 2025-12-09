# Revisão para a prova 2

## Equações de recorrência

Equações de recorrência são relações que definem uma sequência de valores com base em termos anteriores, frequentemente usadas para analisar o tempo de execução de algoritmos recursivos. Por exemplo, a equação T(n) = T(n-1) + O(1) descreve um algoritmo que executa uma operação constante após chamar-se recursivamente.

Para resolver essas equações, métodos comuns incluem a substituição, a árvore de recursão e o método mestre. O método mestre, por exemplo, permite uma análise mais direta, especialmente para recursões da forma T(n) = aT(n/b) + f(n).

## Método iterativo

Vamos entender como os métodos funcionam na prática:

Tendo em vista a seguinte equação de recorrência

```
    T(n) = T(n/2) + 1
    T(1) = 1
```
Nesse método fazemos as substituições da fórmula tentando achar um padrão que se repita em `k` iterações.

assim temos

$T(n) = T(n/2) + 1$

$T(n) = T(T(n/4)+ 1) + 1$

$T(n) = T(T(T(n/8)+ 1)+ 1) + 1$

Depois disso podemos montar o padrão encontrado, nesse caso

$T(n) = T(n/2^k)+k$

Temos que achar um número `k` de iterações que faça nós chegarmos ao caso base da recursão $T(1) = 1$ .

$n/2^k = 1$

$n = 2^k $

$k = log2(n)$

Agora voltamos na expressão generalizada substituindo `k` pelo resultado encontrado.

$T(n) = 1 + log2(n)$

Com isso achamos o resultado final:

$T(n) = Θ(log(n)) $ .

## Método mestre

O método mestre é uma técnica poderosa para resolver equações de recorrência que frequentemente aparecem na análise de algoritmos, especialmente aqueles que seguem um padrão de divisão e conquista. O método é aplicado a recorrências da forma:

$ T(n) = a*T(n/b) +f(n) $

onde:

+ 𝑎≥1 é o número de subproblemas,

+ b>1 é o fator de redução do tamanho do problema,

+ f(n) é uma função que representa o custo de dividir e combinar os subproblemas.


### Casos do Método Mestre

O método mestre possui três casos principais:

#### Caso 1

Se $ f(n) $ é assintoticamente menor que $ n^{\log_b a} $:
- **Formalmente**: $ f(n) = O(n^{\log_b a - \epsilon}) $ para alguma constante $ \epsilon > 0 $.
- **Resultado**: $ T(n) = \Theta(n^{\log_b a}) $.

#### Caso 2

Se $ f(n) $ é assintoticamente igual a $ n^{\log_b a} $:
- **Formalmente**: $ f(n) = \Theta(n^{\log_b a}) $.
- **Resultado**: $ T(n) = \Theta(n^{\log_b a} \log n) $.

#### Caso 3

Se $ f(n) $ é assintoticamente maior que $ n^{\log_b a} $ e satisfaz a condição de regularidade:
- **Formalmente**: $ f(n) = \Omega(n^{\log_b a + \epsilon}) $ para alguma constante $ \epsilon > 0 $ e $ a f\left(\frac{n}{b}\right) \leq c f(n) $ para algum $ c < 1 $ e para valores suficientemente grandes de $ n $.
- **Resultado**: $ T(n) = \Theta(f(n)) $.

Tomando como exemplo o a mesma equação anterior:

```
    T(n) = T(n/2) + 1
    T(1) = 1
```

a = 1

b = 2

f(n) = 1

$n^{logb(a)} = n^{log2(1)} = n^0 = 1$

Caso 2 f(n) = $\Theta(1)$

logo a solução da equação é

$T(n) = Θ(1 * log(n)) $ .



$T(n) = Θ(log(n)) $ .

