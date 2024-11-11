# Grafos

# Definição

- Conjunto de objetos (vértices) junto com uma coleção de
conexões entre pares de vértices.

- Grafo G(V, E): conjunto V de `vértices` e uma coleção E de pares
de vértices, chamados de `arestas`.

### Tipos de arestas

- **Dirigidas:** A aresta (u, v) é dita dirigida de u para v se o par (u, v) for
ordenado, com u precedendo v, ou seja, quando temos a indicação de sentido de onde a aresta sai e onde ela entra.

- **Não dirigida:** a aresta (u, v) é dita não-dirigida se o par (u, v) não for
ordenado; neste caso, (u, v) é o mesmo que (v, u), ou seja, quando a só temos a ligação nos ambos sentidos.


### Tipos de grafos

- Orientado: Grafos com arestas dirigidas.
- Não orientado: Grafos com arestas não dirigidas;

![Grafos 1](./Imagens/Grafos 1.png) 

### Termologia

- **Vértices adjacentes**: há uma aresta entre eles.

- **Aresta incidente**: se o vértice for um dos pontos finais da
aresta.

- **Grau de um vértice**: número de arestas incidentes que saem ou entram nesse nó.
  + Grau de entrada: quantidade de arestas que entram no vértice.
  + Grau de saída: quantidade de arestas que saem do vértice.

***OBS:*** Vértices que não possuem arestas tem grau `0`.












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
