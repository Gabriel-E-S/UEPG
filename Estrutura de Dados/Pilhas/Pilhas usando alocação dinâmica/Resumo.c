#include <stdio.h>
#include <stdlib.h> // precisamos dessa biblioteca para usar a alocação dinâmica de memória

// definindo a estrutura que representará os elementos da nossa pilha
// ela é feita do valor e do ponteiro que aponta para o próximo endereço de memória

typedef struct no{
    int valor ;
    struct no* prox;
}no ;

no *topo  ; // essa variável aponta para o topo da pilha


// procedimento para inserir um valor

void push(int valor){

    no *aux ;
    aux = (no*)malloc(sizeof(no)) ; // aqui é alocada memória de forma dinâmica

    aux->valor = valor ;
    aux->prox = topo ;
    topo = aux ;
    printf("\n\nVALOR %d INSERIDO!\n\n",valor) ;

}

// procedimento para remover elementos

void pop(){

    if(topo == NULL){
        printf("\n\nPILHA VAZIA!\n\n");
        return ;
    }

    no *aux ;
    aux = topo ;
    topo = topo->prox ;
    free(aux);

    printf("\n\nVALOR REMOVIDO!\n\n");
}

// função para imprimir a pilha

void imprimir(){

    no *aux ;
    aux = topo;

    while (aux != NULL){
        printf("%d\n",aux->valor);
        aux = aux->prox ;
    }
}

// exemplo de implementação

int main(){


    push(1);
    push(2);
    push(3);

    imprimir();

    pop();
    pop();

    imprimir();

    push(3);
    push(5);

    imprimir();


    return 0 ;
}

