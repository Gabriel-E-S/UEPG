// bibliotecas
//
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10 // contant

// struct for the list

typedef struct node {
  int key;
  struct node *next;
} node;

// struct for the header

typedef struct vertex {
  int key;
  node *edgeList;
} vertex;

// global variables

int actualSize = 0;
vertex VertexVector[N];

void insereLista(node **inicio, int vertice) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->key = vertice;
  newNode->next = NULL;

  if (*inicio == NULL) {
    *inicio = newNode;
  } else {
    node *temp = *inicio;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int removeLista(node **inicio) {
  if (*inicio == NULL) {
    return -1; // Retorna -1 se a fila estiver vazia
  }
  node *temp = *inicio;
  int vertice = temp->key;
  *inicio = (*inicio)->next;
  free(temp);
  return vertice;
}

// procedure that initializes the vector of vertexes

void initVector() {
  for (int i = 0; i < N; i++) {
    VertexVector[i].edgeList = NULL;
  }
}

// procedure that searches for a vertex

int searchForVertex(int key) {

  for (int i = 0; i < actualSize; i++) {
    if (VertexVector[i].key == key) {
      return i;
    }
  }
  return -1;
}

// procedure that searches for a vertex

int searchForEdge(node *start, int key) {
  node *aux = start;

  while (aux != NULL) {
    if (aux->key == key) {
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}

// procedure that insert a vertex

void insertVertex(int key) {

  if (actualSize >= N) {
    printf("I can't insert more elements, because the vector is full!\n");
    return;
  }
  if (searchForVertex(key) != -1) {
    printf("A vertex with this value (%d) already exists\n", key);
    return;
  }

  node *aux = (node *)malloc(sizeof(node));

  if (aux) {

    VertexVector[actualSize].key = key;
    actualSize += 1;

    printf("Vertex %d insertion complete!\n", key);
  } else {
    printf("Memory aloccation error\n");
  }
}

// procedure that insert a edge

void insertEdge(int origin, int destination) {
  int b1 = searchForVertex(origin);
  int b2 = searchForVertex(destination);

  if (b1 != -1 && b2 != -1) {
    if (searchForEdge(VertexVector[b1].edgeList, destination) == 0) {

      node *aux = (node *)malloc(sizeof(node));

      aux->key = destination;

      aux->next = VertexVector[b1].edgeList;

      VertexVector[b1].edgeList = aux;
      printf("Edge <%d,%d> insertion complete!\n", origin, destination);
    } else {
      printf(
          "A edge with this origin and destination  <%d,%d> already exists\n",
          origin, destination);
    }
  }
}

// procedure that removes a edge

void removeEdge(int origin, int destination) { // this function removes edges

  int b1 = searchForVertex(origin); // verifies if the Vertexes exists
  int b2 = searchForVertex(destination);

  if (b1 != -1 && b2 != -1) {
    if (searchForEdge(VertexVector[b1].edgeList, destination) != 0) {

      node *aux = VertexVector[b1].edgeList; // auxiliar pointers
      node *previous = NULL;

      while (aux != NULL &&
             aux->key != destination) { // searching for the correct node
        previous = aux;
        aux = aux->next;
      }

      if (aux == NULL) { // edge nodet found
        printf("Edge <%d,%d>  nodet found", origin, destination);
      }

      if (previous == NULL) { // first element
        VertexVector[b1].edgeList = aux->next;
      } else { // other cases
        previous->next = aux->next;
      }

      free(aux); // free the memory

      printf("Edge <%d,%d> remotion complete!\n", origin, destination);
    } else {
      printf("A edge with this origin and destination  <%d,%d> does nodet "
             "exists.\n",
             origin, destination);
    }
  }
}

// procedure that verifies if a vertex has a edge

void hasEdge(int origin, int destination) {

  int b1 = searchForVertex(origin); // verifies if the Vertexes exists
  int b2 = searchForVertex(destination);

  if (b1 != -1 && b2 != -1) {

    node *aux = VertexVector[b1].edgeList; // auxiliar pointers

    while (aux != NULL &&
           aux->key != destination) { // searching for the correct node
      aux = aux->next;
    }

    if (aux == NULL) { // edge nodet found
      printf("Edge <%d,%d> nodet found\n", origin, destination);
      return;
    }
    printf("Edge <%d,%d> found!\n", origin, destination);
  } else {
    printf("One of the vertixes does nodet exists\n");
  }
}

// procedure that print a edge

void printGraph() {

  printf("\n\n*****Actual Graph*****\n\n");

  for (int i = 0; i < actualSize; i++) {

    printf("Vertex %d:", VertexVector[i].key);

    node *aux = VertexVector[i].edgeList;

    while (aux != NULL) {
      printf("<%d,%d> ", VertexVector[i].key, aux->key);
      aux = aux->next;
    }
    printf("\n");
  }
}

void bfs(int u, int *visited) {

  node *begin = NULL; // Ponteiro para a fila.

  visited[u] = 1; // Marca o nó como visitado.
  printf("Visitando o nó: %d\n", VertexVector[u].key);

  insereLista(&begin, u);

  while (1) {
    int removed = removeLista(&begin);

    if (removed == -1) {
      break;
    }

    node *aux = VertexVector[removed].edgeList;

    while (aux != NULL) {

      int adj = aux->key;

      if (visited[adj] == 0) {
        visited[adj] = 1;
        printf("Visitando o nó: %d\n", VertexVector[adj].key);
        insereLista(&begin, adj);
      }

      aux = aux->next;
    }
  }
}
// Inicializamos um vetor de quais já foram visitados com 0 e depois executamos
// o algoritmo do percurso.

void caminhoEmLargura() {

  printf("\n*****Caminho em largura*****\n");
  int visitados[actualSize];

  for (int i = 0; i < actualSize; i++) {
    visitados[i] = 0;
  }

  for (int i = 0; i < actualSize; i++) {
    if (visitados[i] == 0) {
      bfs(i, visitados);
    }
  }
}

int main() {

  initVector();

  // Inserting the data from the slides.

  insertVertex(0);
  insertVertex(1);
  insertVertex(2);
  insertVertex(3);
  insertVertex(4);
  insertVertex(5);

  insertEdge(1, 2);
  insertEdge(1, 3);
  insertEdge(1, 4);
  insertEdge(1, 5);

  insertEdge(2, 1);
  insertEdge(2, 3);

  insertEdge(3, 1);
  insertEdge(3, 2);
  insertEdge(3, 4);

  insertEdge(4, 1);
  insertEdge(4, 3);
  insertEdge(4, 5);

  insertEdge(5, 1);
  insertEdge(5, 4);

  printGraph();

  caminhoEmLargura();
  return 0;
}
