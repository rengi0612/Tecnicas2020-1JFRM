all : program

program : Main Num_Aleatorios
	gcc -o prueba Main.o Num_Aleatorios.o

Num_Aleatorios : Num_Aleatorios.c Num_Aleatorios.h
	gcc -c Num_Aleatorios.c

Main: Main.c Num_Aleatorios.h
	gcc -c Main.c
	