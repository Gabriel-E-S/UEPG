//////////////////////////////////////////
//  CÓDIGO FEITO POR: Gabriel E.Santo   //
//  ESTRUTURA DE DADOS 2                //
//  ÁRVORESS AVL                        //
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>     // Bibliotecas

typedef struct no
{
    int dado;           // Campo que guarda o valor
    int bal;            // Campo que guardar o balanceamento atual
    struct no *esq;     // Ponteiro para o nó esquerdo 
    struct no *dir;     // Ponteiro para o nó direito
} no;

struct no *raiz_avl = NULL; // Raiz da árvore

// Função que cria e retorna um nó

struct no* cria_no(int chave)
{
    no *aux = (no*) malloc(sizeof(no)); // Alocando espaço na memória

    aux->dado = chave;                  // Colocando a key no nó
    aux->dir = NULL;                    // Começando os ponteiros com NULL
    aux->esq = NULL;
    aux->bal = 0;                       // E o balanceamento com 0

    return aux;
}

// Procedimento que faz uma rotação para a esquerda simples

void esquerda(no *atual)    // Atual é o nó pai
{
    no *q,*aux;             // Ponteiros auxiliares

    q = atual->dir;         // Fazendo a rotação pt.1
    aux = q->esq;           // Resolvendo o problema do filho perdido.

    q->esq = atual;         // pt.2
    atual->dir = aux;       // Adotando o filho perdido

}

// Procedimento que faz uma rotação para a direita simples

void direita(no *atual)     // Espelhado da versão a esquerda
{
    no *q,*aux;

    q = atual->esq;
    aux = q->dir;

    q->dir = atual ;

    aux->esq = aux;
}

// Procedimento que imprime uma árvore em preOrdem

void preOrdem(no *atual)
{
    if(atual!= NULL)
    {

        printf("%d ",atual->dado);

        preOrdem(atual->esq);
        preOrdem(atual->dir);
    }
}

// Procedimento que imprime uma árvore em emOrdem

void emOrdem(no *atual)
{
    if(atual!= NULL)
    {
        emOrdem(atual->esq);

        printf("%d ",atual->dado);

        emOrdem(atual->dir);
    }
}

// Procedimento que imprime uma árvore em posOrdem

void posOrdem(no *atual)
{
    if(atual!= NULL)
    {
        posOrdem(atual->esq);
        posOrdem(atual->dir);
        printf("%d ",atual->dado);
    }
}

