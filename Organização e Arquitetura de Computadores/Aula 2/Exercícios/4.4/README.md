# Gabarito 4.4

.data
	x: . word 0x01020304

.text

	la $s0, x
	lb $t0, 2($s0)


-- RESULTADO $t0 <- 02
