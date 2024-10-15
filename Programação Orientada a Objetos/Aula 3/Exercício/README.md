# Sistema de Controle de Estoque

Considere um sistema muito simples de controle de estoque. Desenvolva uma classe chamada `Produto`, que contenha:

## Atributos privados

| Identificador | Tipo   | Descrição                                 |
|---------------|--------|-------------------------------------------|
| nome          | String | Nome do produto                           |
| preco         | double | Preço de venda do produto                 |
| quantidade    | Int    | Quantidade do produto disponível em estoque |

## Métodos públicos

| Identificador             | Retorno | Parâmetro            | Descrição                                                                  |
|---------------------------|---------|----------------------|----------------------------------------------------------------------------|
| `Produto` (construtor)    |         | `nome`, `qtd`, `preco` | Inicia os valores dos três atributos                                        |
| `Produto` (construtor)    |         | `nome`, `preco`      | Inicia os valores dos atributos `nome` e `preco`                          |
| `vender`                  | void    | `qtde`               | Se houver itens suficientes no estoque, faz a venda e diminui a quantidade de produtos em estoque |
| `comprar`                 | void    | `qtde`               | Compra uma determinada quantidade de produtos do fornecedor                |
| `imprimir`                | void    |                      | Imprime as informações de um produto                                       |

## Classe Principal

Desenvolva uma classe `Principal` na qual seja definido um vetor de produtos, alguns objetos sejam inseridos no vetor e os métodos sejam testados.
