.data
	x: .word 15
	y: .byte 5 	# seção de dados
	z: .word 0 

.text

	la $s0, x 	# carregando os ponteiros das variáveis x e y
	la $s1 , y

	lw $t0, 0($s0)	# carregando a word x na memória
	lb $t1, 0($s1)  # carregando o byte y na memória

	sub $t2, $t0, $t1 # fazendo as contas

	la $s2, z # carregando um ponteiro para z
	sw $t2,0($s2)	# guardando o resultado