all: matrixcalc

matrixcalc: matrixcalc.c
	 gcc matrixcalc.c -l pthread -o matrixcalc


