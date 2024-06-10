# Revisão para a prova.

## Classes Abstratas

Uma classe abstrata é uma classe que não pode ser instanciada diretamente e serve como uma base para outras classes. Ela pode conter métodos abstratos e métodos concretos(métodos normais).

### Definição e Sintaxe:

Uma classe abstrata é declarada com a palavra-chave **abstract**.
Pode conter métodos abstratos (sem implementação) que devem ser implementados pelas subclasses.
Pode também conter métodos concretos (com implementação).

### Métodos Abstratos:

Métodos declarados com a palavra-chave abstract dentro de uma classe abstrata.
Não possuem corpo (implementação) e são terminados com um ponto e vírgula.
Subclasses concretas devem fornecer implementações para todos os métodos abstratos.

### Herança:

Uma classe abstrata pode ser herdada por outras classes.
A primeira classe concreta que herda a classe abstrata deve implementar todos os métodos abstratos da classe abstrata.

### Objetivo:

Serve como um esqueleto para subclasses, definindo um contrato que as subclasses devem seguir.
Facilita a reutilização de código e promove uma maior organização e estrutura no desenvolvimento de software.
Exemplo de Classe Abstrata:

Exemplo

```Java

public abstract class Animal {

    public void dormir(){
        System.out.println("O animal está a mimir ") ;
    }
    public abstract void fazerBarulho();
}

```

Nessa classe abstrata o método dormir foi implementado de maneira concreta e o método fazerBarulho de forma abstrata, logo as classes que estenderem Animal terão que implementar esse método **obrigatoriamente**.

```Java
public class Gato extends Animal {

    public void fazerBarulho(){
        System.out.println("Meoww") ;
    }

    public void subirNasCoisas(){
        //...
        //exemplo de método extra...
    }
}
```

Na classe Gato implementamos o método fazerBarulho() e podemos adicionar outros métodos e atributos normalmente.

``` Java

public class Principal{
    public static void main(String args[]){
        Gato meuGato = new Gato();

        meuGato.fazerBarulho() // saída: Meow
        meuGato.dormir(); // saída: O animal está a mimir .
    }
}
```

Na classe Principal é criado um objeto do tipo Gato e em seguida realizados os métodos fazerBarulho() e dormir().

## Herança

herança é um conceito fundamental da programação orientada a objetos que permite que uma classe (subclasse ou classe derivada) herde atributos e métodos de outra classe (superclasse ou classe base). A herança promove a reutilização de código e estabelece uma hierarquia entre classes.

Principais Pontos sobre Herança em Java:

### Definição e Sintaxe:

Usa-se a palavra-chave **extends** para indicar que uma classe herda de outra.
A classe que herda é chamada de subclasse, e a classe da qual ela herda é chamada de superclasse.

### Atributos e Métodos:

A subclasse herda todos os atributos e métodos da superclasse, mas pode adicionar seus próprios atributos e métodos ou sobrescrever (override) métodos da superclasse.

### Construtores:

Construtores não são herdados, mas a subclasse pode chamar o construtor da superclasse usando a palavra-chave **super**.

**OBS:** podemos acessar os contrutores e qualquer outro método da superclasse usando a palavra **super**.

### Polimorfismo:

A herança permite que objetos de subclasses sejam tratados como objetos de suas superclasses, promovendo o uso de polimorfismo.

### Exemplo de Herança:

Vamos usar um exemplo parecido com o anterior com a difereça do usa da herança enfatizando o polimorfismo.

``` Java
// Superclasse
public class Animal {

    private double tamanho;
    private int idade ;
    private String nome ;

    public void fazerSom() {
        System.out.println("O animal faz um som.");
    }
}
```
A subclasse herda todos os métodos e atributos de Animal

``` Java
// Subclasse / classe herdeira
public class Cachorro extends Animal {
    // Sobrescrevendo o método fazerSom
    public void fazerSom() {
        System.out.println("O cachorro faz: Au Au");
    }
    public void correr() {
        System.out.println("O cachorro está correndo.");
    }
}
```
``` Java
public class Principal {
    public static void main(String[] args) {
        Animal meuAnimal = new Animal();
        meuAnimal.fazerSom(); // Saída: O animal faz um som.

        Cachorro meuCachorro = new Cachorro();
        meuCachorro.fazerSom(); // Saída: O cachorro faz: Au Au
        meuCachorro.correr();   // Saída: O cachorro está correndo.

        meuCachorro.nome = "Leão" ; // essa linha não compila pois os atributos foram definidos como private.

        // Polimorfismo
        Animal animalPolimorfico = new Cachorro();
        animalPolimorfico.fazerSom(); // Saída: O cachorro faz: Au Au.

        animalPolimorfico.correr();
        // Não compila, pois Animal não tem o método correr.
    }
}

```

