#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genero{
	ninguno,hombre,mujer
};
typedef enum genero genero;

struct Persona
{
	char nombre[40];
	int diaNacimiento;
	int anioNacimiento;
	genero genero;
};

struct Persona ** reservarMemoria(int fil, int col);

void ingresarUsuario (struct Persona ** pGente, int tamanios[]);

void mostrarMes (struct Persona ** pGente, int tamanios[]);

void fibonacciDia (struct Persona ** pGente, int fil, int col);

void generos (struct Persona ** pGente,int fil, int col);

