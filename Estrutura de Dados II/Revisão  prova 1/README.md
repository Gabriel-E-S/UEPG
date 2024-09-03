# Revisão para a prova 

## Conteúdos dessa prova

Busca Sequencial
Busca Binária
Busca Sentinela
Busca Transposição
Busca Mover Para Frente

## Buscas do tipo sequencial

São algoritmos mais simples, em que percorremos a lista elemento a elemento até encontrar, ou não, a chave que desejamos procurar.

Para dados que não estejam ordenados esse tipo de busca pode ser interessante.

Podemos realizar a implementação retornando o elemento ou o seu índice.

### Complexidade

| Caso        | Melhor Caso | Pior Caso | Caso Médio |
|-------------|-------------|-----------|------------|
| Exista      | O(1)        |  O(n)     |  n/2       |
| Não exista  | O(n)        |  O(n)     |  O(n)      |


O melhor acontece quando o elemento que estamos a buscar é o primeiro da lista.

O pior caso acontece quando ele está por último ou ele não existe na lista, porque precisaremos percorrer ela toda.

### Implementações

#### Busca Sequencial Tradicional

Implementação em linguagem C

```c

int BuscaSequencial(int vet[],int n,int chave){

    int i;

    for(i=0;i<n;i++){
        if(vet[i] == chave){
            return i; // 1
            break; // 2
        }
    }
    return -1; // 3
}
```

1. Retornamos o índice aonde está o elemento.

2. Colocamos o break para quando acharmos o elemento seja interrompida a busca.

3. Retornamos -1 caso o elemento não exista no vetor.

#### Busca Sequencial Sentinela

A fim de melhorarmos um pouco o desempenho do código acima, podemos fazer a busca e uma forma em que uma das comparações seja eliminada, de forma que comparamos no critério de parada do laço de repetição.

Implementação em linguagem C

```c

int buscaSentinela(int vet[], int n, int chave){

    int i, aux;

    if(vet[n-1] == chave){
        return n-1;
    }
    else{
        aux = vet[n-1];
        vet[n-1] = chave;
    }

    i = 0;

    while(vet[i]!=chave){
        i++;
    }

    vet[n-1] = aux;

    if(i == n-1){
        return -1;
    }
    else{
        return i;
    }
}
```

#### Busca Mover Para Frente

Nesse tipo de busca se encontramos uma chave de pesquisa trazemos ela para a primeira posição do vetor e rearanjamos o restante uma posição para trás. 

Implementação em Linguagem C:

```c
int buscaMoverParaFrente(int vet[], int n, int chave){

    int i;

    for(i=0;i<n;i++){

        if(chave == vet[i]){

            int j;

            for(j=i;j>0;j--)  // 1
                vet[j] = vet[j-1];

            vet[0] = chave;
            return i;
        }
    }
    return -1;
}
```

1. Lógica que traz os elementos anteriores uma casa para frente.

#### Busca por Transposição

Nesse tipo de busca se achamos o elemento a ser buscado movemos ele para uma posição imediatamente a frente da anterior.

Implementação em linguagem C:

```C
int buscaTransposicao(int vet[], int n, int chave){

    int i,aux;

    if(vet[0] == chave ){ // 1
        return 0;
    }
    else{

        for(i=1;i<n;i++){

            if(vet[i] == chave){

                aux = vet[i];   // 2
                vet[i]= vet[i-1];
                vet[i-1] = aux;
                return i;
            }
        }
    }
    return -1;
}
```
1. Se o elemento buscado estiver na primeira posição temos que fazer esse teste para evitar erros.

2. Nessa parte de código trocamos o elemento com o seu imediatamente anterior.

## Busca Binária

Só pode ser aplicada em estruturas ordenadas, mas possui grande vantagem em relação ao seu tempo de execução. A cada iteração o conjunto usado pela busca diminui pela metade!

Abordagem de divisão e conquista

### Complexidade

Para o algoritmo de busca binária temos uma complexidade de tempo O(log n).

### Implementação

Segue a implementação em linguagem C



```c
int buscaBinaria(int vet[], int n, int chave){
    int inicio, fim, meio ;

    inicio = 0;
    fim = n-1;

    while(inicio <= fim){

        meio = (inicio+fim)/2;

        if(vet[meio] == chave){
            return meio;
        }
        else{
            if(vet[meio] > chave){
                fim = meio - 1;
            }
            else{
                inicio = meio + 1;
            }
        }
    }
    return -1;
}
```

## Filas de Prioridade ( HEAP's)

### Características

Uma heap é uma lista de prioriedade finita que pode ser implementada usando vetores.

Cada dado da heap tem  um grau de prioriedade.

São consideradas árvores completas representadas por vetores.

### Revisando árvores

**Árvores completas -** São árvores que posuem as seguintes características:

+ Cada nó possui no máximo 2 filhos
+ As folhas estão somente no último ou penúltimo nível.

### Organização da Heap

Ela é preenchida da esquerda para a direita.

Utilizamos os índices do vetor para organizá-la.

Para acharmos os filhos de `i` fazemos $$ Fe= i * 2$$ $$ Fd  = i * 2 + 1 $$ se $2*i <=n $.

Para acharmos o pai de `i` fazemos $$ Pi = i/2$$ se $i >2$.

Nível de um elemento: $ log(i) $ .

Altura de um elemento: $ log(n/i) $ .

As subárvores podem ser consecutivas ou não.

