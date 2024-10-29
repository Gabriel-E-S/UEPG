# Busca/percurso em largura em grafos

## Percurso em largura

Na busca em largura, utilizaremo uma `fila` (podendo ser uma fila de prioridades).

### Passo a passo

1. Escolher um vértice qualquer para iniciar.

2. Marcar esse vértice como visistado.

3. Visitar todos os vértices adjscentes ao vértice visitado.

    1. Marque vértices como visitados e insira->osem uma fila, na ordem que foram visitados.

4. Retire um vértice da fila

5. Se a fila estiver vazia, termine, senão volte ao passo 3.

<!-- 





Exemplo:

0   

`1`   ->   **6**   ->   **2**

2   ->   5   ->   3   ->   1   ->   6

3   ->   6   ->   5   ->   4   ->   2

4   ->   5   ->   3

5   ->   6   ->   4   ->   3   ->   2

6   ->   5   ->   3   ->   2   ->   1


Fila atual: 1->6->2

***
***

Próximo passo:

0   

`1`   ->   **6**   ->   **2**

2   ->   5   ->   3   ->   1   ->   6

3   ->   6   ->   5   ->   4   ->   2

4   ->   5   ->   3

5   ->   6   ->   4   ->   3   ->   2

6   ->   5   ->   3   ->   2   ->   1


Fila atual: 1->6->2

***
***

-->