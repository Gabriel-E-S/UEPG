#include <stdio.h>

#define TAM 3

// definindo como implementaremos nossa lista

int lista[TAM], cont = 0 ;

// função que diz se a lista está vazia ou não

int vazia(){
    if(cont == 0){
        printf("\n\nLISTA VAZIA!\n\n");
        return 1;
    }
    else{
        return 0;
    }

}

// procedimento para inserir um elemento na lista ordenada

void inserir(int valor){

    int i;

    if(cont == TAM){
        printf("\n\nLISTA CHEIA!\n\n");
        return;
    }

    // nesse for pegamos os elementos que são maiores que o valor que queremos inserir
    // e trocamos de posição deslocando eles para direita

    for(i=cont; i>=0 && valor < lista[i-1];i--){
        lista[i] = lista[i-1] ;
    }

    // após acharmos a posição correta o valor é inserido

    lista[i] = valor ;
    cont ++ ; // e o contador atualizado
    printf("\n\nVALOR INSERIDO!\n\n");
}

// procedimento que remove elementos por posição

void removerPosicao(int posicao){
    int i;

    if(vazia()){
        return ;
    }

    // aqui nesse for pegamos todos os elementos que estão para a frente do vetor
    // e deslocamos para a esquerda

    for(i=posicao;i<cont-1;i++){
        lista[i] = lista[i+1];
    }
    cont -- ;   // depois atualizamos o contador

    printf("\n\nVALOR DA POSICAO %d REMOVIDO\n\n",posicao);
}

// procedimento para remover elementos por valor
// se um mesmo valor existir mais de uma vez todos são removidos

void removerValor(int valor){

    int i,existe = 0;

    for(i=0;i<cont;i++){    // esse laço percorre o vetor todo procurando se o valor existe
        if(valor == lista[i]){
            removerPosicao(i);  // se o valor existir é removido
            i-- ;
            existe = 1;
        }
    }
    if(existe){
        printf("valor encontrado e removido");
    }
    else{
        printf("o valor n está na lista");
    }

}

// procedimento para imprimir a lista

void imprimir(){

    int i;
    if(vazia()){
        return ;
    }

    printf("\n\nLISTA ATUAL\n\n");
    for(i=0;i<cont;i++){
        printf("%d ",lista[i]);
    }
    printf("\n\n");

}

// exemplo de implementação

int main(){

    inserir(1);
    inserir(3);
    inserir(2);

    imprimir();

    removerPosicao(0);
    removerValor(3);

    imprimir();

    return 0;
}

