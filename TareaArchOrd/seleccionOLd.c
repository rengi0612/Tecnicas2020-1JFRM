#include <stdio.h>
#include <time.h>

void seleccionPeor(int * a,int tam,int * can){
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


int main(){
	FILE* pFile = fopen("prueba.txt","a");
	int a[20] = {3,4,2,5,6,7,1,8,9,15,12,13,11,18,16,14,19,10,20,17};
	int tam = 20;

	time_t comienzo, final;
	clock_t start,end;
	double seg;

	int can[2];

	time(&comienzo);
	start = clock();
	seleccion(a,tam,can);
	end = clock();
	time(&final);
	seg = (double)(end-start)/CLOCKS_PER_SEC;
	fprintf(pFile,"Para n = %d\n",tam);
	fprintf(pFile,"Comienzo : %s",ctime(&comienzo));
	fprintf(pFile,"Final : %s",ctime(&final));
	fprintf(pFile,"Tiempo de ejecución : %f / Comparaciones : %d / Intercambios : %d\n",seg,can[0],can[1]);
	fprintf(pFile,"\n");
    fclose(pFile);
}