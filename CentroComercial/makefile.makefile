all: programa

programa: FuncionesCC Main
	gcc -o Parcial2 FuncionesCC.o Main.o 

FuncionesCC: FuncionesCC.c FuncionesCC.h
	gcc -c FuncionesCC.c

Main: Main.c FuncionesCC.h
	gcc -c Main.c