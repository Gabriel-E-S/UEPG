# Árvores de busca genéricas

Para saber mais sobre esse assunto veja o seguinte README:[clique aqui](https://github.com/Gabriel-E-S/UEPG/blob/main/Estrutura%20de%20Dados%20II/%C3%81rvore%20topdown/README.md).


# Árvores B

+ É uma árvore múltipla que é balanceada.

+ Os nós numa árvore criada por essa técnica, com exceção da
raiz, são, no mínimo, semicompletos (no mínimo metade dele
está preenchido) de modo que muito pouco espaço de
armazenamento é desperdiçado.

## Definição

Uma árvore múltipla balanceada de ordem `n` na qual todos nós,
exceto a raiz, contém pelo menos $\frac{(n-1)}{2}$ chaves, é chamada
árvore B de ordem n.

A definição exata varia de autor para autor.

## Inserção

+ Os dois primeiros passos para inserir são idênticos aos da
primeira técnica, ou seja, encontra-se o nó folha no qual a
nova chave se insere, e se o nó tiver espaço, insere-se a
chave nesse nó.

**OBS:** As chaves em cada nó devem ser ordenadas.

Porém, se o nó estiver cheio não é criado um novo nó a principio, e sim o nó folha é dividido em 2.

Da mesma forma se temos *n* nós, temos *n-1* chaves.

Se *n* é um número ímpar:

+ Se o nó está cheio ao inserir, os nós são dividos.
+ A chave central vira o pai e as outras chaves são divididas em 2 subárvores(esquerda e direita).
+ Ao preencher um nó folha, continua o preenchimento do nó pai.
+ Se o pai estiver cheio dividimos ele.

## Remoção

Procedimento complexo que envolve análise de todos os nós.

(Não implementamos esse método nas nossas práticas).

Consiste de 2 partes:

+ **Empréstimo**: Inicialmente, deve-se verificar se o irmão anterior ou
seguinte desse nó contém um número de chaves pelo menos uma
unidade a mais do que o valor mínimo de chaves. Nesse caso,
empresta-se uma chave desse nó irmão.

+ **Consolidação**: Se os dois irmãos estiverem com o número mínimo
de nós, então deve-se concatenar ou consolidar o nó que perdeu
uma das chaves com um de seus irmãos.

Essa técnica deve ser recursiva para atender o pai caso ele fique
sem filhos.

# Referências

Conteúdo do professor Marcos e Marcio.



