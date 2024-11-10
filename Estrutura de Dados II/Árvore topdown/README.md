# Árvores genéricas de busca

Podemos usar árvores que não são binárias para buscar elementos, elas são chamadas
árvores genéricas de busca, podendo ser de dois tipos:

+ Árvores múltiplas.
+ Árvores digitais.

# Conceito

Relembrando o  conceito da árvore binária, onde cada nó aponta para dois
nós (direta e esquerda) onde as chaves menores ficam a
esquerda e chaves maiores a direita.

Pode-se estender esse conceito para árvores genéricas, nas
quais cada nó contém uma ou mais chaves.

Uma árvore múltipla de ordem n é uma árvore que em cada nó tem n ou menos subárvores.

Com isso o número de chaves é igual a `n-1`.

Exemplo: Se um nó tiver 4 subárvores, ele terá 3 chaves.

Dito isso, se as chaves de cada nó estiverem ordenadas de forma crescente podemos afirmar:

Chamando as subárvores de $s_1,s_2,s_3...s_n$ forem as n subárvores de um nó com as chaves
$c_1,c_2,c_3,...,c_{n-1}$

Todas as chaves da subárvore $s_1$ serão menores que $c_1$, todas as chaves na subárvore $s_i$ (onde $2 ≤ i ≤ n-1$) serão maiores ou iguais a
$c_{i-1}$ e menores que $c_i$, e todas as chaves na subárvore $s_n$ serão
maiores ou iguais a $c_{n-1}$.

## Definições

+ **Nó completo:** Aquele que contém o número máximo de chaves.
+ **Semifolha:** Nó com pelo menos uma subárvore vazia.
+ **Folha:** Nó com `todas` as subárvores vazias.
+ **Balanceamento:** Uma árvore múltipla está balanceada quando todas as
semifolhas encontram-se no mesmo nível, ou seja, todas as
semifolhas são folhas, e todas as subárvores vazias estão no
último nível.

## Implementações

Em uma árvore múltipla de ordem n, geralmente,
implementam-se os nós como vetores que possuem n-1 chaves
e n ponteiros para as n subárvores.

Essa estratégia é possível porque em árvores múltiplas existe
um limite para a quantidade de filhos de um nó, e podemos
esperar que a maioria dos nós seja a mais completa possível.


### Busca

Precisamos saber o número de chaves do nó, seus filhos e a raiz da árvore.

```C
// Procedimento que está fazendo a busca.
void busca(int chave){

    struct no *aux = raiz ;
    int i;

    while(aux != NULL){
        i = encontra_chave(aux,chave);
        if(i<aux->n_chaves && aux->dado[i] == chave){
            printf("encontrei o numero %d\n",chave);
            return ;
        }
        aux = aux->filhos[i] ;
    }
    printf("n achei %d\n",chave);

}
```

E a função encontra_chave:

```C 
// Encontra uma chave no nó apontado por atual e retorna a posição dela no nó
int encontra_chave(struct no *atual, int chave) {
    int i = 0;
    while (i < atual->n_chaves && chave > atual->dado[i])
        i++;
    return i;
}
```

### Percurso

Procedimento que implementa um percurso:

```C
void emordem(struct no *atual){

    int i;

    if(raiz == NULL){
        printf("ÁRVORE VAZIA!\n");
        return ;
    }

    if(atual != NULL){
        i = 0 ;
        int nc = atual->n_chaves ;
        while(i<nc){
            emordem(atual->filhos[i]);
            printf("%d ",atual->dado[i]);
            i++ ;
        }
        emordem(atual->filhos[nc]);
    }

}
```

# Árvore Top Down

A primeira é análoga a técnica de inserção em árvores binárias de
busca, e gera árvores não balanceadas também chamadas de
árvores top-down, inserções devem sempre ser feitas em nós folha.

## Inserção

+ Encontra-se o nó folha no qual a nova chave se insere.

+ Se esse nó folha possuir espaço, a nova chave é inserida
nesse nó.

+ Se o nó folha estiver completo, é criado um nó (contendo
apenas a nova chave) e ele é inserido na posição
correspondente na árvore.

