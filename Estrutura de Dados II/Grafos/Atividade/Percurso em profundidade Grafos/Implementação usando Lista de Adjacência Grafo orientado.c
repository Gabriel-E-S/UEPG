/////////////////////////////////////
//  Code made by: Gabriel E.Santo  //
/////////////////////////////////////

#include <stdio.h>
#include <stdlib.h> // libraries

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

      if (aux == NULL) { // edge not found
        printf("Edge <%d,%d>  not found", origin, destination);
      }

      if (previous == NULL) { // first element
        VertexVector[b1].edgeList = aux->next;
      } else { // other cases
        previous->next = aux->next;
      }

      free(aux); // free the memory

      printf("Edge <%d,%d> remotion complete!\n", origin, destination);
    } else {
      printf(
          "A edge with this origin and destination  <%d,%d> does not exists.\n",
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

    if (aux == NULL) { // edge not found
      printf("Edge <%d,%d> not found\n", origin, destination);
      return;
    }
    printf("Edge <%d,%d> found!\n", origin, destination);
  } else {
    printf("One of the vertixes does not exists\n");
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

void dfs(int u, int *visitVector) { // depth-first search

  visitVector[u] = 1; // Changes this vertex to visited
  printf("%d\t",
         VertexVector[u].key); // shows in the screen the value from the vertex

  node *aux =
      VertexVector[u]
          .edgeList; // auxiliar node to go to through the adjacency list

  while (aux != NULL) {
    int w = aux->key; // Recursive part

    if (visitVector[w] == 0) {
      dfs(w, visitVector);
    }
    aux = aux->next;
  }
}

void course() {

  int visitVector[actualSize]; // Creating the visit Vector

  for (int i = 0; i < actualSize; i++) { // initializes the auxiliar vector with
                                         // 0, that means an unvisited vertex.
    visitVector[i] = 0;
  }
  for (int i = 0; i < actualSize; i++) {
    if (visitVector[i] == 0) {
      dfs(i, visitVector);
    }
  }
}

void inDepthCourse() {

  printf("\n\n*****Atual Graph in depth*****\n\n");

  course();

  printf("\n\n------------------------------------------>\n\n");
}
int main() {

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

  inDepthCourse();

  return 0;
}
