#include "Ejercicio1.h"

/* Bn por lo de la memoria dinámica. A mejorar la mayuscula sostenida para definir
los enums 
En general el codigo esta bn ordenado*/

struct Persona ** reservarMemoria(int fil, int col){
	int i;
	struct Persona** pGente = malloc(fil*sizeof(struct Persona*));
	if(pGente!=NULL){
		for(i=0;i<fil;i++){
			pGente[i] = malloc(col*sizeof(struct Persona));
			if (pGente[i]==NULL){
				printf("error al reservar memoria\n");
				break;
			}
		}
	}else{
		printf("error reservando la memoria\n");
	}
	printf("Memoria reservada\n");
	return pGente;
}

void ingresarUsuario (struct Persona ** pGente, int tamanios[]){
	printf("Ingrese el mes de nacimiento : ");
	int mes,genOp;
	scanf("%d",&mes);
	if (tamanios[mes-1]<5){
		printf("Ingrese el nombre del usuario: ");
		scanf("%s", pGente[mes-1][tamanios[mes-1]].nombre);
		printf("Ingrese el día de nacimiento : ");
		scanf("%d", &pGente[mes-1][tamanios[mes-1]].diaNacimiento);
		printf("Ingrese el año de nacimiento : ");
		scanf("%d", &pGente[mes-1][tamanios[mes-1]].anioNacimiento);
		printf("Ingrese el género 1 para hombre, 2 para mujer : ");
		scanf("%d",&genOp);
		genero g = genOp == 1 ? hombre : mujer;
		pGente[mes-1][tamanios[mes-1]].genero = g;
		tamanios[mes-1]+=1;
	}
	else
		printf("El mes está lleno");
	printf("\n");

}

void mostrarMes (struct Persona ** pGente, int tamanios[]){
	int j;
	int numMes=1;
	printf("Qué mes desea consultar ? ");
	scanf("%d",&numMes);
	for (j=0;j<tamanios[numMes-1];j++){
		printf("Nombre : %s  Fecha de Nacimiento : %d/%d/%d",pGente[numMes-1][j].nombre,pGente[numMes-1][j].diaNacimiento,numMes,pGente[numMes-1][j].anioNacimiento);
		if (pGente[numMes-1][j].genero == hombre){
			printf(" Género : Hombre ");
		}
		else
			printf(" Género : Mujer ");
		printf("\n");
	}
	printf("\n");

}

int fibo(int n){
	int resultado;
	if (n<2){
		return n;
	}
	else
		resultado = fibo(n-1)+fibo(n-2);

	return resultado;
}

void fibonacciDia (struct Persona ** pGente, int fil, int col){
	char nom[40];
	printf("En esta función se calcula el número de fibonacci del día de nacimiento de la persona solicitada.\n");
	printf("Ingrese el nombre: ");
	scanf("%s",nom);
	int i,j;
	for (i=0;i<fil;i++){
		for (j=0;j<col;j++){
			if (!strncmp(pGente[i][j].nombre,nom,40)){
				printf("Número de fibonacci : %d",fibo(pGente[i][j].diaNacimiento));
			}
		}
	}
	printf("\n");
}

void generos (struct Persona ** pGente,int fil, int col){
	int i,j,genOp;
	printf("En esta función se imprimen todas las personas que o son mujeres o son hombres \n");
	printf("Ingrese el género que desea imprimir 1 para hombres y 2 para mujeres :");
	scanf("%d",&genOp);
	genero g = genOp == 1 ? hombre : mujer;
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			if (pGente[i][j].genero==g){
				printf("Nombre : %s  Fecha de Nacimiento : %d/%d/%d",pGente[i][j].nombre,pGente[i][j].diaNacimiento,i,pGente[i][j].anioNacimiento);
			printf("\n");
			}
		}
	}
}