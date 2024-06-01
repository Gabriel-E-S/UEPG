# Aula 2

## Objetos em Java

podemos criar um objeto em Java a partir do comando **new**.

Exemplo:

``` Java
ContaCorrente conta = new ContaCorrente();
```
Nesse exemplo **conta** é uma variável do tipo refêrencia, ou seja, ela funciona como se fosse um ponteiro para o objeto. Em outras palavras, conta contém um endereço de memória onde o objeto está localizado.

## Atributos e métodos em Java

Atributos podem de tipos primitivos ou podem referenciar uma classe. Os tipos primitivos de java são boolean, byte,short, int, long, float, double. O tamanho de um atributo (ou uma variável local) de cada um do tipos primitivos é mostrado na tabela a seguir.


| Tipo    | Tamanho               |
|---------|-----------------------|
| boolean | 1 bit                 |
| char    | 16 bits (Unicode)     |
| byte    | 8 bits                |
| short   | 16 bits               |
| int     | 32 bits               |
| long    | 64 bits               |
| float   | 32 bits               |
| double  | 64 bits               |

Métodos em Java são semelhantes a funções em C: podem receber parâmetros, retornar um valor e possuir variáveis locais que só existem durante a execução do método.

Um método pode ter como parâmetros:

+ variáveis de tipos primitivos passadas por valor.

+ objetos, que são passados por referência.

O acesso aos atributos e métodos públicos de um objeto é feito pelo nome do objeto, um ponto e o nome do componente sendo acessado.

Exemplo

    conta.sacar(valor);

Em P.O.O. os objetos interagem entre si através da execução dos métodos públicos de outros objetos. Isso é chamado de troca de mensagens.

## Encapsulamento

Nem todos os dados ou atributos de uma classe devem ser acessíveis a todos de maneira livre, o ato de esconder ou encapsular informações de uma classe é chamado de encapsulamento.

O encapsulamento é importante pois evita erros de execução e dá mais segurança ao código.

Imagine se por exemplo na classe ContaCorrente o atributo saldo fosse público, poderiam ser atribuídos valores negativos ou até mesmo o valor real poderia ser alterado.

Para evitar isso definimos os atributos como **private** (privados), quando fazemos isso só é possível modificar o valor do atributo utilizando métodos da própria classe.

Uma versão mais completa da classe ContaCorrente

```Java
    public class ContaCorrente{
        private String nome ;
        private int numero ;
        private double saldo ;

        public void setNumero(int numero) {
            if (numero>0){
                this.numero=numero;
            }
            else System.out.println("Número de conta negativo");
        }

        public int getNumero() {
            return this.numero;
        }

        public void sacar(double valor) {
            if (valor<=saldo && valor > 0){
                saldo = saldo - valor;
            }
            else System.out.println("Saldo insuficiente");
        }

        public void depositar(double valor) {
            if (valor > 0)
                saldo = saldo + valor;
            else System.out.println("Número negativo!");
        }
    }
```
De forma geral podemos chamar os métodos que modificam atributos privados de **métodos set**(ou setters ou métodos modificadores) e os que recuperam atributos privados de **métodos get**(ou getters ou métodos de acesso), No exemplo anterior o método set verifica se o atributo é negativo ou não.

## Modificadores de acesso

+ public -> acesso direto permitido por qualquer classe da aplicação.

+ private -> acesso direto apenas dentro da classe.

+ protected -> será estudado mais para a frente.

## Sobrecarga de métodos

Todo método possui uma assinatura que o diferencia de outros métodos, exemplo de assinaturas:

+ Nome
+ Quantidade de parâmetros
+ Ordem dos parâmetros
+ Tipos de parâmetros

Os métodos a seguir são diferentes

+ public void m()
+ public void m(int a)
+ public void m(float a)
+ public void m(int a, float b)
+ public void m(float, int b)

**IMPORTANTE ->** o tipo de retorno não faz parte da assinatura do método!

Quando temos diversas versões do mesmo método temos uma sobrecarga(**overload**), e dizemos que o método está sobrecarregado.

A sobrecarga permite criar métodos com nomes iguais que exigem parâmetros diferentes, isso simplifica a classe e facilita a programação.

## Construtores

São um tipo especial de método que só podem ser executados na criação do objeto, geralmente usam o conceito de overload.

Eles não possuem retorno de valor, possuem o mesmo nome da classe e geralmente são usados para inicializar os atributos.

Por exemplo na classe Conta Corrente

```Java

public class ContaCorrente {
    private String nome ;
    private int numero ;
    private double saldo ;

    public ContaCorrente(String nome, int numero, double saldo) {
        this.nome = nome ;
        this.numero = numero ;
        this.saldo = saldo ;
    }
    public ContaCorrente(String nome, int numero) {
        this.nome = nome ;
        this.numero = numero ;
    }
}
```
A palavra reservada **this** é usada para diferenciar o atributo(this.nome) do parâmetro usado no método(nome) e evitar confusões.

No caso da sobrecarga do construtor os objetos podem ser criados com qualquer um deles, e caso não tenha sido definido um construtor, Java colocará um construtor padrão automaticamente que não possui atributos.

```Java
public class Principal {
    public static void main(String args[]) {

        ContaCorrente conta, conta1;

        conta = new ContaCorrente("Fulano",21,1000);
        conta1 = new ContaCorrente("Cleiton",202);
        }
    }
```
Nesse caso foi criado um objeto com saldo de R$1000 e outro com saldo de R$0.