## Pacotes e atributos protegidos

### Pacotes

Em Java, pacotes (packages) são usados para organizar classes e interfaces em pastas e locais específicos, fornecendo uma estrutura hierárquica que facilita a modularização e a gestão de grandes projetos. Os pacotes ajudam a evitar conflitos de nomes e permitem um melhor controle sobre a visibilidade das classes e seus membros.

Principais Pontos sobre Pacotes:

#### Declaração:

A primeira linha de código de um arquivo Java deve ser a declaração do pacote, se o arquivo pertence a um pacote específico.

``` Java
package com.exemplo.meupacote;
```
#### Importação:

Para usar classes de outros pacotes, é necessário importá-las.

``` Java
import com.exemplo.outropacote.MinhaClasse;
```

#### Pacote Padrão:

Se nenhuma declaração de pacote for fornecida, a classe é considerada parte do pacote padrão (default package). Esse pacote considera arquivos que estão em uma mesma pasta.

#### Organização:

Os pacotes ajudam a organizar o código fonte de maneira lógica e ordenada.

Geralmente, os pacotes seguem a convenção de nomenclatura baseada em domínios invertidos (por exemplo, br.com.uepg.deinfo).

#### Exemplo de Uso de Pacotes:

``` Java

package br.com.deinfo;

public class Animal {
    protected void fazerSom() {
        System.out.println("O animal faz um som.");
    }
}
```

``` Java
package br.com.deinfo;

public class Cachorro extends Animal {

    protected void fazerSom() {
        System.out.println("O cachorro faz: Au Au");
    }
    public void correr() {
        System.out.println("O cachorro está correndo.");
    }
}
```
``` Java
import br.com.deinfo.Cachorro;

public class Main {
    public static void main(String[] args) {
        Cachorro meuCachorro = new Cachorro();

        meuCachorro.correr(); // Saída: O cachorro está correndo.
        meuCachorro.fazerSom();
         //Esse método gera um erro de compilação, pois o método fazerSom() foi definido como protected, logo não pode ser acessado por uma classe que está fora do pacote.
    }
}
```

### Atributos Protected

Atributos protegidos (protected) em Java são membros de uma classe (variáveis ou métodos) que podem ser acessados dentro da própria classe, e por outras classes no mesmo pacote.

Principais Pontos sobre Atributos Protegidos:

#### Visibilidade:

+ Mesma Classe: Atributos protegidos são acessíveis.

+ Mesmo Pacote: Atributos protegidos são acessíveis.

+ Outros Pacotes: Atributos protegidos não são acessíveis para classes não relacionadas.


#### Modificador protected:

Utilizado para declarar um membro da classe como protegido.

## Interfaces

Em Java, uma interface é um "contrato" que define um conjunto de métodos que uma classe deve implementar. As interfaces fornecem uma forma de garantir que diferentes classes tenham métodos específicos com assinaturas idênticas, permitindo a interoperabilidade e a flexibilidade no design de software.

Principais Pontos sobre Interfaces:

### Definição e Sintaxe:

Uma interface é declarada com a palavra-chave **interface**.

Métodos em uma interface são implicitamente públicos e abstratos, não contendo implementações.

### Implementação:

Uma classe implementa uma interface usando a palavra-chave **implements**.

Uma classe pode implementar várias interfaces, promovendo a utilização do polimorfismo e a composição de comportamentos.

### Constantes:

Interfaces podem declarar constantes (variáveis static final), que são implicitamente públicas.

### Benefícios das Interfaces:

+ Polimorfismo: Permitem que objetos sejam tratados de forma intercambiável, baseando-se nas interfaces que implementam, não na classe específica.

+ Desacoplamento: Promovem o desacoplamento de código, permitindo que a implementação possa ser alterada sem afetar o código cliente.

