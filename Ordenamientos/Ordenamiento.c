#include "Ordenamiento.h"


void llenarArreglo(int * arreglo,int tam){
	int i;
	for (i=0;i<tam;i++){
		printf("Ingrese el valor %d del arreglo : ", i);
		scanf("%d", &arreglo[i]);
	}
}

void imprimirArreglo(int * arreglo, int tam){
	int i;
	printf("[");
	for(i=0;i<tam;i++){
		printf(" %d ", arreglo[i] );
	}
	printf("]\n");
}

void merge(int * a, int inicio, int fin,int tam){
	int mitad = (inicio + fin)/2;
	int i = inicio;
	int j = mitad + 1;
	int k = inicio;
	int temporal[tam];

	while(i<=mitad && j<=fin){
		
		if(a[i]<a[j]){
			temporal[k++] = a[i++];
		}
		else{
			temporal[k++] = a[j++];
		}
		
	}
	while(i<=mitad){
		temporal[k++] = a[i++];
		
	}
	while(j<=fin){
		temporal[k++] = a[j++];
		
	}
	
	for(i=inicio;i<=fin;i++){
		a[i] = temporal[i];
	}

}

void mergeSort(int * arreglo, int inicio, int fin, int tam){
	
	if(inicio>=fin){
		return;
	}
	int mitad = (inicio + fin)/2;
	mergeSort(arreglo,inicio,mitad,tam);
	mergeSort(arreglo,mitad + 1, fin,tam);
	merge(arreglo,inicio,fin,tam);
}

void incersion(int * arreglo, int tam){
	int i;
	int valor;
	int j;
	for(i=1;i<tam;i++){
		valor = arreglo[i];
		j = i-1;
		while(j>=0){
			if ( valor < arreglo[j]){
				arreglo[j+1] = arreglo[j];
				arreglo[j] = valor;
				j--;
			}
			else{
				break;
			}
		}
	}
}
