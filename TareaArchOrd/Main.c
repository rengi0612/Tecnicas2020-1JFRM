#include "Num_Aleatorios.h"


void menu(){
	int opc=0;
	printf("Bienvenido a la tarea de ordenamientos\n");
	do{
		printf("Ingrese la opción que desea llevar acabo\n");
		printf("1. Generar archivo de números aleatorios\n");
		printf("2. Ordenar un archivo de números aleatorios\n");
		printf("0. Salir\n");
		printf("opc : ");scanf("%d",&opc);
		switch(opc){
			case 1:
				guardarNumAlea();
				break;
			case 2:
				ordenar();
				break;
		}
	}while(opc !=0);
}




int main(){
	menu();
	return 0;
}