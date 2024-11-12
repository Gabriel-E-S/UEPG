// bibliotecas

#include <locale.h>
#include <stdbool.h>
#include <stdio.h>

#define N 10 // Tamanho máximo do grafo

int vetorVertices[N], matrizAdj[N][N],
    tamanhoAtual = 0; // Variáveis globais
                      // Um contador de elementos, um vetor contendo os vértices
                      // e uma matriz de adjascência desses vértices.

// Procedimento que inicializa a matriz de adjascência e o vetor de vértices.

void inicializarMatrizAdj() {

  int i, j;

  for (i = 0; i < N; i++) {
    vetorVertices[i] = -1;
    for (j = 0; j < N; j++) {
      matrizAdj[i][j] = 0;
    }
  }
}

// Função que consulta se um vértice está no vetor de vértices.

int verificarExistencia(int valor) {
  int i;

  for (i = 0; i < N; i++) {
    if (vetorVertices[i] == valor) { // Busca sequencial simples retornando o
                                     // índice do elemento quando encontrado.
      return i;
    }
  }
  return -1; // Quando o elemento não existe retorna -1, pois -1 não pode ser
             // nenhum índice.
}

// Procedimento que insere um vértice no grafo

void insereVertice(int valor) {

  if (tamanhoAtual < N &&
      verificarExistencia(valor) ==
          -1) { // Se ainda houver espaço no vetor e valor não existir nele o
    vetorVertices[tamanhoAtual] =
        valor; // elemento é inserido e o tamanho atualizado.
    tamanhoAtual += 1;

    printf("VÉRTICE %d ADICIONADO\n", valor);

  } else {

    printf("NÃO FOI POSSÍVEL INSERIR O VALOR\n");
  }
}

// Procedimento que insere um vértice dando uma origem e um destino

void insereAresta(int origem, int destino) {

  int valor1 =
      verificarExistencia(origem); // Verificamos se os vértices existem.
  int valor2 = verificarExistencia(destino);

  if (valor1 != -1 &&
      valor2 != -1) { // Se ambos existirem criamos a aresta na matriz.

    matrizAdj[valor1][valor2] = 1;
    matrizAdj[valor2][valor1] = 1; // Fazendo um grafo não orientado.

    printf("ARESTA INSERIDA COM SUCESSO!\n");
  } else {
    if (valor1 == -1) {

      printf(
          "O VÉRTICE DE ORIGEM NÃO EXISTE\n"); // Caso contrário mostra-se a
                                               // mensagem de erro e o motivo.
    }
    if (valor2 == -1) {

      printf("O VÉRTICE DE DESTINO NÃO EXISTE\n");
    }
  }
}

// Procedimento que remove uma aresta dada uma origem e um destino

void removeAresta(int origem, int destino) {

  int valor1 =
      verificarExistencia(origem); // Verificamos se os vértices existem.
  int valor2 = verificarExistencia(destino);

  if (valor1 != -1 &&
      valor2 != -1) { // Se ambos existirem criamos a aresta na matriz.
    matrizAdj[valor1][valor2] = 0;

    printf("ARESTA REMOVIDA COM SUCESSO!");
  } else {
    if (valor1 == -1) {

      printf("O VÉRTICE DE ORIGEM NÃO EXISTE"); // Caso contrário mostra-se a
                                                // mensagem de erro e o motivo.
    }
    if (valor2 == -1) {

      printf("O VÉRTICE DE DESTINO NÃO EXISTE");
    }
  }
}

// Procedimento que verifica se uma aresta existe no grafo.

void haAresta(int origem, int destino) {

  int valor1 = verificarExistencia(origem); // Mesmo procedimento anterior
  int valor2 = verificarExistencia(destino);

  if (valor1 != -1 && valor2 != -1) {
    if (matrizAdj[valor1][valor2] == 1) {

      printf("A ARESTA ENTRE %d e %d EXISTE", origem, destino);
    } else {

      printf("A ARESTA ENTRE %d e %d NÃO EXISTE", origem, destino);
    }
  } else {
    if (valor1 == -1) {

      printf("O VÉRTICE DE ORIGEM NÃO EXISTE");
    }
    if (valor2 == -1) {

      printf("O VÉRTICE DE DESTINO NÃO EXISTE");
    }
  }
}

// Procedimento que imprime uma matriz

void imprimeMatrizAd() {

  int i, j;

  printf("\n\nMATRIZ DE ADJASCÊNCIA\n\n");

  for (i = 0; i < tamanhoAtual; i++) {

    for (j = 0; j < tamanhoAtual; j++) {

      printf("%d ", matrizAdj[i][j]);
    }
    printf("\n");
  }
}

// Procedimento que imprime todas as arestas que estão saindo de um vértice.

void imprimeArestas(int linha) {

  int i;

  int coluna = 36;

  for (i = 0; i < N; i++) {
    if (matrizAdj[linha][i] != 0) {

      printf("<%d,%d> ", vetorVertices[linha], vetorVertices[i]);
      coluna += 7;
    }
  }
}

// Procedimento que imprime o grafo usando o procedimento anterior.

void imprimeGrafo() {

  int i;

  if (tamanhoAtual > 0) {

    imprimeMatrizAd(); // Imprimimos a matriz.

    printf("\n\nGRAFO ATUAL\n\n"); // E em seguida o gráfico.

    for (i = 0; i < tamanhoAtual; i++) {

      printf("%d -> ", vetorVertices[i]);
      imprimeArestas(i);
      printf("\n");
    }
  }
  printf("\n\n\n\n");
}

void dfs(int u, int *visitados) {
  visitados[u] = 1; // Marca o nó como visitado
  printf("Visitando o nó: %d\n", vetorVertices[u]);

  for (int j = 0; j < tamanhoAtual; j++) {
    if (matrizAdj[u][j] == 1 && visitados[j] == 0) {
      dfs(j, visitados);
    }
  }
}

// Inicializamos um vetor de quais já foram visitados com 0 e depois executamos
// o algoritmo do percurso.

void caminhoEmProfundidade() {

  printf("\n*****Caminho em profundidade*****\n");
  int visitados[tamanhoAtual];

  for (int i = 0; i < tamanhoAtual; i++) {
    visitados[i] = 0;
  }

  for (int i = 0; i < tamanhoAtual; i++) {
    if (visitados[i] == 0) {
      dfs(i, visitados);
    }
  }
}

// Procedimento main.

int main() {

  setlocale(LC_ALL, "Portuguese");

  inicializarMatrizAdj();

  insereVertice(0);
  insereVertice(1);
  insereVertice(2);
  insereVertice(3);
  insereVertice(4);
  insereVertice(5);

  insereAresta(1, 2);
  insereAresta(1, 3);
  insereAresta(1, 4);
  insereAresta(1, 5);

  insereAresta(2, 1);
  insereAresta(2, 3);

  insereAresta(3, 1);
  insereAresta(3, 2);
  insereAresta(3, 4);

  insereAresta(4, 1);
  insereAresta(4, 3);
  insereAresta(4, 5);

  insereAresta(5, 1);
  insereAresta(5, 4);

  imprimeGrafo();

  caminhoEmProfundidade();
  return 0;
}
