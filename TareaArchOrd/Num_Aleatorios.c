#include "Num_Aleatorios.h"


void imprimir(int * a, int tam){
	printf("Su arreglo es : ");
	for(int i = 0; i<tam;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void guardar(char * path,int * tam){
	FILE* pFile = fopen(path,"w");
	if(pFile==NULL){
		return;
	}
	int cont  = 0;
	int n;
	while ( cont < *tam){
		n = rand() % 11;
		fprintf(pFile, " %d ", n);
		cont++;
	}
	fclose(pFile);
	printf("Acabé\n");
}

void seleccionarArchivo(char * path, int * tam, int opc1){
	int opc;
	do{
		printf("1. num10.txt\n");
		printf("2. num100.txt\n");
		printf("3. num1000.txt\n");
		printf("4. num10000.txt\n");
		printf("5. numUltimo.txt\n");
		printf("Último es de 1'000.000 de datos\n");
		printf("0. Salir\n");
		printf("opc : ");scanf("%d",&opc);
		switch(opc){
			case 1:
				strcpy(path,"num10.txt");
				*tam = 10;
				if ( opc1 == 1){
					guardar(path,tam);
				}
				break;
			case 2:
				strcpy(path,"num100.txt");
				*tam = 100;
				if ( opc1 == 1){
					guardar(path,tam);
				}
				break;
			case 3:
				strcpy(path,"num1000.txt");
				*tam = 1000;
				if ( opc1 == 1){
					guardar(path,tam);
				}
				break;
			case 4:
				strcpy(path,"num10000.txt");
				*tam = 10000;
				if ( opc1 == 1){
					guardar(path,tam);
				}
				break;
			case 5:
				strcpy(path,"numUltimo.txt");
				*tam = 1000000;
				if ( opc1 == 1){
					guardar(path,tam);
				}		
				break;
		}

	}while(opc!=0);
}

void guardarNumAlea(){
	srand(time(NULL));
	char path[TAM_PATH];
	int opc = 0;
	int tamanio;
	int * tam;
	tam = &tamanio;
	printf("Ingresa en qué archivo deseas guardar los números aleatorios\n");
	printf("Cada archivo corresponde al número de datos que desa guardar\n");
	int opc1 = 1;
	seleccionarArchivo(path,tam,opc1);
}

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

void guardarOrdenado(int * ordenado, int tam, char * path){
	FILE* pFile = fopen(path,"w");
	if (pFile == NULL){
		printf("No se encontró el archivo\n");
		return;
	}
	int cont = 0;
	while(cont<tam){
		fprintf(pFile, " %d ", ordenado[cont]);
		cont++;
	}
	fclose(pFile);
	printf("Acabé2\n");
}

void guardarEstadisticas(char * path, int tam, time_t comienzo, time_t final, double segundos, long long int * can){
	FILE* pFile = fopen(path,"a");
	fprintf(pFile,"Para n = %d\n",tam);
	fprintf(pFile,"Comienzo : %s",ctime(&comienzo));
	fprintf(pFile,"Final : %s",ctime(&final));
	fprintf(pFile,"Tiempo de ejecución : %f / Comparaciones : %lli / Intercambios : %lli\n",segundos,can[0],can[1]);
	fprintf(pFile,"\n");
    fclose(pFile);
}


void ordenar(){
	int opc1=2;
	char path[TAM_PATH];
	char ruta[40];
	char path_est[40];
	int tamanio;
	int * tam;
	tam = &tamanio;
	
	int opc = 0;
	
	clock_t start,end;
	double seg;
	time_t comienzo,final;

	long long int can[2] = {0,0};


	do{
		printf("Escoja el archivo que desea ordenar \n");
		seleccionarArchivo(path,tam,opc1);
		int orden[tamanio];
		int inicio = 0;
		int fin = tamanio-1;
		int cont = 0;
		FILE* pFile = fopen(path,"r");
		while(!feof(pFile)){
			fscanf(pFile,"%d", &orden[cont]);
			cont++;
		}
		fclose(pFile);
		printf("Escriba el algoritmo con el que desea ordenar\n");
		printf("1. MergSort\n");
		printf("2. Inserción\n");
		printf("3. Selección\n");
		printf("4. SelecciónPeor\n");
		printf("0. Salir\n");
		printf("opc : ");scanf("%d",&opc);
		switch(opc){
			case 1: 
				time(&comienzo);
				start = clock();
				mergeSort(orden, inicio, fin, tamanio,can);
				end =clock();
				time(&final);
				seg = (double)(end-start)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecución : %f\n", seg);
				printf("Cantidad de intercambios : %lli\n",can[1]);
				printf("Cantidad de comparaciones : %lli\n",can[0]);
				printf("\n");
				strcpy(path_est,"MergeEst.txt");
				guardarEstadisticas(path_est,tamanio,comienzo,final,seg,can);
				can[0]=0;can[1]=0;
				switch(tamanio){
					case 10:
						strcpy(ruta,"Ord10Merge.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 100:
						strcpy(ruta,"Ord100Merge.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000:
						strcpy(ruta,"Ord1000Merge.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 10000:
						strcpy(ruta,"Ord10000Merge.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000000:
						strcpy(ruta,"Ord1000000Merge.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
				}
				break;
			case 2:
				time(&comienzo);
				start = clock();
				incersion(orden,tamanio,can);
				end =clock();
				time(&final);
				seg = (double)(end-start)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecución : %f\n", seg);
				printf("Cantidad de intercambios : %lli\n",can[1]);
				printf("Cantidad de comparaciones : %lli\n",can[0]);
				printf("\n");
				strcpy(path_est,"IncerEst.txt");
				guardarEstadisticas(path_est,tamanio,comienzo,final,seg,can);
				can[0]=0;can[1]=0;
				switch(tamanio){
					case 10:
						strcpy(ruta,"Ord10Incer.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 100:
						strcpy(ruta,"Ord100Incer.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000:
						strcpy(ruta,"Ord1000Incer.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 10000:
						strcpy(ruta,"Ord10000Incer.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000000:
						strcpy(ruta,"Ord1000000Incer.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
				}
				break;
			case 3:
				time(&comienzo);
				start = clock();
				seleccion(orden,tamanio,can);
				end =clock();
				time(&final);
				seg = (double)(end-start)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecución : %f\n", seg);
				printf("Cantidad de intercambios : %lli\n",can[1]);
				printf("Cantidad de comparaciones : %lli\n",can[0]);
				printf("\n");
				strcpy(path_est,"SelecEst.txt");
				guardarEstadisticas(path_est,tamanio,comienzo,final,seg,can);
				can[0]=0;can[1]=0;
				switch(tamanio){
					case 10:
						strcpy(ruta,"Ord10Sele.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 100:
						strcpy(ruta,"Ord100Sele.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000:
						strcpy(ruta,"Ord1000Sele.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 10000:
						strcpy(ruta,"Ord10000Sele.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000000:
						strcpy(ruta,"Ord1000000Sele.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
				}
				break;
			case 4:
				time(&comienzo);
				start = clock();
				seleccionPeor(orden,tamanio,can);
				end =clock();
				time(&final);
				seg = (double)(end-start)/CLOCKS_PER_SEC;
				printf("Tiempo de ejecución : %f\n", seg);
				printf("Cantidad de intercambios : %lli\n",can[1]);
				printf("Cantidad de comparaciones : %lli\n",can[0]);
				printf("\n");
				strcpy(path_est,"SelecPeorEst.txt");
				guardarEstadisticas(path_est,tamanio,comienzo,final,seg,can);
				can[0]=0;can[1]=0;
				switch(tamanio){
					case 10:
						strcpy(ruta,"Ord10SelePeor.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 100:
						strcpy(ruta,"Ord100SelePeor.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000:
						strcpy(ruta,"Ord1000SelePeor.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 10000:
						strcpy(ruta,"Ord10000SelePeor.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
					case 1000000:
						strcpy(ruta,"Ord1000000SelePeor.txt");
						guardarOrdenado(orden,tamanio,ruta);
						break;
				}
				break;

		}
	}while(opc != 0);
	

}