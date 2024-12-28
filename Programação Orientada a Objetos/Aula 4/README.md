# Aula 4

# Formas de reutilização de código

A partir de agora vamos ver formas de reaproveitar código e assim otimizar nossos programas, começando por composição

# Composição

Vamos imaginar uma classe Janela, que possui como atributo cor.

```java
public class Janela{
  private String cor; // Atributo.

  public Janela(String cor){ // Construtor.
    this.cor = cor;
  }
  // Métodos set e get.

  public void setCor(String cor){
    this.cor = cor;
  }
  public String getCor(){
    return cor;
  }
  // Outros métodos.

  public void abrir(){
    System.out.println("Tenho a cor" + cor + "e estou abrindo");
  }
  public void fechar(){
    System.out.println("Tenho a cor" + cor + "e estou fechando");
  }
}
```

Agora em seguida vamos pensar na classe Carro, que possui 4 portas, podemos usar a classe já criada para criar esses atributos.


```java
public class Carro{

  // Para usarmos a composição colocamos o nome da classe e o nome do objeto dentro da outra classe.
  private Janela janela1, janela2, janela3, janela4;

  public Carro(Janela janela1, Janela janela2, Janela janela3, Janela janela4){
    this.janela1 = janela1;
    this.janela2 = janela2;
    this.janela3 = janela3;
    this.janela4 = janela4;
  }
  // Métodos para abrir cada janela individualmente.
  public void abrirJanela1() {
    janela1.abrir();
  }

  public void abrirJanela2() {
    janela2.abrir();
  }

  public void abrirJanela3() {
    janela3.abrir();
  }

  public void abrirJanela4() {
    janela4.abrir();
  }

  // Métodos para fechar cada janela individualmente.
  public void fecharJanela1() {
    janela1.fechar();
  }

  public void fecharJanela2() {
    janela2.fechar();
  }

  public void fecharJanela3() {
    janela3.fechar();
  }

  public void fecharJanela4() {
    janela4.fechar();
  }

  // Métodos para abrir e fechar todas as janelas (opcional).
  public void abrirTodasAsJanelas() {
    System.out.println("Abrindo todas as janelas:");
    abrirJanela1();
    abrirJanela2();
    abrirJanela3();
    abrirJanela4();
  }

  public void fecharTodasAsJanelas() {
    System.out.println("Fechando todas as janelas:");
    fecharJanela1();
    fecharJanela2();
    fecharJanela3();
    fecharJanela4();
  }

}
```

O uso do verbo `ter` tem de fazer sentido quando
relacionamos as duas classes, pois uma composição implica uma relação de pertinência entre as
duas classes.
Ou seja, para sabermos se existe uma relação de composição na qual a classe A vai ser
incluída como atributo da classe B, a frase B tem A deve fazer sentido.


+ Precisamos construir métodos separados para mexer em nos objetos usando a composição.

+ **IMPORTANTE:** Ao passarmos objetos para consturores de classes na classe principal, estes são passados por referência, por isso devemos criar objetos separados para cada objeto da classe que usa a outra.

```java
public class Principal {

  public static void main(String[] args) {
    // Criação de janelas com cores diferentes.
    Janela janela1 = new Janela("Vermelha");
    Janela janela2 = new Janela("Azul");
    Janela janela3 = new Janela("Verde");
    Janela janela4 = new Janela("Amarela");

    // Criação do objeto Carro com as janelas.
    Carro carro = new Carro(janela1, janela2, janela3, janela4);

    // Abrindo as janelas individualmente.
    System.out.println("Abrindo janelas individualmente:");
    carro.abrirJanela1();
    carro.abrirJanela2();
    carro.abrirJanela3();
    carro.abrirJanela4();

    // Fechando as janelas individualmente.
    System.out.println("\nFechando janelas individualmente:");
    carro.fecharJanela1();
    carro.fecharJanela2();
    carro.fecharJanela3();
    carro.fecharJanela4();

    // Abrindo todas as janelas de uma vez.
    System.out.println("\nAbrindo todas as janelas de uma vez:");
    carro.abrirTodasAsJanelas();

    // Fechando todas as janelas de uma vez.
    System.out.println("\nFechando todas as janelas de uma vez:");
    carro.fecharTodasAsJanelas();
  }
}
```

# Referências

Material do professor Marcio.