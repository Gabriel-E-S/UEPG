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

### Principais algoritmos de ordenação e tópicos da revisão

Se quiser clique no nome para ver um contéudo em específico.

Tópicos de ordenação:

+ [Ordenação por Inserção](#ordenação-por-inserção).
+ [Ordenação por Seleção](#ordenação-por-seleção).
+ [MergeSort ou Ordenação por Combinação ou Intercalação](#ordenação-por-combinação-merge-sort).
+ [Heapsort](#heap-sort).
+ [QuickSort](#quicksort).
+ [Ordenação por Contagem](#ordenação-por-contagem-counting-sort).
+ [Ordenação por Dígitos](#ordenação-por-dígitos-radix-sort).
+ [Ordenação por Caixas (Bucket Sort)](#bucket-sort).
---
Outros tópicos:
+ [Programação dinâmica](#programação-dinâmica).
--- 

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
    int i;
    for (i = 1; i < n; i++) {
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
    int i;
    if (n <= 1) {
        return;
    }

    // Encontra o índice do menor elemento no array A[0..n-1]
    int minIndex = 0;
    for (i = 1; i < n; i++) {
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
void heapify(int arr[], int n,int i) {
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

## Ordenação em tempo linear

Métodos de ordenação por comparação de chaves tem cota inferior na complexidade de tempo de pior caso de $\Theta(n\cdot log(n))$.

Como ordenar em tempo linear então?

1. Não usar comparação entre chaves
    - por exemplo, comparar os dígitos dos números.
    - usar as chaves como índices.
2. Ter informações sobre a distribuição dos números
    - por exemplo, ordenar números com distribuição uniforme.
    - chaves dentro de um intervalo pequeno.
3. Casos particulares
    - Ordenar um vetor de zeros e uns.
    - Ordenar um vetor de n números entre 1 e n.

Vamos perceber que esses algoritmos não contradizem a cota inferior que será estudada no próximo tópico.

Além disso é possível ordenar em tempo linear dadas certas condicões.

Aqui o nosso primeiro exemplo:

```C
// Função que ordena um vetor de inteiros com n elementos
// contendo todos os números entre 0 e n-1.
// O é o vetor ordenado no final passado como parâmetro.
void Ordena(int *V, int n, int *O) {
    int i;
    // Inicializa o vetor O com zeros
    for ( i = 0; i < n; i++) {
        O[i] = 0; // Define todos os elementos como 0
    }

    // Preenche o vetor O com os elementos do vetor V
    for ( i = 0; i < n; i++) {
        O[V[i]] = V[i]; // Coloca cada elemento na posição correspondente
    }
}
```

Esse código percorre o vetor com n elementos somente uma vez, logo seu tempo de execução é $\Theta(n)$.

### Ordenação por Contagem (Counting sort)

* Conta o número de ocorrências de cada número

* Calcula quantos números são menores ou iguais a cada
número
* Atribui os números (registros) às suas posições no vetor de
saída
* percorre o vetor de entrada em ordem reversa
* a cada ocorrência de um número, decrementa o número de
números menores ou iguais a ele

#### Exemplo:

+ Vetor de Entrada: V = [7, 5, 5, 1, 1, 0, 2, 1]
+ Ocorrências de cada número: C = [1, 3, 1, 0, 0, 2, 0, 1]
+ Quantos números são menores ou iguais a:
C = [1, 4, 5, 5, 5, 7, 7, 8]
+ Vetor em Ordem: V = [0, 1, 1, 1, 2, 5, 5, 7].

#### Uma implementação em linguagem C

```C
void countingSort(int V[], int n, int max) {
    i;
    int C[max]; // Contar ocorrências
    int O[n];   // Vetor ordenado

    // Inicializa o vetor de contagem
    for (i = 0; i < max; i++) {
        C[i] = 0;
    }

    // Contar ocorrências
    for (i = 0; i < n; i++) {
        C[V[i]]++;
    }

    // Acumular as contagens
    for (i = 0; i < max - 1; i++) {
        C[i + 1] += C[i];
    }

    // Construir o vetor ordenado
    for (i = n - 1; i >= 0; i--) {
        O[C[V[i]] - 1] = V[i];
        C[V[i]]--;
    }

    // Copiar o vetor ordenado de volta para o vetor original
    for (i = 0; i < n; i++) {
        V[i] = O[i];
    }
}
```
#### Análise assintótica

Vamos considerar que o vetor tem `n` números e que o intervalo das chaves é de `0 até k-1`.

Percorremos o vetor V com `n` posições 2 vezes: $\Theta(n)$.
Percorremos o vetor C com `k`posições 1 vez: $\Theta(k)$.

Logo o tempo de execução é de $\Theta(n+k)$.

Quando $k ∈ O(n)$, então o algoritmo é $Θ(n)$.

#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n+k)$.

+ Complexidade de melhor caso: $\Theta(n)$.

+ É estável? `SIM`.

### Ordenação por dígitos (Radix sort)

+ Ordena strings de mesmo comprimento.
+ Ordena eficientemente números com muitos dígitos.

#### Ordem Lexicográfica - Definição

Dizemos que uma string s é lexicograficamente menor que uma
string t se o primeiro byte de s que difere do correspondente byte
de t é menor que o byte de t. Caso esse byte não existe, a menor
string é a com menos caracteres.

O ordenação por dígitos funciona devido essa propriedade, outro requisito é que devemos ordenar  do dígito `menos` significativo para o `mais` significativo, além disso a ordenação deve ser `estável`.

#### implementação em C

```C
void RadixSort(int V[], int n) {
    // Encontrar o valor máximo para determinar o número de dígitos
    i,exp;
    int max = V[0];
    for (i = 1; i < n; i++) {
        if (V[i] > max) {
            max = V[i];
        }
    }

    // Aplicar CountingSort para cada dígito
    for (exp = 1; max / exp > 0; exp *= 10) {
        CountingSort(V, n, exp);
    }
}
```

A função do CountingSort foi levemente modificada como se pode ver a seguir:

```C
void CountingSort(int V[], int n, int exp) {
    i;
    int output[n]; // Vetor de saída
    int count[10] = {0}; // Contador para dígitos (0-9)

    // Contar ocorrências dos dígitos
    for (i = 0; i < n; i++) {
        count[(V[i] / exp) % 10]++;
    }

    // Acumular contagens
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir o vetor de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[(V[i] / exp) % 10] - 1] = V[i];
        count[(V[i] / exp) % 10]--;
    }

    // Copiar o vetor de saída para o vetor original
    for (i = 0; i < n; i++) {
        V[i] = output[i];
    }
}
```
#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n\cdot k)$.
Onde $k$ é o comprimento médio da chave.

+ Complexidade de melhor caso: $\Theta(n+s)$. Onde $s$ é o tamanho do alfabeto.

+ É estável? `SIM`.

Em resumo, quando precisamos ordenar dados com quantidades fixas de caracteres de forma estável esse algoritmo pode ser uma escolha muito interessante.

### Bucket Sort

Princípio de funcionamento:

+ Ordena n chaves distribuídas uniformemente no intervalo [0,1].
+ Distribui as chaves em n listas (buckets).
+ Ordena as listas.
+ Concatena as listas.

#### Implementação em C


```C
// Função de ordenação por baldes
void BucketSort(float V[], int n) {
    int i;

    // Verifica se o número de elementos não excede o número máximo de baldes, que é definido por MAX_BUCKETS.
    if (n > MAX_BUCKETS) {
        printf("Número de elementos excede o número máximo de baldes permitidos.\n");
        return;
    }

    float buckets_list[MAX_BUCKETS][MAX_BUCKETS]; // Array de baldes
    int bucket_sizes[MAX_BUCKETS] = {0}; // Array para rastrear o tamanho de cada balde

    // Inicializa todos os baldes
    for (i = 0; i < MAX_BUCKETS; i++) {
        bucket_sizes[i] = 0; // Tamanho inicial de cada balde é zero
    }

    // Distribui os elementos nos baldes
    for (i = 0; i < n; i++) {
        int j = (int)(n * V[i]); // Determina o balde para o elemento V[i]
        if (j >= MAX_BUCKETS) {
            j = MAX_BUCKETS - 1; // Coloca o elemento no último balde se exceder
        }
        buckets_list[j][bucket_sizes[j]] = V[i]; // Adiciona o elemento ao balde
        bucket_sizes[j]++; // Incrementa o tamanho do balde
    }

    // Ordena os elementos dentro de cada balde
    for (i = 0; i < MAX_BUCKETS; i++) {
        if (bucket_sizes[i] > 0) { // Verifica se o balde contém elementos
            InsertionSort(buckets_list[i], bucket_sizes[i]); // Ordena o balde
        }
    }

    // Concatena os baldes em um único vetor
    int index = 0; // Índice para o vetor de saída
    for (i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            V[index++] = buckets_list[i][j]; // Copia os elementos de cada balde para V
        }
    }
}
```

#### Características do algoritmo:

+ Complexidade de pior caso: $\Theta(n^2)$.


+ Complexidade de melhor caso: $\Theta(n+k)$.

+ É estável? `SIM`.

## Limite inferior para ordenação com comparação entre chaves

Qual é a complexidade de tempo de pior caso mínima de
qualquer algoritmo de ordenação?

$Ω(n)$ é um limitante inferior para algoritmos de ordenação.

Por quê?

Porque precisamos no mínimo processar todos os elementos do vetor para garantir que ele está ordenado.

Agora estudaremos um limite inferior maior do que $Ω(n)$
para o pior caso de algoritmos de ordenação por comparação.
entre chaves.

### Árvores de decisão

Uma árvore de decisão modela todas as possíveis execuções
de um algoritmo específico de ordenação para um n fixo.

Então existe, por exemplo, uma árvore de decisão para a
ordenação por inserção para n = 3.

Vamos assumir que os elementos a serem ordenados são
distintos.

Exemplo do conceito:

![Árvore de decisão](./Imagens/Árvore%20de%20decisão%201.png)

Agora o conceito aplicado em ordenação de vetores.

Esta árvore modela o Algoritmo de Ordenação por Inserção para
n = 3:

![Árvore de decisão](./Imagens/Árvore%20de%20decisão%202.png)


+ Cada nó interno da árvore representa uma comparação.
+ As folhas da árvore representam permutações do vetor de
entrada.
+ Um caminho da raiz até uma folha representa o
comportamento de uma execução do algoritmo.
+ Quando o resultado de uma comparação é $<$ , a execução do
algoritmo segue o filho esquerdo do nó.
+ Caso contrário segue o filho direito.

### Prova

Se cada caminho da raiz até uma folha representa a execução
do algoritmo para uma das possíveis entradas, o que
representa o tempo de pior caso do algoritmo?

Vamos mostrar que qualquer árvore de decisão que representa a
execução de um algoritmo de ordenação por comparação entre
chaves tem altura de no mínimo $Ω(n\cdot log (n))$.

Os elementos de entrada estão na seguinte ordem:
a1, a2, . . . , an.

Vamos assumir que os elementos são distintos.

• Se o algoritmo ordena corretamente qualquer vetor, então
todas as permutações possíveis devem estar presentes nas
folhas das árvores. O número total de folhas deve ser de no mínimo $n!$.

Uma árvore binária de altura h tem no máximo $2^h$
folhas.

Portanto $2^h >=$ número de folhas $>= n!$

Então $h >= log_2(n!)$

Resolvendo essa expressão expandindo o faotrial chegamos no resultado que $k>\Omega(n\cdot log(n))$.


A solução segue abaixo:

![solução da equação](./Imagens/Prova%20do%20limite%20inferior.png)

### Programação Dinâmica

É uma técnica de projeto de algoritmo que pode ser aplicada quando temos um problema maior que pode ser resolvido a partir de soluções menores desse mesmo problema.

Essa situação pode gerar recursões ineficientes, que calculam muitas vezes uma mesma instância do problema.

A técnica de programação dinâmica consiste em
resolver os menores problemas primeiro e armazenar
os resultados em uma tabela (vetor ou matriz) a ser
consultada quando necessário.

#### Solução ótima

Existem algoritmos que podem vir a encontrar soluções para problemas mas não necessariamente a melhor solução.

A solução dita como `ótima` é a melhor solução devido a uma entrada em específico seguindo as regras do problema.

O valor da solução ótima pode ser descrito por relações de
recorrência.

##### Exemplo: Fibonnaci

A sequência de Fibonnaci é composta pela soma dos números `n-1` com os `n-2` partindo de um `n` atual.

A equação de recorrência é dada por:


$$
\begin{align*}

\end{align*}


$$

$$
\left\{
\begin{align*}
f(n) = f(n-1) + f(n-2)\\
f(0) = 1\\
f(1) = 1\\
\end{align*}
\right.
$$

Exemplo da árvore de recursão para $n=7$, note que o crescimento é exponencial.

Uma solução é guardarmos o que já calculamos usando a programação dinâmica.

![árvore otimizada](./Imagens/Árvore%20de%20recursão%202.png)

#### Problema da mochila

##### Definição:

Temos um conjunto de objetos S, numerados 1,2, ..., n.

O valor do objeto i é vi , para i = 1,...,n.

O peso de cada objeto é pi
 , para i = 1,..., n.

Queremos encher uma mochila, cuja capacidade de peso é B,
de forma a maximizar o valor dos objetos carregados.

Vamos denotar por opt(X, k) o valor de uma solução para o
problema da mochila, considerando os objetos no conjunto X e uma
mochila de capacidade k.

##### Versão binária

Nessa versão ou levamos o item ou deixamos ele de lado, o que buscamos e máximizar o valor dos itens dada uma capacidade.















