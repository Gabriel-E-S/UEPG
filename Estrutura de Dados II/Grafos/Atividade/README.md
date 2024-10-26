# Grafos e Matriz de Adjacências

## Exercícios

Implemente um grafo direcionado usando matriz de adjacências. Os vértices devem ser inseridos em um vetor.

### Funções a serem implementadas

- **void insereVértice(int valor)**: 
  - Insere um vértice em um grafo.
  - Deve verificar se há espaço no vetor e não pode inserir vértices repetidos.

- **void insereAresta(int origem, int destino)**: 
  - Insere uma aresta entre dois vértices.
  - Deve verificar inicialmente se os vértices existem.

- **void removeAresta(int origem, int destino)**: 
  - Remove uma aresta entre dois vértices.
  - Deve verificar inicialmente se os vértices existem e se a aresta existe.

- **void haAresta(int origem, int destino)**: 
  - Imprime se existe uma aresta entre dois vértices.
  - Deve verificar inicialmente se os vértices existem.

- **void imprimeGrafo()**: 
  - Imprime o grafo da seguinte forma:
  
    ```
    0 -> <0,1> <0,2>
    1 -> <1,0>
    2 -> 
    ```

  - O grafo representado acima tem três vértices (0, 1 e 2) e três arestas: `<0,1>`, `<0,2>` e `<1,0>`.

### Função Principal

Desenvolva uma função principal na qual todas essas funções sejam testadas.
