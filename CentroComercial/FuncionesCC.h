#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum estado{
	ocupado,libre
};
typedef enum estado estado;

enum categoria{
	ropa, comida, entretenimiento,sinAsignar 
};
typedef enum categoria categoria;

typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numxLocal;//Columnas
	estado estado; 
	categoria categoria;
	int precioLocal;
	// Completelo con lo que quiera
} local_t;


local_t ** crearCentroComercial(int pisos, int locales);
	

/*Agregar las funciones que necesite para satisfacer los requerimientos */

void ingresarNuevoLocal(local_t ** pCentroComercial, int pisos, int locales);

void mostrarCentro(local_t ** pCentroComercial, int pisos, int locales);

void mostrarCategorias(local_t ** pCentroComercial, int pisos, int locales);

void mostrarLocal(local_t ** pCentroComercial, int pisos, int locales);

void modificarLocal(local_t ** pCentroComercial, int pisos, int locales);

void eliminarLocal(local_t ** pCentroComercial, int pisos, int locales);

void buscarLocalPrecio(local_t ** pCentroComercial, int pisos, int locales);

#endif /* FUNCIONESCC_H_ */