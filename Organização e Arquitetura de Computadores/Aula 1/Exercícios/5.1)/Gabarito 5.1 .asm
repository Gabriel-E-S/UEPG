
.data

	a: .word 2
	b: .word 5
	c: .word 5
	d: .word -1
	e: .word 0

.text

	la $s0, a	        # carregando os ponteiros das variáveis
	la $s1, b
	la $s2, c
	la $s3, d
	la $s4, e

	lw $t0, 0($s0)  	# colocando o conteúdo das variáveis nos registradores de 
	lw $t1, 0($s1)	    # $t0 a $t4
	lw $t2, 0($s2)
	lw $t3, 0($s3)
	lw $t4, 0($s4)

	add $t4, $t0, $t1   # e <- a + b
	add $t4, $t4, $t2   # e <- e + c
	add $t4, $t4, $t3   # e <- e + d

	sw $t4, 0($s4)      # salvando o resultado na memória
