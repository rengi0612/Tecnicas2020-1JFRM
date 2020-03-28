#include "Ejercicio1.h"

void menu(struct Persona ** pGente, int fil, int col,int tamanios[]){
	int opcion=0;
	do{
		printf("Opciones\n\n");
		printf("1. Ingresar usuario\n");
		printf("2. Mostrar mes\n");
		printf("3. Fibonacci\n");
		printf("4. Género\n");
		printf("0. Salir\n\n");
		printf("Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				ingresarUsuario(pGente,tamanios);
				break;
			case 2:
				mostrarMes(pGente,tamanios);
				break;
			case 3:
				fibonacciDia(pGente,fil,col);
				break;
			case 4:
				generos(pGente,fil,col);
		}

	}while(opcion!=0);
}

int main(){
	int filas=12, columnas=5;
	int tamanios[12]={0};
	struct Persona ** pGente;
	pGente = reservarMemoria(filas,columnas);
	if(pGente!=NULL){
		//Menu que muestra las opciones disponibles
		menu(pGente,filas,columnas,tamanios);
	}else{
		printf("No se pudo reservar espacio en memoria para esta matriz");
	}
	free(pGente);
	return 0; 
}