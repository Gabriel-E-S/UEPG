# Aula 3

## Vetores em Java

Para criarmos vetores, temos que passar por 2 etapas:

+ Declaração do vetor.
+ Criação do vetor.

### Declarando vetores

A parte de declaração é semelhante à Linguagem C, por exemplo:

``` Java
    int vetor[];
    int [] vetor2 ;
```
### Instanciando vetores

Outra característica similar é que eles **SEMPRE** começam no índice `0`.

Em Java, vetores são objetos, logo temos que instanciá-los.

Para isso usamos o comando `new` em seguida do `tipo` do vetor e seu tamanho entre `[]`.

``` Java
int vet[] = new int[5] ;
```

### Atributo length

Todo objeto que é do tipo vetor tem um atributo que define seu tamanho chamado `length` .

Por exemplo para imprimirmos um vetor de inteiro podemos usar:

```Java
for(int i=0; i < vetor.length ; i++)
    System.out.println(vetor[i]);
```

**OBS:** O atributo length define o tamanho do vetor e não o número de elementos que foram inseridos nele.

### Criando vetores com elementos

Se soubermos o número e quais elementos um vetor terá podemos declarar ele dessa forma:

``` Java
int vet[] = {1,2,3} ;
```
## Referências a objetos

Quando declaramos variáveis de objetos criamos ponteiros que começam apontando para null.

No exemplo a seguir quando declaramos *conta* e *conta1* as variáveis apontam para `null`, e só passam a referenciar um objeto quando usamos o comando `new`.


``` Java
public class Principal {
    public static void main(String args[]) {
        ContaCorrente conta, conta1;

        conta = new ContaCorrente("Fulano", 201, 1000);
        conta1 = new ContaCorrente("Sicrano", 202);
    }
}
```
Da mesma forma quando declaramos vetores de objetos estamos criando ponteiros, que passam a ter valor após a instanciação dos objetos, no caso cada elemento do vetor.

## Método toString()

O método toString() "transforma" um objeto em uma String.

Por padrão o método retorna o endereço de memória em que está o objeto. no entanto podemos sobrepor o método para outras aplicações.

Exemplos:

``` Java

public class Principal {
    public static void main(String args[]) {
        ContaCorrente conta;
        conta = new ContaCorrente("Irineu",201,1000);
        System.out.println(conta);
    }
}
```
A execução do trecho acima resultará na escrita de um endereço de memória na tela.

``` Java
public String toString() {
    String temp;
    retorno = "Nome: "+nome+"\nNúmero: "+numero+"\nSaldo: "+saldo;
    return temp;
}
```

Agora se rodarmos o mesmo código novamente o que será escrito são as informações do método toString novo.





