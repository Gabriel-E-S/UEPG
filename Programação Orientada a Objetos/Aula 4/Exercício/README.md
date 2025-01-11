# Sistema de Controle de Estoque

Este sistema tem como objetivo controlar o estoque de produtos, utilizando classes para representar a data e os produtos.

## Parte I - Classe Data

A classe `Data` é responsável por armazenar informações sobre a data (dia, mês e ano).

### Atributos privados

| Identificador | Tipo | Descrição |
|---------------|------|----------|
| dia           | int  | Dia do mês (1..31) |
| mes           | int  | Mês do ano (1..12) |
| ano           | int  | Ano (2024..) |

#### Métodos

- **getDia()**: Retorna o valor do atributo `dia`.
- **setDia(int dia)**: Define o valor do atributo `dia`.
- **getMes()**: Retorna o valor do atributo `mes`.
- **setMes(int mes)**: Define o valor do atributo `mes`.
- **getAno()**: Retorna o valor do atributo `ano`.
- **setAno(int ano)**: Define o valor do atributo `ano`.
- **toString()**: Retorna uma representação da data no formato `dd/mm/aaaa`.

#### Construtores

| Identificador | Retorno | Parâmetro | Descrição |
|---------------|---------|-----------|----------|
| `Data()`      | void    | dia, mês, ano | Inicia os valores dos três atributos. |
| `Data()`      | void    | dia, mês | Inicia os valores dos atributos `dia` e `mês` e considera o ano de 2024. |

## Parte II - Classe Produto

A classe `Produto` é responsável por representar os produtos no estoque. Ela possui uma relação de composição com a classe `Data`, já que cada produto possui uma data de validade.

### Atributos privados

| Identificador | Tipo   | Descrição |
|---------------|--------|----------|
| nome          | String | Nome do produto |
| preco         | double | Preço de venda do produto |
| quantidade    | int    | Quantidade do produto disponível em estoque |
| validade      | Data   | Data de validade do produto |

#### Métodos

- **getNome()**: Retorna o valor do atributo `nome`.
- **setNome(String nome)**: Define o valor do atributo `nome`.
- **getPreco()**: Retorna o valor do atributo `preco`.
- **setPreco(double preco)**: Define o valor do atributo `preco`.
- **getQuantidade()**: Retorna o valor do atributo `quantidade`.
- **setQuantidade(int quantidade)**: Define o valor do atributo `quantidade`.
- **toString()**: Retorna uma representação do produto.
- **setValidade(int dia, int mes, int ano)**: Define a validade do produto, passando os valores de `dia`, `mes` e `ano`.
- **setValidade(Data validade)**: Define a validade do produto, passando um objeto da classe `Data`.
- **vender(int qtde)**: Se houver itens suficientes no estoque, faz a venda e diminui a quantidade de produtos em estoque.
- **comprar(int qtde)**: Compra uma determinada quantidade de produtos do fornecedor.

#### Construtores

| Identificador | Retorno | Parâmetro | Descrição |
|---------------|---------|-----------|----------|
| `Produto()`   | void    | nome, qtd, preco, validade | Inicia os valores dos quatro atributos. O parâmetro `validade` é um objeto da classe `Data`. |
| `Produto()`   | void    | nome, preco, validade | Inicia os valores dos atributos `nome`, `preco` e `validade`. O parâmetro `validade` é um objeto da classe `Data`. |
| `Produto()`   | void    | nome, validade | Inicia os valores dos atributos `nome` e `validade`. O parâmetro `validade` é um objeto da classe `Data`. |

## Parte III - Classe Principal

A classe `Principal` tem como objetivo criar um vetor de produtos e incluir pelo menos dois produtos, utilizando diferentes métodos construtores.

