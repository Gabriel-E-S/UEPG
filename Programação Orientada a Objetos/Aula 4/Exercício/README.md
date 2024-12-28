# Sistema de Cadastro de Funcionários e Alunos da Universidade

## Estrutura do Sistema
O sistema é constituído por 5 classes:
- `Data`
- `Pessoa`
- `Aluno`
- `Funcionario`
- `Principal`

---

## Classe Data
### Atributos Privados
| Identificador | Tipo | Descrição                  |
|---------------|------|----------------------------|
| `dia`         | `int`| Dia do mês (1..31)         |
| `mes`         | `int`| Mês do ano (1..12)         |
| `ano`         | `int`| Ano (1950..)               |

### Regras
Para simplificar o programa, considere que todos os meses têm 31 dias.

### Métodos
- Métodos `get` e `set` para todos os atributos.
- Método `toString()`.
- Método construtor com 3 parâmetros: `dia`, `mês` e `ano`.

---

## Classe Pessoa
### Atributos Privados
| Identificador | Tipo     | Descrição                       |
|---------------|----------|---------------------------------|
| `nome`        | `String` | Nome da pessoa                 |
| `telefone`    | `String` | Telefone da pessoa             |
| `nascimento`  | `Data`   | Data de nascimento da pessoa   |

### Métodos
- Métodos `get` e `set` para os atributos `nome` e `telefone`.
- Método `toString()`.

#### Métodos Públicos
| Identificador   | Retorno | Parâmetros            | Descrição                                                                 |
|-----------------|---------|-----------------------|---------------------------------------------------------------------------|
| `Pessoa`        |         | Nome, telefone, data de nascimento | Inicia os valores dos três atributos. O parâmetro data de nascimento é um objeto da classe `Data`. |
| `Pessoa`        |         | Nome, data de nascimento | Inicia os valores dos atributos `nome` e `nascimento`. O parâmetro data de nascimento é um objeto da classe `Data`. |
| `setNascimento` | `void`  | Data de nascimento    | Define o valor da data de nascimento passando como parâmetro um objeto da classe `Data`. |

---

## Classe Aluno (estende a classe Pessoa)
### Atributos Privados
| Identificador | Tipo     | Descrição     |
|---------------|----------|---------------|
| `ra`          | `String` | RA do aluno   |

### Métodos
- Métodos `get` e `set` para o atributo `ra`.
- Método `toString()`.

#### Construtores
| Identificador | Retorno | Parâmetros                                   | Descrição                                                                 |
|---------------|---------|---------------------------------------------|---------------------------------------------------------------------------|
| `Aluno`       |         | Nome, telefone, data de nascimento, RA      | Inicia os valores dos quatro atributos. O parâmetro data de nascimento é um objeto da classe `Data`. |
| `Aluno`       |         | Nome, data de nascimento, RA                | Inicia os valores dos atributos `nome`, `nascimento` e `ra`. O parâmetro data de nascimento é um objeto da classe `Data`. |

---

## Classe Funcionario (estende a classe Pessoa)
### Atributos Privados
| Identificador | Tipo     | Descrição                        |
|---------------|----------|----------------------------------|
| `registro`    | `String` | Registro profissional do funcionário |
| `salario`     | `double` | Salário do funcionário           |

### Métodos
- Métodos `get` e `set` para os atributos `registro` e `salario`.
- Método `toString()`.

#### Construtores
| Identificador  | Retorno | Parâmetros                                            | Descrição                                                                 |
|----------------|---------|-----------------------------------------------------|---------------------------------------------------------------------------|
| `Funcionario`  |         | Nome, telefone, data de nascimento, registro, salário | Inicia os valores dos cinco atributos. O parâmetro data de nascimento é um objeto da classe `Data`. |
| `Funcionario`  |         | Nome, data de nascimento, registro, salário          | Inicia os valores dos atributos `nome`, `nascimento`, `registro` e `salario`. O parâmetro data de nascimento é um objeto da classe `Data`. |

#### Método Específico
| Identificador | Retorno  | Descrição                                      |
|---------------|----------|------------------------------------------------|
| `bonificar`   | `double` | Retorna a bonificação de um funcionário, que equivale a 10% do salário básico. |

---

## Classe Chefe (estende a classe Funcionario)
### Atributos Privados
| Identificador | Tipo     | Descrição                        |
|---------------|----------|----------------------------------|
| `cargo`       | `String` | Cargo de chefia do funcionário  |

### Métodos
- Métodos `get` e `set` para o atributo `cargo`.
- Método `toString()`.

#### Construtores
| Identificador | Retorno | Parâmetros                                                   | Descrição                                                                 |
|---------------|---------|-----------------------------------------------------------|---------------------------------------------------------------------------|
| `Chefe`       |         | Nome, telefone, data de nascimento, registro, salário, cargo | Inicia os valores dos seis atributos. O parâmetro data de nascimento é um objeto da classe `Data`. |
| `Chefe`       |         | Nome, data de nascimento, registro, salário, cargo          | Inicia os valores dos atributos `nome`, `nascimento`, `registro`, `salario` e `cargo`. O parâmetro data de nascimento é um objeto da classe `Data`. |

#### Método Específico
| Identificador | Retorno  | Descrição                                      |
|---------------|----------|------------------------------------------------|
| `bonificar`   | `double` | Retorna a bonificação de um funcionário, que equivale a 20% do salário básico. |

---

## Classe Principal
Desenvolver uma classe `Principal`, na qual sejam criados `Aluno`, `Funcionario` e `Chefe`, e sejam impressas as informações deles, incluindo:
- Salário.
- Bonificações para funcionários e chefes.
