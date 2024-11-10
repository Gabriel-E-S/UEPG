# Árvore Rubro Negra


É um tipo de árvore balenceada, que diferente da árvore AVL pode ter níveis que superam 1 e -1

Ela possui propriedades baseadas nas cores `Rubra` e `Preta`.

Foi criada por Bayer,1972; Gibas e Sedgewick,1978.

# Definição

1. A raiz `SEMPRE` é preta.
2. Todo nó externo (folhas) é preto, e consideramos os nós vazios como sendo pretos e eles fazem
parte da árvore.
3. Se um nó é vermelho seus filhos são pretos.
4. Os caminhos de qualquer vértice até suas folhas têm o mesmo número de nós pretos.

# Inserção

Segue o mesmo princípio de uma árvore binária normal, vendo se o elemento é maior ou menor do que o nó atual.

Se o nó for a raiz, então ele assume a cor `preta`.

Caso contrário ele é `vermelho`.

Só isso já garante os itens 1,2 e 4 da árvore RN.

## Para satisfazer o item 3:

Se o pai for preto não há problema, caso contrário precisamos avaliar o tio e o avô.

Supondo que o novo nó seja *n*, o pai *p*, tio *t*, e vô *v*.

Assumindo que *p* é vermelho
Possuímos 2 casos:

### Caso 1: o nó tio também é vermelho

Neste caso, trocam-se as cores de t e p para preto e de v para
vermelho (a menos que v seja a raiz, caso em que será
colorido de preto).

Entretanto, é possível que o problema do vermelho duplo
reapareça, pois v pode ter o pai vermelho.

Nesta situação, repete-se a troca de cores em relação à v.
Consequentemente, a troca de cores pode se propagar até a raiz da
árvore

### Caso 2: o nó tio é preto

+ Se n é filho esquerdo de um pai esquerdo em relação ao seu avô: Rotação simples para a direita.
+ Se n é filho direito de um pai direito em relação ao seu avô: Rotação simples para a esquerda.
+ Se n é filho direito de um p esquerdo em relação ao seu avô: Rotação dupla esquerda e direita. 
+ Se n é filho esquerdo de um p direito em relação ao seu avô: Rotação dupla direita e esquerda.

As rotações funcionam da mesma forma do que em uma árvore AVL.




