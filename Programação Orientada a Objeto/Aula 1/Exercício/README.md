# Exercício 1

Considere um sistema muito simples de controle bancário. Desenvolva uma classe
chamada ContaCorrente, que contenha:

## Atributos privados:

| Identificador |  Tipo    | Descrição      | 
|---------------|----------|----------------|
| saldo         |  double  | Saldo da conta |

## Atributos públicos

| Identificador |  Tipo    | Descrição         |
|---------------|----------|-------------------|
| nome          |  String  | Nome do cliente   |
| numero        |  int     | Número da conta   |
| agencia       |  int     | Número da agência |


## Métodos

| Identificador | Retorno | Parâmetro                     | Descrição                                                                 |
|---------------|---------|-------------------------------|--------------------------------------------------------------------------|
| sacar         | void    | valor: valor a ser sacado     | Se houver saldo e for um número positivo, saca um valor da conta         |
| depositar     | void    | valor: valor a ser depositado | Se for um número positivo, deposita um valor na conta                    |
| imprimir      | void    |                               | Imprime todas as informações da conta                                    |



## Objetivo

Desenvolva uma classe Principal, na qual sejam criadas duas contas correntes, preencha
o atributo das contas criadas, faça saques e depósitos e imprima informações sobre as contas.