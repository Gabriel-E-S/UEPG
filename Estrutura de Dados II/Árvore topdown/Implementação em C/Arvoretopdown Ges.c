
// �rvore top down Gabriel E.S

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define ORDEM 200              // N�mero m�ximo de filhos
#define MAX_CHAVES (ORDEM - 1) // N�mero m�ximo de chaves

struct no {
  int dado[MAX_CHAVES];
  struct no *filhos[ORDEM];
  struct no *pai;
  int n_chaves;
};

// Ponteiro para a raiz da �rvore
struct no *raiz = NULL;

// Fun��o para criar um novo n�
struct no *cria_no(int chave) {
  struct no *novo = (struct no *)malloc(sizeof(struct no));
  novo->dado[0] = chave;
  novo->n_chaves = 1;
  for (int i = 0; i < ORDEM; i++) {
    novo->filhos[i] = NULL;
  }
  novo->pai = NULL;
  return novo;
}

// Encontra uma chave no n� apontado por atual e retorna a posi��o dela no n�
int encontra_chave(struct no *atual, int chave) {
  int i = 0;
  while (i < atual->n_chaves && chave > atual->dado[i])
    i++;
  return i;
}

// Encontra o n� folha onde uma chave deve ser inserida e retorna um ponteiro
// para ele
struct no *encontra_no(int chave, int *posicao) {
  struct no *atual = raiz;
  struct no *anterior = NULL;

  while (atual != NULL) {
    *posicao = encontra_chave(atual, chave);
    anterior = atual;
    atual = atual->filhos[*posicao];
  }
  return anterior;
}

// Insere uma nova chave em um n� folha que possui espa�o
void insere_folha(struct no *atual, int chave) {
  int i;
  for (i = atual->n_chaves; i > 0 && chave < atual->dado[i - 1]; i--)
    atual->dado[i] = atual->dado[i - 1];
  atual->dado[i] = chave;
  atual->n_chaves++;
}

// Insere uma nova chave em uma �rvore m�ltipla top-down
int insere(int chave) {
  struct no *novo, *atual;
  int posicao;

  if (raiz == NULL) {
    raiz = cria_no(chave);
    return 1;
  }

  // Encontra n� folha onde a nova chave ser� inserida
  atual = encontra_no(chave, &posicao);

  // Existe espa�o no n� folha, insere nova chave
  if (atual->n_chaves < MAX_CHAVES) {
    insere_folha(atual, chave);
    return 1;
  }

  // N�o existe espa�o no n� folha, cria novo n� (mas essa parte deve ser
  // completada)
  novo = cria_no(chave);
  atual->filhos[posicao] = novo;
  return 1;
}

int conta(struct no *atual) {
  int i, total;

  if (atual != NULL) {
    total = 1;
    for (i = 0; i < atual->n_chaves + 1; i++) {
      total = total + conta(atual->filhos[i]);
    }
    return total;
  }
  return 0;
}

void busca(int chave) {

  struct no *aux = raiz;
  int i;

  while (aux != NULL) {
    i = encontra_chave(aux, chave);
    if (i < aux->n_chaves && aux->dado[i] == chave) {
      printf("encontrei o numero %d\n", chave);
      return;
    }
    aux = aux->filhos[i];
  }
  printf("n achei %d\n", chave);
}

void emordem(struct no *atual) {

  int i;

  if (raiz == NULL) {
    printf("�RVORE VAZIA!\n");
    return;
  }

  if (atual != NULL) {
    i = 0;
    int nc = atual->n_chaves;
    while (i < nc) {
      emordem(atual->filhos[i]);
      printf("%d ", atual->dado[i]);
      i++;
    }
    emordem(atual->filhos[nc]);
  }
}

int main() {

  setlocale(LC_ALL, "Portuguese");
  int i;

  printf("***************�RVORES M�LTIPLAS***************\n\n");

  for (i = 1; i <= 5000; i++) {
    insere(i);
  }

  printf("\n\n�RVORE EM ORDEM\n\n");
  emordem(raiz);

  printf("\n\nN�MERO DE N�S = %d\n\n", conta(raiz));

  busca(4000);
  busca(10000);

  return 0;
}
