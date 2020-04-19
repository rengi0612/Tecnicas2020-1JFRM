#include "Ordenamiento.h"

void menu(int * arreglo, int tam){
	int opc = 0;
	int inicio = 0;
	int final  = tam - 1;
	llenarArreglo(arreglo,tam);
	printf("Su arreglo sin ordenar es : ");
	imprimirArreglo(arreglo,tam);
	do{
		
		printf("Escoja el algoritmo con el que desea ordenar su arreglo : \n");
		printf("1. MergeSort\n");
		printf("2. Incersión\n");
		printf("-1. Salir\n");
		printf("opc : ");scanf("%d",&opc);
		switch(opc){
			case 1:
				mergeSort(arreglo,inicio,final,tam);
				printf("Su arreglo ordenado es : ");
				imprimirArreglo(arreglo,tam);
				break;
			case 2:
				incersion(arreglo,tam);
				printf("Su arreglo ordenado es : ");
				imprimirArreglo(arreglo,tam);
				break;

		}
	}while(opc!=-1);
}



int main(){
	int tam;
	printf("Bienvenido al algoritmo de ordenamiento !!!\n");
	printf("Ingrese el tamaño del arreglo : ");scanf("%d", &tam);
	int * arreglo = malloc(tam*sizeof(int));
	if (arreglo == NULL){
		printf("No se pudo reservar la memoria");
		return 0;
	}
	menu(arreglo,tam);
	
	free(arreglo);
	return 0;
}
