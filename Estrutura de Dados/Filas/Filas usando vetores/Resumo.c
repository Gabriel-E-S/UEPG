# include <stdio.h>

#define TAM 3

// declaração da fila, teremos uma variável para mostrar aonde está o início,
// o fim, e uma para contar a quantidade de elementos na fila

int fila[TAM], inicio = 0, fim = 0, cont = 0 ;

// função que retorna 1 se a fila está vazia e 0 se ela não está

int vazia(){
    if(cont == 0){
        printf("\n\nFILA VAZIA\n\n");
        return 1 ;
    }
    else{
        return 0;
    }

}

// procedimento que insere elementos no final da fila

void insereFila(int valor){

    if(cont == TAM){    // se o cont for igual ao TAM a fila está cheia
        printf("\n\nFILA CHEIA!\n\n");
        return ;
    }
    fila[fim] = valor ; // elementos na fila são colocados sempre no final

    if(fim == TAM - 1){ 
        fim = 0;
    }
    else{
        fim ++ ;
    }
    cont ++ ;   // a cada inserção cont é atualizado
    printf("\nELEMENTO %d ADICIONADO!\n",valor);

}

// procedimento que remove elementos do início da fila

void removeFila(){

    if(vazia()){
        return ;
    }
    printf("\nELEMENTO %d REMOVIDO!!\n",fila[inicio]);
    cont --;
    if(inicio == TAM - 1){
        inicio = 0 ;
    }
    else{
        inicio ++ ;
    }
}

// procedimento para imprimir a fila, como estamos usando um formato circular
// é necessário uma impressão diferenciada

void imprimir(){

    int aux1, aux2 ;

    printf("\n\nFILA ATUAL\n\n");

    for(aux1 = inicio,aux2 = 0; aux2<cont;aux2++){

        printf("%d ",fila[aux1]);
        if(aux1 == TAM - 1){
            aux1 = 0 ;
        }
        else{
            aux1++ ;
        }
    }
    printf("\n\n");

}

// exemplo de utilização

int main(){

    removeFila();

    insereFila(10);
    insereFila(8);
    imprimir();

    insereFila(12);
    insereFila(14);

    imprimir();

    removeFila();
    imprimir();

    insereFila(14);
    imprimir();



    insereFila(16);
}

