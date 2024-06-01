# Aula 2

## Instruções para movimentações de dados

+ Load word - traz um valor que está na memória e coloca ele em um registrador definido pelo programador.

+ Store word - pega o valor que está em um registrador e guarda ele na memória.

Exemplos:

``` assembly
    lw $t0,0($s0)   # 1
    sw $t1,0($s1)   # 2
```

1- Nesse caso pegamos da memória o valor que está salvo no ponteiro de $s0, e colocamos no registrador $t0.

2- E nesse caso salvamos o contéudo de $t1 no ponteiro de $s1.

``` assembly
    lw $t0,0($s0)   # 1
    sw $t1,0($s1)   # 2
```

Exemplo de um código que soma o conteúdo das variáveis x e y e armazena em z


``` assembly
   
.data
    x: .word 5
    y: . word 7
    z: .word 0

.text
.globl main
main:

    la $s0, x
    la $s1, y
    la $s2, z

    lw $t0, 0($s0)
    lw $t1, 0($s1)

    add $t2,$t0,$t1

    sw $t2,0($s2)
```
**IMPORTANTE**-> endereços na arquitetura MIPS são alinhados, em operações de load e store só podem ser realizadas com deslocamentos múltiplos de 4.

## Vetores em Assembly

Um exemplo de vetor em c:

    int vetor[5];

como o vetor tem 5 posições seus índices irão ser de 0 até 4.



Em assembly vetores são rotulados como variáveis e ficam no segmento data do programa.

Exemplo
    .data
        x:.word 1, 2, 3, 5, 8, 13

Nesse caso a variável x representa o ínicio do vetor em memória, o segundo elemento estará no endereço de x+4 e assim por diante.

Na arquitetura MIPS temos o que é chamado de deslocamento, que é o valor que colocamos antes do ponteiro nas operações de store e load.

Exemplo:
    lw $t0, 0($s1) # deslocamento 0
    lw $t1, 4($s1) # deslocamento 4

## Setor de Dados

o comando .data mostra o início do segmentos de dados ao montador, é nessa porção de memória que as variáveis e seus identificadores ficam.

Temos 2 formatos de representações geralmente nas arquiteturas:

Considere o número em hexadecimal 0x01020304

+ Litle Endian -> O algorismo mais sinificativo fica mais a esquerda, é a representação que o MIPS usa,ficaria assim: 0x01020304.

+ Big Endian ->  algorismo mais sinificativo fica mais a direita, assim:
0x04030201.

## Movimentação de Bytes

Da mesma forma do que com words mas usamos os comandos Load Byte e Store Byte.

No caso de por exemplo

    lb $t0,3($s0)

estamos carregando da memória o 4 elemento do vetor apontado por $s0.

# Usos de contantes em instruções MIPS

podemos usar instruções com operandos imediatos, para isso colocamos i no final das instruções

    addi $t0,$t1,5










