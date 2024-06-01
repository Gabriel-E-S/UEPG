.data
	v: .word 0,1,2,3,4,5,6	# seção de dados
	alfa: .word 32

.text

	la $s0, v
	la $s1, alfa # definindo os ponteiros

	lw $t0, 0($s1)	# carregando a word alfa da memória

	sw $t0,4($s0)
	sw $t0,12($s0) # substituindo e salvando os valores impares
	sw $t0,20($s0) # pegamos o indice e multiplicamos por 4