# Aula 5

# Polimorfismo

Capacidade de referenciar um objeto de maneiras diferentes, por exemplo vamos considerar a seguinte classe que soma bonificações de funcionários de uma empresa:

```java
public class ControleDeBonificacoes{

  private double totalBonificacoes;

  public void somar(Funcionario funcionario){
    totalBonificacoes = totalBonificacoes + funcionario.bonificar();
  }
  public double getTotalBonificacoes{
    return totalBonificacoes;
  }
}
```

O seguinte código é válido:

```java
public class Principal {
  public static void main(String args[]){

    Funcionario f = new Funcionario("Fulano","123.456.789-00",100);

    Chefe c = new Chefe("Sicrano","098.765.432-10",100,"RH");

    ControleDeBonificacoes controle = new ControleDeBonificacoes();

    controle.somar(f);
    controle.somar(c);
    System.out.println(controle.getTotalBonificacoes());
  }
}

```
+ Por mais que o parâmetro do método `somar` que criamos peça um objeto da classe funcionário, podemos executar o método passando um objeto da classe Chefe, pois um Chefe é um tipo de Funcionário, e podemos referenciar ele assim. 

+ Ou seja, polimorfismo é quando podemos fazer um método enxergar um objeto de classes dais quais ele foi criado por herança como se fosse da classe base.

+ Mas o objeto em si continua sendo um objeto da classe Chefe, apenas a referência é
feita de maneira diferente. Um objeto carrega consigo todos os seus métodos, e esses serão
executados independente da referência. Por exemplo, mesmo que no método somar() o objeto
da classe Chefe seja referenciado como um Funcionario, o método bonificar() (linha 5 da classe
ControleBonificacoes) executado será o definido na classe Chefe.

## Uso em vetores

+ Podemos usar esse conceito também em vetores, seguindo om mesmo exemplo, podemos ter um vetor de Funcionario e incluir um objeto da classe Chefe nele.

Exemplo:

```java

public class Principal {
  public static void main(String args[]) {

    Funcionario vetor[] = new Funcionario[2];

    vetor[0] = new Funcionario("Fulano","123.456.789-00",100);

    vetor[1] = new Chefe("Sicrano","098.765.432-10",100,"RH");

    ControlaBonificacoes controle = new ControlaBonificacoes();

    for (int i=0; i<vetor.length; i++) // OBS: todo vetor em Java tem o atributo .length, que informa o tamanho do vetor.

    controle.somar(vetor[i]);

    System.out.println(controle.getTotalBonificacoes());
  }
}
```

+ Alguns autores condenam usar muita herança pois aumenta a dependência entre classes, por ouro lado,
polimorfismo é uma prática bem recomendada.


# Referências

+ Material do professor Marcio.

