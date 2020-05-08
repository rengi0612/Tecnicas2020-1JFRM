#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void merge(int * a, int inicio, int fin,int tam,long long int * can){
	int mitad = (inicio + fin)/2;
	int i = inicio;
	int j = mitad + 1;
	int k = inicio;
	int temporal[tam];

	

	while(i<=mitad && j<=fin){
		can[0]+=1;
		if(a[i]<a[j]){
			can[1]+=1;
			temporal[k++] = a[i++];
		}
		else{
			can[1]+=1;
			temporal[k++] = a[j++];
		}
		
	}
	while(i<=mitad){
		can[1]+=1;
		temporal[k++] = a[i++];
		
	}
	while(j<=fin){
		can[1]+=1;
		temporal[k++] = a[j++];
		
	}
	
	for(i=inicio;i<=fin;i++){
		a[i] = temporal[i];
	}
}

void mergeSort(int * arreglo, int inicio, int fin, int tam,long long int * can){
	
	if(inicio>=fin){
		return;
	}
	int mitad = (inicio + fin)/2;
	mergeSort(arreglo,inicio,mitad,tam,can);
	mergeSort(arreglo,mitad + 1, fin,tam,can);
	merge(arreglo,inicio,fin,tam,can);
}


void incersion(int * arreglo, int tam, long long int * can){
	int i;
	int valor;
	int j;
	for(i=1;i<tam;i++){
		valor = arreglo[i];
		j = i-1;
		while(j>=0){
			can[0]+=1;
			if ( valor < arreglo[j]){
				arreglo[j+1] = arreglo[j];
				arreglo[j] = valor;
				j--;
				can[1]+=1;	
			}
			else{
				break;
			}
		}
	}
}

void seleccion(int * a,int tam,long long int * can){
	int i,j;
	int menor;
	int valor;
	for(i=0;i<tam;i++){
		menor = i;
		for(j=i+1;j<tam;j++){
			can[0]+=1;
			if(a[menor]>a[j]){
				menor = j;
			}
		}
		
		if(menor != i){
			valor=a[menor];
			a[menor] = a[i];
			a[i] = valor;
			can[1]+=1;

		}
	}
}

void seleccionPeor(int * a,int tam,long long int * can){
	int i,j;
	int menor;
	int pos;
	for(i=0;i<tam;i++){
		menor = a[i];
		for(j=i+1;j<tam;j++){
			can[0]+=1;
			if(menor>a[j]){
				menor = a[j];
				pos = j;
			}
		}
		if(menor != a[i]){
			can[1]+=1;
			a[pos] = a[i];
			a[i] = menor;
		}
	}
}


void guardar( int tam,double seg, long long int * can, char * path){
	FILE* pFile = fopen(path,"a");
	fprintf(pFile,"n = %d TE = %f com = %lli inter = %lli\n", tam, seg,can[0], can[1]);
	fprintf(pFile,"\n");
	fclose(pFile);
}
void guardar2( int tam,double seg, long long int * can, char * path){
	FILE* pFile = fopen(path,"a");
	fprintf(pFile," %d,%f,%lli,%lli\n", tam, seg,can[0], can[1]);
	//fprintf(pFile,"\n");
	fclose(pFile);
}

void imprimir(int * a, int tam){
	for(int i = 0; i<tam;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


int main(){
	srand(time(NULL));
	int tam = 0;
	int cont = 0;
	int inicio = 0;
	int fin = 0;
	long long int can[2];
	//Tiempo
	clock_t start,end;
	double seg;
	//
	char path[40];

	for(int i=200000;i<1000001;i+=100000){
		can[0] = 0;can[1]=0;
		cont = 0;
		tam=i;
		fin=tam-1;
		int * a = malloc(tam*sizeof(int));
		while(cont<tam){
			a[cont] = rand() % 11;
			cont++;
		}
		
		start = clock();
		mergeSort(a,inicio,fin,tam,can);
		end = clock();
		seg = (double)(end-start)/CLOCKS_PER_SEC;
		strcpy(path,"MergeSort100.txt");
		guardar2(tam,seg,can,path);
		printf("n = %d TE = %f com = %lli inter = %lli\n", tam, seg,can[0], can[1]);

		free(a);
	}	
}