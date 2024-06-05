# include <stdio.h>
# include <stdlib.h>



typedef struct no{
    int valor;
    struct no *proximo ;
    struct no *anterior ;
}no ;

no *inicio = NULL, *fim = NULL ;

void inserirDireita(int valor){

    no *aux = (no*) malloc(sizeof(no));

    aux->valor = valor ;
    aux->proximo = NULL ;

    if(inicio == NULL){
        aux->anterior = NULL ;
        inicio = aux;
        fim = aux ;
    }
    else{
        fim->proximo = aux ;
        aux->anterior = fim ;
        fim = aux ;
    }
    printf("\nVALOR %d INSERIDO\n",valor) ;

}

void inserirEsquerda(int valor){

    no *aux = (no*) malloc(sizeof(no));

    aux->valor = valor ;
    aux->anterior = NULL ;

    if(inicio == NULL){
        aux->proximo = NULL ;
        inicio = aux;
        fim = aux ;
    }
    else{
        aux->proximo = inicio ;
        inicio->anterior = aux ;
        inicio = aux ;

    }
    printf("\nVALOR %d INSERIDO\n",valor) ;
}

void removerEsquerda(){

    no *aux = inicio;

    int vremovido = inicio->valor ;

    inicio = inicio->proximo;

    inicio->anterior = NULL;

    free(aux);

    printf("\nVALOR %d REMOVIDO PELA ESQUERDA\n",vremovido);
}

void removerDireita(){

    no *aux = fim;

    int vremovido = fim->valor ;

    fim = fim->anterior;

    fim->proximo = NULL ;

    free(aux);

    printf("\nVALOR %d REMOVIDO PELA DIREITA\n",vremovido);
}


void removerValor(int valor){

    no *aux, *atual, *lixo = NULL;
    atual = inicio;

    while(atual != NULL){

        if(atual->valor == valor){

            if(atual == inicio){
                lixo = inicio ;
                inicio = inicio->proximo ;

                free(lixo);
                atual = inicio;
                inicio->anterior = NULL ;
                printf("\nVALOR %d REMOVIDO DO INICIO\n",valor);
            }
            else if(atual == fim){
                lixo = fim;
                fim = fim->anterior ;
                fim->proximo = NULL;
                free(lixo);
                atual = NULL ;
                printf("\nVALOR %d REMOVIDO DO FIM\n",valor);
            }
            else{
                no *aux2 ;
                aux2 = atual->proximo ;
                lixo = atual ;

                aux = atual->anterior ;

                aux->proximo = atual->proximo ;
                aux2->anterior = aux;
                free(lixo);
                atual = aux2;
                printf("\nVALOR %d REMOVIDO DO MEIO\n",valor);
            }

        }else{
            atual = atual->proximo;
        }
    }
}

void imprimeDequeNormal(){

    no *aux ;

    aux = inicio ;

    printf("\n\nDEQUE ATUAL\n\n");

    while(aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->proximo ;
    }
    printf("\n\n");
}

void imprimeDequeInvertido(){

    no *aux ;

    aux = fim ;

    printf("\n\nDEQUE ATUAL INVERTIDO\n\n");

    while(aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->anterior ;
    }
    printf("\n\n");
}

int main(){

    inserirDireita(1);
    inserirDireita(2);
    inserirDireita(3);
    inserirDireita(1);
    inserirDireita(2);
    inserirDireita(3);
    inserirDireita(2);
    inserirEsquerda(2);

    imprimeDequeNormal();

    removerValor(2);

    imprimeDequeNormal();

    imprimeDequeInvertido();
}
