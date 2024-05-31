# Exercício 2.1

 Relacione os conceitos a seguir:

1. $t0
2. add $t0, $t1, $t2
3. Busca da próxima instrução
4. 32
5. PC (Program Counter)
6. tradução
7. RISC
8. número máximo de operandos das instruções MIPS
9. Assembler
10. Assembly

**preencha** as lacunas abaixo, conforme o item acima mais adequado:

( ) armazena o endereço em memória da próxima instrução a ser executada  
( ) conversão de um programa para a linguagem de máquina  
( ) instrução com 3 operandos  
( ) etapa do ciclo de instrução  
( ) software Montador  
( ) arquitetura com um conjunto reduzido de instruções, que se opõe ao conceito de CISC  
( ) três  
( ) Linguagem de montagem  
( ) registrador  
( ) quantidade de registradores na arquitetura MIPS  

# Exercício 2.2

Converta o seguinte fragmento de programa da linguagem C para a linguagem de montagem MIPS. Considere que o conteúdo das variáveis f a j já estão disponíveis nos registradores de $t0 a $t4:

```c
    f = (g + h) - (i - j)
```

# Exercício 5.1

Converta o programa abaixo ( que está descrito na linguagem C) para o Assembly do MIPS, usando a ferramenta MARS.


```c
    int a = 2 ;
    int b = 5 ;
    int c = 5 ;
    int d = -1 ;
    int e = 0 ;

void main(){
    e = a + b + c
    e = e + d ;
}
```
