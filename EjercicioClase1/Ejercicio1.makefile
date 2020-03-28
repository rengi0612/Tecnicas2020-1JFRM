all: programa

programa: Ejercicio1 Main
	gcc Ejercicio1.o Main.o -o prueba2

Ejercicio1:
	gcc -c Ejercicio1.c

Main:
	gcc -c Main.c