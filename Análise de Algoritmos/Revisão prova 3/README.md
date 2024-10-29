# Revisão prova 3

## Algoritmos de ordenação

A ordenação de dados é algo muito importante em computação.

### Algoritmos de ordenação estáveis

São aqueles que ao termos mais de 1 elemento igual a ser ordenado a ordem original é preservada.

Exemplo:

Considere o vetor 

```C
   int vetor[] =  [4,2,5,2,1]
   //posicões:     0,1,2,3,4
```

Quando o algoritmo é estável, obrigatóriamente o número `2` do índice 1 vem antes do que o `2` do índice 3.

### Principais algoritmos de ordenação

Se quiser clique no nome para ver um contéudo em específico.

+ [Ordenação por Inserção](#ordenação-por-inserção).
+ [Ordenação por Seleção](#ordenação-por-seleção).
+ [MergeSort ou Ordenação por Combinação ou Intercalação](#ordenação-por-combinação-merge-sort).
+ [Heapsort](#heap-sort)
+ [QuickSort](#quicksort)
+ Ordenação por Contagem
+ Ordenação por Dígitos
+ Ordenação por Caixas (Bucket Sort)

Um resumo das suas complexidades de tempo pode ser dada pela tabela a seguir:

| Algorithm       | Worst-case running time | Average-case/expected running time |
|-----------------|-------------------------|------------------------------------|
| Insertion sort  | Θ(n²)                   | Θ(n²)                              |
| Selection sort  | Θ(n²)                   | Θ(n²)                              |
| Merge sort      | Θ(n lg n)               | Θ(n lg n)                          |
| Heapsort        | O(n lg n)               | —                                  |
| Quicksort       | Θ(n²)                   | Θ(n lg n) (expected)               |
| Counting sort   | Θ(k + n)                | Θ(k + n)                           |
| Radix sort      | Θ(d (n + k))            | Θ(d (n + k))                       |
| Bucket sort     | Θ(n²)                   | Θ(n) (average-case)                |


### Ordenação por Inserção

Esse algoritmo vai procurando o menor elemento e colocando ele em uma porção ordenada do vetor, movendo a outra parte para isso.

#### Versão recursiva:

```C
void inserctionSort(int A[],int n){

    if(n<=1){
        return;
    }

    inserctionSort(A,n-1);

    int x = A[n-1];
    int j = n-2;

    while(j>=0 && x< A[j] ){
        A[j+1] = A[j];
        j = j-1;
    }

    A[j+1] = x;
}
```

#### Versão iterativa:

```C
void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i]; // O elemento a ser inserido
        int j = i - 1;

        // Move os elementos de A[0..i-1], que são maiores que x, para uma posição à frente
        while (j >= 0 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }

        // Insere o elemento na posição correta
        A[j + 1] = x;
    }
}
```
#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n^2) $.

+ Complexidade de melhor caso: $\Theta(n) $

+ É estável? `SIM`.

### Ordenação por Seleção

Faz uma buca pelo menor item e faz a troca.

Função que faz a troca de duas variáveis:

```C
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

```

#### Versão recursiva
```C
void selectionSort(int A[], int n) {
    if (n <= 1) {
        return;
    }

    // Encontra o índice do menor elemento no array A[0..n-1]
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] < A[minIndex]) {
            minIndex = i;
        }
    }

    // Troca o primeiro elemento com o menor elemento encontrado
    swap(&A[0], &A[minIndex]);

    // Chama a função recursivamente para o restante do vetor
    selectionSort(A + 1, n - 1);
}
```

#### Versão iterativa

```C
void selectionSort(int A[], int n) {
    int i,j;

    for ( i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume que o primeiro elemento é o menor

        // Encontra o índice do menor elemento na parte não ordenada
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        // Troca o elemento atual com o menor encontrado
        if (minIndex != i) {
            swap(&A[i], &A[minIndex]);
        }
    }
}
```

#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n^2) $.

+ Complexidade de melhor caso: $\Theta(n^2) $

+ É estável? `NÃO`.

### Ordenação por Combinação (Merge sort)

Algoritmo que usa divisão em conquista para resolver o problema.

+ **Divisão**: Divide o vetor em dois vetores de tamanho n/2.

+ **Conquista**: Recursivamente as duas metades são ordenadas.

+ **Combinação**: Combina-se as duas metas para formar um vetor novamente só que ordenado.

A função intercala junta as duas metades usando um vetor auxiliar.

```C
void intercala(int inicio,int fim,int meio){

    int poslivre, inicio_vet, inicio_vet2,i, aux[N] ;

    inicio_vet = inicio ;
    inicio_vet2 = meio + 1 ;
    poslivre = inicio;

    while(inicio_vet <= meio && inicio_vet2 <= fim){
        if(vetor[inicio_vet] <= vetor[inicio_vet2]){
            aux[poslivre] = vetor[inicio_vet];
            inicio_vet ++ ;
        }
        else{
            aux[poslivre] = vetor[inicio_vet2];
            inicio_vet2 ++ ;
        }
        poslivre ++ ;
    }
    for(i=inicio_vet;i<=meio;i++){
        aux[poslivre] = vetor[i];
        poslivre++ ;
    }
    for(i=inicio_vet2;i<=fim;i++){
        aux[poslivre] = vetor[i];
        poslivre++ ;
    }
    for(i=inicio;i<=fim;i++){
        vetor[i] = aux[i];
    }
}
```
Função do mergeSort

```C
void mergeSort(int inicio,int fim){

    int meio ;

    if(inicio<fim){
        meio = (inicio+fim)/2 ;

        mergeSort(inicio,meio); // divide o vetor em duas metades
        mergeSort(meio+1,fim);
        intercala(inicio,fim,meio); // combina o resultado
    }
}
```

#### Equação de recorrência

A equação de recorrência desse algoritmo é:


$$ T(n) = 2T(n/2)+ cn $$

Que tem solução $\Theta(n\cdot log(n))$

#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n\cdot log(n))$.

+ Complexidade de melhor caso: $\Theta(n\cdot log(n))$.

+ Complexidade de espaço:
$\Theta(n)$.

+ É estável? `SIM`.

### Heap Sort

Nesse resumo não irei detalhar o que é uma heap, no entanto o heap sort consiste em criar essa estruturar de dados em um vetor e ordená-lo com base nisso.

Algumas operações possíveis:

+ Max-Heapify(A, i) As sub-árvores do nodo i são max-heaps, mas
A[i] pode ser menor do que seus dois filhos. O
procedimento transforma A[] em um max-heap. Tempo: $O(log(n))$

+ Constrói-Heap(A) Transforma o vetor A em um heap. Tempo: $O(n)$
.

+ HeapSort(A) Ordena o vetor A usando as operações
Constrói-Heap() e Max-Heap().

```C
// Função para ajustar o heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int left = 2 * i + 1; // Filho esquerdo
    int right = 2 * i + 2; // Filho direito

    // Verifica se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Verifica se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz, troca e continua a heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
```
Agora a função que chama a anterior:

```C
// Função principal para implementar o heap sort
void heapSort(int arr[], int n) {
    int i;
    // Constrói um heap máximo
    for ( i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Um a um, extrai elementos do heap
    for ( i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Mover a raiz atual para o final
        heapify(arr, i, 0); // Chama heapify na árvore reduzida
    }
}
```
#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n\cdot log(n))$.

+ Complexidade de melhor caso: $\Theta(n\cdot log(n))$.

+ É estável? `NÃO`.

### QuickSort

Um algoritmo eficiente para ordenação que por mais que possua tempo de pior caso de $\Theta(n^2)$, tem sua eficiência comprovada analiticamente e experimentalmente considerando que seu caso médio é de $\Theta(n\cdot log(n))$.

+ **Divisão**: Divide o vetor em dois vetores de tamanho n/2, colocando os elementos menores do que o pivô na primeira parte.

+ **Conquista**: Recursivamente as duas metades são ordenadas.

+ **Combinação**: `No quick sort não é preciso fazer nada para combinar as soluções!`

#### Passo a passo do algoritmo:

1. Escolhemos um pivô para comparação.

+ **IMPORTANTE**: para que dois elementos sejam comparados um deles `OBRIGATORIAMENTE` deve ser o pivô, e cada elemento só é comparado `1 vez`.

2. É chamada a função [partição](#função-partição) que coloca os menores queo pivô para um lado e os maiores do outro dividindo o vetor em duas partes.

3. As partes criadas são ordenadas recursivamente.

##### Função partição:

```C
int particao(int A[], int p, int r) {
    int j;
    int x = A[r]; // Escolhendo o último elemento como pivô
    int i = p - 1; // Índice do menor elemento

    // Itera sobre os elementos da parte da lista que está sendo ordenada
    for (j = p; j <= r - 1; j++) {
        if (A[j] <= x) { // Se o elemento atual é menor ou igual ao pivô
            i++; // Aumenta o índice do menor elemento
            troca(&A[i], &A[j]); // Troca os elementos
        }
    }
    swap(&A[i + 1], &A[r]); // Coloca o pivô na posição correta
    return i + 1; // Retorna o índice do pivô
}
```

E a função que organiza as chamadas recursivas

```C
// Função principal do QuickSort
void quicksort(int A[], int p, int r) {
    if (p < r) { // Verifica se a lista tem mais de um elemento
        int q = particao(A, p, r); // Particiona e obtém o índice do pivô
        quicksort(A, p, q - 1); // Ordena a parte da esquerda
        quicksort(A, q + 1, r); // Ordena a parte da direita
    }
}
```

Nessa implementação o pivô foi escolhido como o elemento mais a direita do vetor,
podem ser usadas eurísticas para minizar a chance do pior caso como mediana de 3 elementos, pivô aleatório...

#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n\cdot log(n))$.

Acontece quando a distribuição das duas metades fica muito desigual deixando dois problemas de tamanho **n-1** e **0**.


+ Complexidade de melhor caso: $\Theta(n\cdot log(n))$.

Acontece quando o vetor é quase sempre dividido ao meio.

+ Complexidade de espaço:
$\Theta(1)$.

+ É estável? `NÃO`.

+ A probabilidade de dois elementos distintos serem comparados em um intervalo $I_{ij}$ é dada por $\frac{2}{j-i+1}$ .
























