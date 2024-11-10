#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  int cor;
  struct no *esq;
  struct no *dir;
} no;

struct no *raizRN = NULL; // Raiz da árvore rubro-negra

void clear() {
  printf("\033[2J\033[1;1H"); // limpa a tela
}

void pause() {
#ifdef _WIN32
  system("pause"); // Para Windows
#else
  printf("Pressione Enter para continuar...");
  getchar(); // Para Linux e sistemas Unix
#endif
}

void esquerda(no *raiz, no *atual) {
  no *q = atual->dir;
  if (q != NULL) {
    atual->dir = q->esq;
    q->esq = atual;
    if (atual == raiz) {
      raiz = q;
    }
  }
}

void direita(no *raiz, no *atual) {
  no *q = atual->esq;
  if (q != NULL) {
    atual->esq = q->dir;
    q->dir = atual;
    if (atual == raiz) {
      raiz = q;
    }
  }
}

void ajustaRN(struct no *novo) {
  struct no *p = raizRN, *pp = NULL, *ap = NULL, *bp = NULL, *tp;
  // Percorre Árvore binária com quatro ponteiros:
  // p: nó atual
  // pp (pai do nó apontado por p)
  // ap (avô do nó apontado por p)
  // bp (bisavô do nó apontado por p)
  while (p != novo) {
    if (ap != NULL)
      bp = ap;
    if (pp != NULL)
      ap = pp;
    pp = p;
    if (novo->dado < p->dado)
      p = p->esq;
    else
      p = p->dir;
  }
  if (p == raizRN) {
    raizRN->cor = 'n';
    return; /* Inserção na raiz */
  }
  if (pp->cor == 'n')
    return;          /* Não houve desbalanceamento, pois pai e preto */
  if (pp == ap->esq) /* Descobre tio do nó apontado por p */
    tp = ap->dir;
  else
    tp = ap->esq;
  // Se tio for vermelho, troca cor do pai, do tio e do avô
  if (tp != NULL && tp->cor == 'v') {
    tp->cor = 'n';
    pp->cor = 'n';
    ap->cor = 'v';
    ajustaRN(ap);
    // A mudanca de cor do avô pode gerar um problema, então ajusta novamente
    // a Arvore usando o avô como referencia
  } else // Caso onde o tio e preto e rotacoes são necessárias
  {
    if (p == pp->dir && pp == ap->esq) // Filho direito e pai esquerdo
    {
      esquerda(raizRN, pp);
      ap->esq = p;
      pp = p;
      p = p->esq;
    } else if (p == pp->esq && pp == ap->dir) // Filho esquerdo e pai direito
    {
      direita(raizRN, pp);
      ap->dir = p;
      pp = p;
      p = p->dir;
    }
    pp->cor = 'n';
    ap->cor = 'v';
    // Filho e pai são ambos esquerdos
    if (p == pp->esq && pp == ap->esq)
      direita(raizRN, ap);
    else // Filho e pai são ambos direitos
      esquerda(raizRN, ap);

    // Ajusta o ponteiro do bisavô do nó apontado por p
    if (bp != NULL)
      if (ap == bp->esq)
        bp->esq = pp;
      else
        bp->dir = pp;
    else
      raizRN = pp;
  }
}

void preOrdem(no *atual) {

  if (atual != NULL) {

    printf("%d%c ", atual->dado, atual->cor);

    preOrdem(atual->esq);
    preOrdem(atual->dir);
  }
}

void emOrdem(no *atual) {

  if (atual != NULL) {

    emOrdem(atual->esq);

    printf("%d%c ", atual->dado, atual->cor);

    emOrdem(atual->dir);
  }
}

void posOrdem(no *atual) {

  if (atual != NULL) {

    posOrdem(atual->esq);

    posOrdem(atual->dir);
    printf("%d ", atual->dado);
  }
}

void insere(int dado) {

  no *aux = (no *)malloc(sizeof(no)); // alocando espaço para o nó
  if (aux == NULL) {
    printf("erro ao alocar memoria\n");
    return;
  }

  aux->dado = dado;
  aux->esq = NULL;
  aux->dir = NULL;
  aux->cor = 'v';

  if (raizRN == NULL) {
    raizRN = aux;
    aux->cor = 'n';
    return;
  }

  no *p1 = raizRN, *p2 = NULL;

  while (p1 != NULL) {
    p2 = p1;
    if (dado < p1->dado) {
      p1 = p1->esq;
    } else {
      p1 = p1->dir;
    }
  }

  if (dado < p2->dado) {
    p2->esq = aux;
  } else {
    p2->dir = aux;
  }

  ajustaRN(aux);
}

// função de menu

void menuImprimir(no *raizRN) {

  int opc = -1;

  if (raizRN == NULL) {
    printf("ÁRVORE VAZIA!");
    return;
  }

  while (opc != 4) {

    // system("clear");

    printf("1-PRE ORDEM\n");
    printf("2-EM ORDEM\n");
    printf("3-POS ORDEM\n");
    printf("4- SAIR\n");
    printf("ESCOLHA --> ");
    scanf("%d", &opc);

    while (getchar() != '\n')
      ;

    switch (opc) {

    case 1: {
      printf("\npre ordem\n");
      preOrdem(raizRN);
      break;
    }

    case 2: {
      printf("\nem ordem\n");
      emOrdem(raizRN);
      break;
    }

    case 3: {
      printf("\npos ordem\n");
      posOrdem(raizRN);
      break;
    }
    case 4: {
      return;
    }
    default: {
      printf("\n\nOPC INVÁLIDA!\n\n");
      break;
    }
    }

    printf("\n\n");
    system("pause");
  }
}

void buscaRN(no *atual, int valor, int *resposta) {

  if (atual != NULL) {

    if (atual->dado == valor) {
      *resposta = 1;
    } else {
      if (atual->dado > valor) {
        buscaRN(atual->esq, valor, resposta);
      } else {
        buscaRN(atual->dir, valor, resposta);
      }
    }
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  int opc = -1;

  while (opc != 4) {
    clear();

    printf("1- INSERIR\n");
    printf("2- BUSCAR\n");
    printf("3- IMPRIMIR\n");
    printf("4- SAIR\n");
    printf("ESCOLHA --> ");

    scanf("%d", &opc);
    while (getchar() != '\n')
      ;

    switch (opc) {

    case 1: {
      int valor;

      printf("\nDIGITE O VALOR --> ");
      scanf("%d", &valor);
      while (getchar() != '\n')
        ;

      insere(valor);
      break;
    }
    case 2: {

      int valor, res = 0;

      if (raizRN == NULL) {
        printf("ÁRVORE VAZIA!");
        break;
      }

      printf("\nDIGITE O VALOR --> ");
      scanf("%d", &valor);
      while (getchar() != '\n')
        ;

      buscaRN(raizRN, valor, &res);

      if (res) {
        printf("\nENCONTREI O NÚMERO\n");
      } else {
        printf("\nNÃO ENCONTREI O NÚMERO\n");
      }

      break;
    }
    case 3: {
      menuImprimir(raizRN);
      break;
    }
    case 4: {
      printf("\nVOCÊ SAIU!");
      break;
      return 0;
    }
    default: {
      printf("\n\nOPC INVÁLIDA!\n\n");
      break;
    }
    }
    pause();
  }

  return 0;
}