+ Herança Múltipla: Java não suporta herança múltipla de classes, mas permite que uma classe implemente múltiplas interfaces, alcançando um efeito similar.

### Exemplo de Interface:

Definição da interface

``` Java

public interface Animal {
    void fazerSom(); // Método abstrato e público.
    void dormir(); // Método abstrato e público.
}
```

Implementação da interface na classe Cachorro

``` Java

public class Cachorro implements Animal {

    public void fazerSom() {
        System.out.println("O cachorro faz: Au Au");
    }

    public void dormir() {
        System.out.println("O cachorro está dormindo.");
    }
}
```
Implementação da interface na classe Gato
``` Java
public class Gato implements Animal {

    public void fazerSom() {
        System.out.println("O gato faz: Miau");
    }

    public void dormir() {
        System.out.println("O gato está dormindo.");
    }
}
```

Classe principal para testarmos:

``` Java

public class Main {
    public static void main(String[] args) {
        Animal meuCachorro = new Cachorro();
        Animal meuGato = new Gato();

        meuCachorro.fazerSom(); // Saída: O cachorro faz: Au Au
        meuCachorro.dormir();   // Saída: O cachorro está dormindo.

        meuGato.fazerSom(); // Saída: O gato faz: Miau
        meuGato.dormir();   // Saída: O gato está dormindo.
    }
}
```


## Exceções

Exceções em Java são eventos que ocorrem durante a execução de um programa que interrompem o fluxo normal das instruções. Elas representam situações excepcionais ou erros que um programa pode encontrar. O mecanismo de tratamento de exceções em Java permite que o programa lide com esses eventos de forma organizada e previsível.

Principais Conceitos:

### Hierarquia de Exceções:

Todas as exceções são derivadas da classe **Throwable**.

Throwable tem duas subclasses principais: Error e Exception.

+ Error: Representa erros graves que geralmente não podem ser recuperados pelo programa (por exemplo, OutOfMemoryError).

+ Exception: Representa condições que um programa pode querer capturar e tratar (por exemplo, IOException).

### Tipos de Exceções:

#### Exceções Verificadas (Checked Exceptions):

São verificadas pelo compilador em tempo de compilação.
Devem ser capturadas ou declaradas na assinatura do método usando throws.

A linguagem Java força o desenvolvedor a lidar com essas exceções explicitamente.

Exemplo comum: Interações com o sistema de arquivos, acesso a bancos de dados, operações de entrada/saída.

``` Java
public void metodoComExcecao() throws IOException {
    // Código que pode lançar IOException
}
```
Exemplo: IOException, SQLException.

#### Exceções Não Verificadas (Unchecked Exceptions):

Não são verificadas pelo compilador.
Incluem RuntimeException e suas subclasses.

Representam erros de programação que geralmente podem ser evitados com verificações adequadas (por exemplo, acesso a índices inválidos de um array, operações ilegais com null).
Não é necessário capturá-las ou declará-las com throws, embora possam ser tratadas explicitamente.

``` Java
public void metodoComExcecaoNaoVerificada() {
    int[] array = new int[5];
    int valor = array[10]; // Lança ArrayIndexOutOfBoundsException
}
```

Exemplo: NullPointerException, ArrayIndexOutOfBoundsException.

### Mecanismo de Tratamento de Exceções:

+ try: Bloco de código onde as exceções são monitoradas.

+ catch: Bloco que captura e trata a exceção.

+ finally: Bloco opcional que executa código, independentemente de uma exceção ter sido lançada ou não.

+ throw: Usado para lançar uma exceção explicitamente.

+ throws: Declarado na assinatura do método para indicar que o método pode lançar exceções.

``` Java
public class ExemploUncheckedException {
    public static void main(String[] args) {
        try {
            dividir(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }

    public static void dividir(int a, int b) {
        int resultado = a / b;
        System.out.println("Resultado: " + resultado);
    }
}
```
## Casting

Casting de classes em Java refere-se ao processo de converter um objeto de um tipo de dado para outro. Isso é particularmente útil em situações de herança e polimorfismo, onde você pode querer tratar um objeto de uma classe derivada como um objeto de sua classe base, ou vice-versa.

### Tipos de Casting de Classes:

#### Upcasting:

