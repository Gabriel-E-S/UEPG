#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3

// declarando nossa estrutura de pilha

int pilha[TAM],topo = 0;


// a função vaia vê se o topo é igual a 0 e retorna 1 se isso acontecer, o que indica que a pilha está vazia

int vazia(){
    if(topo == 0){
        return 1;
        printf("\n\nPILHA VAZIA!\n\n");
    }
    else{
        return 0;
    }
}

// procedimento que adiciona um elemento na pilha

void push(int valor){

    if(topo == TAM){                        // se o topo for igual ao tamanho definido a pilha está cheia
        printf("PILHA CHEIA!\n");
        return ;
    }
    pilha[topo] = valor ;                   // colocando o valor na pilha, lembrando que o topo sempre aponta um elemento acima
    topo ++ ;                               // incrementando o topo
    printf("\nVALOR %d INSERIDO!\n",valor);
}

// procedimento para retirar elementos, ela modifica o ponteiro para o topo
// OBS: o valor não é efetivamente retirado da posição de memória, 
// somente o ponteiro é alterado.

void pop(){

    if(vazia()){
        return ;
    }
    printf("\nVALOR %d RETIRADO!\n",pilha[topo-1]);
    topo -- ;

}

// procedimento que imprime os elementos da pilha na tela
// para melhor visualização a impressão e feita de forma descrescente

void imprimir(){

    int i;
    printf("\n\nPILHA ATUAL\n\n");
    for(i = topo-1;i>=0;i--){
        printf("%d\n",pilha[i]);
    }
}

// um exemplo de utilização

int main(){

    push(1);
    push(2);
    push(3);
    imprimir();
    pop();
    pop();
    imprimir();



}
