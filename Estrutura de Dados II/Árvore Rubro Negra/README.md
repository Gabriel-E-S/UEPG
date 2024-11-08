# Árvore Rubro Negra


É um tipo de árvore balenceada, que diferente da árvore AVL pode ter níveis que superam 1 e -1

Ela possui propriedades baseadas nas cores `Rubra` e `Preta`.

Foi criada por Bayer,1972; Gibas e Sedgewick,1978.

# Definição

+ A raiz `SEMPRE` é preta.

+ Todo nó externo (folhas) é preto, e consideramos os nós vazios como sendo pretos e eles fazem
parte da árvore.

+ Se um nó é vermelho seus filhos são pretos.

+ Os caminhos de qualquer vértice até suas folhas têm o mesmo número de nós pretos.

# Inserção

Segue o mesmo princípio de uma árvore binária normal, vendo se o elemento é maior ou menor do que o nó atual.

Se o nó for a raiz, então ele assume a cor `preta`.

Caso contrário ele é `vermelho`.