void insere_bal(int chave)
{
    struct no *pp = NULL, *p = raiz_avl, *pajovem = NULL, *ajovem =
                                       raiz_avl, *q, *filho;
    int imbal;
    if (p == NULL)   /* Arvore vazia */
    {
        raiz_avl = cria_no(chave); /* Funcao para criacao de um novo no */
        return;
    }

    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p != NULL)
    {
        if (chave < p->dado)
            q = p->esq;
        else q = p->dir;
        if (q != NULL)
            if (q->bal != 0)
            {
                pajovem = p;
                ajovem = q;
            }
        pp = p;
        p = q;
    }
    q = cria_no(chave);
    if (chave < pp->dado)
        pp->esq = q;
    else pp->dir = q;
    /* Balanceamento de todos os nÃ³s entre ajovem e q devem ser
    ajustados */
    if (chave < ajovem->dado)
        filho = ajovem->esq;
    else filho = ajovem->dir;
    p = filho;
    while (p != q)
    {
        if (chave < p->dado)
        {
            p->bal = 1;
            p = p->esq;
        }
        else
        {
            p->bal = -1;
            p = p->dir;
        }
    }
    if (chave < ajovem->dado)
        imbal = 1;
    else imbal = -1;
    if (ajovem->bal == 0)   /*NÃ£o houve desbalanceamento */
    {
        ajovem->bal = imbal;
        return;
    }
    if (ajovem->bal != imbal)   /*NÃ£o houve desbalanceamento */
    {

        ajovem->bal = 0;
        return;
    }
    /* Houve desbalanceamento */
    if (filho->bal == imbal)
    {
        p = filho;
        if (imbal == 1) /* Faz rotacao simples */
            direita(ajovem);
        else esquerda(ajovem);
        ajovem->bal = 0;
        filho->bal = 0;
    }
    else
    {
        if (imbal == 1)   /*Faz rotacao dupla */
        {
            p = filho->dir;
            esquerda(filho);
            ajovem->esq = p;
            direita(ajovem);
        }
        else
        {
            p = filho->esq;
            direita(filho);
            ajovem->dir = p;
            esquerda(ajovem);
        }
        if (p->bal == 0)
        {
            ajovem->bal = 0;
            filho->bal = 0;
        }
        else
        {
            if (p->bal == imbal)
            {
                ajovem->bal = -imbal;
                filho->bal = 0;
            }
            else
            {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal = 0;
    }
    if (pajovem == NULL) /* Ajusta ponteiro do pai do ancestral mais jovem
*/

    raiz_avl = p;

    else if (ajovem == pajovem->dir)
        pajovem->dir = p;
    else pajovem->esq = p;
    return;
}

// função que faz a busca, semelhante a busca binaria

void buscaAVL(no *atual,int valor, int *resposta){

    if(atual != NULL){

        if(atual->dado == valor){
            *resposta = 1;
        }
        else{
            if(atual->dado > valor){
                buscaAVL(atual->esq,valor,resposta);
            }
            else{
                buscaAVL(atual->dir,valor,resposta);
            }
        }
    }
}

// função de menu

void menuImprimir(){

    int opc = -1;

    if(raiz_avl == NULL){
        printf("ÁRVORE VAZIA!");return;
    }

    while(opc != 4){

        
        printf("1-PRE ORDEM\n");
        printf("2-EM ORDEM\n");
        printf("3-POS ORDEM\n");
        printf("4- SAIR\n");
        printf("ESCOLHA --> ");
        scanf("%d",&opc);

        while(getchar()!= '\n');

        switch(opc){

            case 1:{
                printf("\npre ordem\n");
                preOrdem(raiz_avl);
                break;
            }

            case 2:{
                printf("\nem ordem\n");
                emOrdem(raiz_avl);
                break;
            }

            case 3:{
                printf("\npos ordem\n");
                posOrdem(raiz_avl);
                break;
            }
            case 4:{
                return;
            }
            default:{
                printf("\n\nOPC INVÁLIDA!\n\n");
                break;
            }


        }

        printf("\n\n");system("pause");

    }



}



int main()
{
    setlocale(LC_ALL,"Portuguese");

    int opc = -1;


    while(opc != 0){
        
        printf("1- INSERIR\n");
        printf("2- BUSCAR\n");
        printf("3- IMPRIMIR\n");
        printf("4- SAIR\n");
        printf("ESCOLHA --> ");

        scanf("%d",&opc);
        while(getchar()!= '\n');

        switch(opc){

            case 1:{
                int valor;

                printf("\nDIGITE O VALOR --> ");
                scanf("%d",&valor);
                while(getchar()!= '\n');

                insere_bal(valor);
                break;
            }
            case 2:{

                int valor, res = 0;

                if(raiz_avl == NULL){
                    printf("ÁRVORE VAZIA!");
                    break;
                }

                printf("\nDIGITE O VALOR --> ");
                scanf("%d",&valor);
                while(getchar()!= '\n');

                buscaAVL(raiz_avl,valor,&res);

                if(res){
                    printf("\nENCONTREI O NÚMERO\n");
                }
                else{
                    printf("\nNÃO ENCONTREI O NÚMERO\n");
                }

                break;
            }
            case 3:{
                menuImprimir();
                break;
            }
            case 4:{
                printf("\nVOCÊ SAIU!");
                break;
            }
            default:{
                printf("\n\nOPC INVÁLIDA!\n\n");
                break;
            }


        }
    }

    return 0;
}
