# Algoritmos de ordenação

Ordenar dados é de extrema importância, para isso podemos utilizar diferentes métodos.

## Buble sort 1

```C

void bubleSort1(int vetor[], int N){
    int i, j, aux ;

    for(i=0 ; i< N; i++){
        for(j=0 ; j<N-1; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j] ;
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux ;
            }
        }
    }
}
```

## Buble Sort 2 

```C

void bubleSort2(int vetor[], int N){
    int i, j, aux ;

    for(i = 0;i<=N-1;i++){
        for(j = N-1 ; j>=i ; j--){
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux ;
            }
        }
    }
}
```

## Buble Sort 3

```C

void bubleSort3(int vetor[], int N){
    int i, j, aux, troca ;

    i = 1;
    troca = 1;

    while (i<= N && troca == 1){
        troca = 0;

        for(j=0 ; j<=N-1-i ; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux ;

                troca = 1 ;
            }
        }
        i = i + 1;
    }
}
```

## Inserction Sort

``` C

void inserctionSort(int vetor[],int N){

    int i, j, x, pivo, aux ;

    for(i=0 ; i<= N; i++){
        pivo = vetor[i];

        j = i-1 ;

        x = 0;

        while(x == 0 && j>= 0){
            if(vetor[j] > pivo){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux ;
                j-- ;
            }
            else{
                x = 1;
            }
        }
    }
}
```

## Selection Sort

``` C

void selectionSort(int vetor[],int N){

    int i,j, aux, aux2 ;

    for(i=0 ; i< N-1;i++){
        aux = i;
        for(j = i+1 ; j<N; j++){
            if(vetor[aux]> vetor[j]){
                aux = j ;
            }
        }
        aux2 = vetor[i];
        vetor[i] = vetor[aux];
        vetor[aux] = aux2 ;
    }
}
```

## Quick Sort

``` C

void troca(int vetor[],int i,int j){

    int aux;

    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux ;
}
```

```C

int particao(int vetor[], int inicio, int fim){
    int pivo, i, j;

    pivo = vetor[(inicio + fim)/2];

    i = inicio -1 ;
    j = fim + 1 ;

    while (i < j){
        do{
            j = j-1 ;
        }while(vetor[j] > pivo) ;

        do{
            i = i+1 ;
        }while(vetor[i]<pivo);

        if(i<j){
            troca(vetor,i,j);
        }
    }
    return j ;
}
```

``` C

void quickSort(int vetor[], int inicio, int fim){
    int meio ;

    if (inicio < fim){
        meio = particao(vetor, inicio, fim);
        quickSort(vetor, inicio, meio);
        quickSort(vetor, meio+1, fim);
    }
}

```
## Merge Sort

``` C

void intercala(int vetor[],int N, int inicio, int fim, int meio){

    int poslivre, inicio_vet, inicio_vet2, i , aux[N] ;

    inicio_vet = inicio ;
    inicio_vet2 = meio + 1 ;
    poslivre = inicio ;

    while(inicio_vet <= meio && inicio_vet2 <= fim){
        if(vetor[inicio_vet] <= vetor[inicio_vet2]){
            aux[poslivre] = vetor[inicio_vet];
            inicio_vet ++ ;
        }
        else{
            aux[poslivre] = vetor[inicio_vet2] ;
            inicio_vet2 ++ ;
        }
        poslivre ++ ;
    }
    for(i = inicio_vet ; i<=meio ; i++){
        aux[poslivre] = vetor[i];
        poslivre ++ ;
    }
    for(i = inicio_vet2 ; i<= fim;i++){
        aux[poslivre] = vetor[i];
        poslivre ++ ;
    }
    for(i = inicio ;i<= fim;i++){
        vetor[i] = aux[i] ;
    }
}

```

``` C

void mergeSort(int vetor[],int N, int inicio,int fim){
    int meio ;


    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeSort(vetor,N,inicio,meio);
        mergeSort(vetor,N,meio+1,fim);
        intercala(vetor,N,inicio,fim,meio);        
    }
}
```



