all: programa

programa: Main Ordenamiento
	gcc -o Ordenar Main.o Ordenamiento.o

Ordenamiento: Ordenamiento.c Ordenamiento.h
	gcc -c Ordenamiento.c

Main: Main.c Ordenamiento.h
	gcc -c Main.c
