.data

.text
.globl main
main:

	li $t1, 2			# aprenderemos depois o comando li ( Load Imediate), ele serve para 
	li $t2, 3			# colocarmos valores nos registradores de forma rápida.
	li $t3, 4
	li $t4, 5
		

	add $t5, $t1, $t2	# (g + h)
	sub $t6, $t3, $t4	# (i - j)
	sub $t0, $t5, $t6	# f = (g + h) - (i - j)