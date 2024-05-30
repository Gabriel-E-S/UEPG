# Introdução

Durante o processo da criação e construção de computadores dois tipos de arquiteturas surgiram

**RISC (Reduced instruction set computer)** Possui um número de instruções total reduzido, intruções mais complexas são resolvidas com mais de uma instrução.

A arquitetura MIPS utiliza o tipo RISC.

**CISC (Complex instruction set computer)** Possui um número de instruções total maior, nem sempre todas as suas intruções são utilizadas.

## Assembly

Aqui nessa apostila focarei mais nos conceitos voltados a Assembly.

Na arquitetura MIPS temos 32 registradores

| Registrador | Nome Alternativo | Descrição                                      |
|-------------|------------------|------------------------------------------------|
| $0          | $zero            | Sempre 0                                       |
| $1          | $at              | Assembler temporary                            |
| $2 - $3     | $v0 - $v1        | Valores de função                              |
| $4 - $7     | $a0 - $a3        | Argumentos de função                           |
| $8 - $15    | $t0 - $t7        | Temporários                                    |
| $16 - $23   | $s0 - $s7        | Preservados                                    |
| $24 - $25   | $t8 - $t9        | Temporários adicionais                         |
| $26 - $27   | $k0 - $k1        | Reservados para o sistema operacional          |
| $28         | $gp              | Global pointer                                 |
| $29         | $sp              | Stack pointer                                  |
| $30         | $fp/s8           | Frame pointer                                  |
| $31         | $ra              | Return address                                 |

E é com esses registradores que poderemos montar nossos programas, vamos começar.

Considere o seguinte trecho de código em linguagem C

``` C
    int a,b,c,d ;

    a = 1 ;
    b = 2 ;
    c = 3 ; 
    d = 4 ;

    a = b + c - d
```

Nesse caso temos a variável a recebendo o valor da expressão, em Assembly as intruções podem possuir no máximo 3 registradores, então teremos que usar mais de uma intrução para resolver esse problema.

Por ora vamos considerar que os registradores de $t0 a $t3 armazenam os valores de a a d respectivamente.

``` assembly
    add $t0,$t1,$t2
    sub $t0,$t0,$t3
```

primeiro fizemos a soma de b com c e armazenamos em a, após isso subtraimos o valor de d.