É o processo de converter um objeto de uma subclasse para um objeto de uma superclasse.
Sempre seguro e não necessita de um operador de casting explícito.

Exemplo: Converter um objeto Cachorro para um objeto Animal.

#### Downcasting:

É o processo de converter um objeto de uma superclasse para um objeto de uma subclasse.

Pode lançar uma ClassCastException se o objeto não for realmente uma instância da subclasse.

Necessita de um operador de casting explícito.

Exemplo: Converter um objeto Animal para um objeto Cachorro.

### Exemplo Prático de Upcasting e Downcasting:

Definindo as classes para o exemplo:

``` Java
public class Animal {
    public void fazerSom() {
        System.out.println("O animal faz um som.");
    }
}
```
``` Java

public class Cachorro extends Animal {

    public void fazerSom() {
        System.out.println("O cachorro faz: Au Au");
    }

    public void correr() {
        System.out.println("O cachorro está correndo.");
    }
}
```
Upcasting

``` Java
public class ExemploUpcasting {
    public static void main(String[] args) {
        Cachorro meuCachorro = new Cachorro();
        Animal meuAnimal = meuCachorro; // Upcasting implícito

        meuAnimal.fazerSom(); // Saída: O cachorro faz: Au Au
        // meuAnimal.correr(); // Erro de compilação: Animal não tem o método correr
    }
}
```
Downcasting

``` Java
public class ExemploDowncasting {
    public static void main(String[] args) {
        Animal meuAnimal = new Cachorro(); // Upcasting implícito
        Cachorro meuCachorro = (Cachorro) meuAnimal; // Downcasting explícito

        meuCachorro.fazerSom(); // Saída: O cachorro faz: Au Au
        meuCachorro.correr();   // Saída: O cachorro está correndo.
    }
}
```
## Entrada e Saída de dados (E/S)

Em Java, a entrada e saída de dados (I/O - Input/Output) são operações fundamentais que permitem a interação com o ambiente externo, como ler dados de um arquivo, escrever dados em um arquivo, ou ler a entrada do usuário a partir do console. A biblioteca padrão de Java fornece várias classes e métodos para facilitar essas operações, localizadas principalmente no pacote java.io e java.nio.

Conceitos Básicos

### Entrada de Dados (Input):

Refere-se à leitura de dados de uma fonte externa, como arquivos, teclado, ou rede.
Classes principais incluem InputStream, Reader, BufferedReader, entre outras.

### Saída de Dados (Output):

Refere-se à gravação de dados em um destino externo, como arquivos, console, ou rede.

Classes principais incluem OutputStream, Writer, BufferedWriter, entre outras.
Classes Utilizadas para I/O

InputStream e OutputStream
Estas classes são usadas para operações de entrada e saída de bytes.

InputStream: Classe abstrata para leitura de dados byte a byte.

Subclasses: FileInputStream, BufferedInputStream, DataInputStream.

OutputStream: Classe abstrata para escrita de dados byte a byte.

Subclasses: FileOutputStream, BufferedOutputStream, DataOutputStream.

### Diferenças Entre Byte Streams e Character Streams

#### Byte Streams (InputStream e OutputStream):

Manipulam dados binários (bytes).
Úteis para manipulação de arquivos binários, como imagens, vídeos, e outros dados que não são texto.

Menos eficiente para manipulação de texto devido à falta de tratamento direto de caracteres.

#### Character Streams (Reader e Writer):

Manipulam dados de texto (caracteres).
Facilmente integrados com sistemas de codificação de caracteres (por exemplo, UTF-8).
Mais eficientes e convenientes para leitura e escrita de texto.

Entrada e Saída Padrão
Entrada Padrão (Standard Input):
Normalmente é o teclado.

Utiliza a classe Scanner para ler dados do console.

Exemplo de leitura usando Scanner:

``` Java
import java.util.Scanner;

public class StandardInputExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite seu nome: ");
        String nome = scanner.nextLine();
        System.out.println("Olá, " + nome + "!");
    }
}
``` 

### Saída Padrão (Standard Output):

Normalmente é o console.

Utiliza a classe System.out para imprimir dados no console.

Exemplo de Escrita com System.out:

```Java
public class StandardOutputExample {
    public static void main(String[] args) {
        System.out.println("Olá, Mundo!");
    }
}
```