**IMPORTANTE -** todo nó deve ter prioridade igual ou maior a prioriedade de seus filhos, se existirem, em uma heap.

### Tipos de Heap

+ Heap máxima: Quando o nó pai é sempre maior que seus filhos.

+ Heap mínima: Quando o nó pai é sempre menor que seus filhos.


### Implementação

Estudamos 3 operações envolvendo heaps:
+ Inserção.
+ Remoção.
+ Consultar o elemento de maior prioriedade.

Precisamos definir a estrutura que será usada para a implementação:

```c
struct heap_type{
    int chaves[MAXHEAP];
    int n;
}
```

### Algoritmo de inserção

O elemento deve ser inserido na primeira posição vazia do vetor, mas respeitando a ordem de prioriedade.

Caso essa ordem seja quebrada temos que restaurá-la.

Implementação em linguagem C:


```c
void insereHeap(heap_type *heap,int valor){

    if(heap->n == HEAPMAX){
        return ;
    }
    heap->n++;

    heap->chaves[heap->n] = valor;
    subir(heap,heap->n);
}
```

```c

void subir(heap_type *heap, int i){

    int j;

    j = i/2

    if(j>= 1){
        if(heap->chaves[i] > heap->chaves[j]){
            aux = heap->chaves[i];
            heap->chaves[i] = heap->chaves[j];
            heap->chaves[j] = aux;
            subir(heap,j);
        }
    }
}
```

### Algoritmo de remoção

Devemos remover sempre o elemento de maior prioriedade e manter as características da heap.

Algoritmo implementado em lingaugem C:


```C
void removeHeap(heap_type *heap){

    int aux;

    if(heap->n == 0){
        return;
    }

    aux = heap->chaves[heap->n];
    heap->chaves[heap->n] = heap->chaves[1];
    heap->chaves[1] = aux ;

    heap->n --;

    descer(heap,1);
}
```

``` void descer(heap_type *heap,int i){

    int j, aux;

    j = i * 2;

    if(j<= heap->n){

        if(heap->chaves[j+1] > heap->chaves[j]){
            j++
        }
        if(heap->chaves[i] < heap->chaves[j]){
            aux = heap->chaves[i];
            heap->chaves[i] = heap->chaves[j];
            heap->chaves[j] = aux ;
            descer(heap,j);
        }

    }

}
```

### Algoritmo para ver o elemento de maior prioriedade

Nesse código apenas mostramos o elemento mais priorietário, que sempre será  primeiro elemento:

**OBS:** lembrar que a implementação foi feita começando no índice 1.


``` c
void mostraPriorietario(heap_type *heap){
    printf("O elemento mais priorietário é %d",heap->chaves[1]);
}
```

## Tabela Hash (espalhamento)

É uma generalização de um vetor com m posições.

Cada posição do vetor representa um endereço.

A posição é calculada com base no valor do endereço.

Em resumo tabelas hashing são dicionários para facilitar o
encontro de informações dentro de uma estrutura de
armazenamento.

As operações de busca podem chegar a O(1).

### Funções de hashing

Evitam que hajam colisões na hora de inserir.

Existem as formas que usam equações lineares, quadráticas, listas encadeadas, etc.

Estrutura que vamos usar:

```c
typedef struct hash_type{
    int valor;
    bool ocupado;
} hash_type ;
```

Funções auxiliares:

```c
int espalha(int chave,int tam,int incremento){

    return chave % tam + incremento;
}
```
```c
bool indiceOcupado(int indice){
    return hash[indice].ocupado;
}
```

### Inserção usando espalhamento linear:

```c
void insere(int valor){
    if(tamanhoAtual == MAXHASH){
        return;
    }

    tamanhoAtual ++;

    int indice = espalha(valor,MAXHASH,0);

    int i = 0;

    while(indiceOcupado(indice)){
        indice = espalha(valor,MAXHASH,i);
        i++;
    }
    hash[indice] = valor ;
    hash[indice].ocupado = true;
}
```

### Procedimento de busca

```c
int busca(int valor){
    int c = 0 ;

    int indice;

    while(c < MAXHASH){
        indice = espalha(valor,MAXHASH);
        if(hash[indice] == valor){
            return indice;
        }
        c++ ;
    }
    return -1;
}
```
### Tratamento de colisões usando listas

Para fazermos isso precisamos definir outra estrutura:

```c
struct no{
    int valor;
    struct no *proximo;
}
```
```c
typedef struct hash_type{
    bool ocupado;
    no *endereco;
} hash_type ;
```

### Função de inserção com listas

```c
void insere(int valor){

    if(tamanhoAtual == N){
        printf("HASH CHEIA!");
        return;
    }
    tamanhoAtual++ ;

    int indice = espalha(valor,N,0);

    if(hash[indice].endereco == NULL){
        hash[indice].endereco = insereLista(valor,NULL);
    }
    else{
        vetor[indice].endereco = insereLista(valor,vetor[indice].endereco);
    }

    vetor[indice].ocupado = true;
}
```

Função para inserir na lista:

```c
struct no* insereLista(int valor,no *inicio){

    struct no *aux ;
    aux = (no*)malloc(sizeof(no));

    aux->valor = valor ;
    aux->proximo = NULL ;


    if(inicio == NULL){
        inicio = aux ;
    }
    else{
        aux->proximo = inicio;
        inicio = aux;
    }
    return inicio ;
}
```





