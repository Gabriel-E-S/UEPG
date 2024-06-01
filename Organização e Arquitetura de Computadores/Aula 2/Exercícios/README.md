# Exercícios aula 2

## 4.1


**Exercício 4.1** Relacione os termos a seguir:

(1) lw  
(2) deslocamento (offset)  
(3) registrador de referência (ponteiro) para acesso à memória em loads ou stores  
(4) little endian  
(5) imediato  
(6) la (load address)  
(7) addi $t0, $t1, 32  
(8) armazenamento de 1 Byte em memória  
(9) .data  
(10) .text  

preencha as lacunas abaixo, conforme o termo acima mais adequado:

(  ) formato de representação de words em memória  
(  ) pseudo-instrução  
(  ) exemplo de instrução que usa um operando imediato  
(  ) load word  
(  ) sb $t0, 3($s2)  
(  ) Informa ao montador o início da seção de código do programa  
(  ) Valor 4 na instrução lw $t0, 4($s0)  
(  ) Informa ao montador o início da seção de dados  
(  ) O registrador $s1 na instrução sw $t5, 0($s1)  
(  ) Valor codificado na instrução de máquina como operando  


## 4.2

Preencha o programa a seguir

```assembly
.data
    x: .word 15
    y: .byte 5
    z: .word 0

.text
.globl main

main:
    # seu programa aqui
```

De forma que ao término da execução do programa, a variável z tenha como resultado a subtração do de x por y.

## 4.3

Considerando o esqueleto de programa a seguir:

``` assembly
.data
    v: .word 0,1,2,3,4,5,6
    alfa: .word 32

.text
.globl main

main:
    # seu programa aqui
```
Complete o programa de forma que as posições ímpares do vetor v recebam o valor de alfa. Não empregue laços (estruturas de repetição).

## 4.4 

Responda:

```assembly
.data
    x: .word 0x01020304

.text
.globl main

main: la $s0, x
      lb $t0, 2($s0)
```
Qual será o resultado armazenado em $t0? Use o MARS para verificar se sua resposta está correta.

## 4.5

``` assembly

.data
    w: .word 0x01020304
    alfa: .byte 24
    x: .word 0, 1, 2, 3, 4
    beta: .byte 12
    w:.word 5,6,7,8,9
```

Responda:

+ Quantos bytes são ocupados pelo segmento de dados?

+ Quantos bytes são desperdiçados (não usados pelo programa) pela restrição de alinhamento?

+ É possível modificar o programa de forma a não perder a não perder espaço em memória devido ao alinhamento?

Dica: É possível montar um programa(Assemble) mesmo que ele não tenha segmento de texto(text).
