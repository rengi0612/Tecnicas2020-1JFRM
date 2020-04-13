
#include "FuncionesCC.h"


local_t ** crearCentroComercial(int pisos, int locales){
	int i;
	local_t ** pCentroComercial = malloc(pisos*sizeof(local_t*));
	if(pCentroComercial!=NULL){
		for(i=0;i<pisos;i++){
			pCentroComercial[i] = malloc(locales*sizeof(local_t));
			if (pCentroComercial[i]==NULL){
				printf("error al reservar memoria\n");
				break;
			}
		}
	}else{
		printf("error reservando la memoria\n");
	}
	printf("Memoria reservada\n");
	return pCentroComercial;
}

int fibo(int n){
	int resultado;
	if (n<2){
		return n;
	}
	else
		resultado = fibo(n-1) + fibo(n-2);
	return resultado;
}

int crearIdLocal(int numPiso, int numLocal){
	int sumandoPiso = numPiso + 3 + numLocal;
	int sumandoLocal = numLocal + 8;
	int resultado = fibo(sumandoPiso) + fibo(sumandoLocal);
	return resultado;
}



void ingresarNuevoLocal(local_t ** pCentroComercial, int pisos, int locales){
	int numPiso = 0;
	int numLocal = 0;
	int bandera = 0;
	int categoria = 0;

	printf("Está a punto de crear un nuevo local\n");

	while(bandera==0){
		
		printf("Por favor, ingrese el piso en donde lo desea ubicar : ");
		scanf("%d",&numPiso);
		printf("Por favor, ingrese el numero del local en donde lo desea ubicar : ");
		scanf("%d",&numLocal);
		numPiso--;
		numLocal--;

		if (numPiso> pisos || numLocal>locales){
			printf("Ha ingresado un piso o un local que no existe\n");
			return;
		}
		
		if (pCentroComercial[numPiso][numLocal].estado == libre){
			bandera = 1;
			break;
		}
		
		else  {
			printf("Vuelva a ingresar los datos\n");
		}

	}
	
	fflush(stdin);
	printf("Ingrese el nombre de su nuevo local : ");
	scanf("%s",pCentroComercial[numPiso][numLocal].nombreLocal);
	pCentroComercial[numPiso][numLocal].pisoLocal = numPiso;
	pCentroComercial[numPiso][numLocal].numxLocal = numLocal;
	pCentroComercial[numPiso][numLocal].idLocal = crearIdLocal(numPiso+1, numLocal+1);
	pCentroComercial[numPiso][numLocal].estado = ocupado;

	printf("Ingrese a qué categoría pertenece su local 1.ropa 2.comida 3.entretenimiento : ");
	scanf("%d",&categoria);
	switch(categoria){
		case 1:
			pCentroComercial[numPiso][numLocal].categoria = ropa;
			break;
		case 2:
			pCentroComercial[numPiso][numLocal].categoria = comida;
			break;
		case 3:
			pCentroComercial[numPiso][numLocal].categoria = entretenimiento;
	}
	printf("Ingrese el precio del local : ");scanf("%d", &pCentroComercial[numPiso][numLocal].precioLocal);
	
}
void imprimir(int i, int j ,local_t ** pCentroComercial){
	printf("Nombre: %s - ID: %d - Piso : %d - #Local : %d - Precio : %d - Estado : ", pCentroComercial[i][j].nombreLocal, pCentroComercial[i][j].idLocal,pCentroComercial[i][j].pisoLocal+1,pCentroComercial[i][j].numxLocal+1, pCentroComercial[i][j].precioLocal);
			if (pCentroComercial[i][j].estado == libre){
				printf("Libre - Categoría : ");
			}
			else{
				printf("Ocupado - Categoría : ");
			}
			if (pCentroComercial[i][j].categoria == ropa){
				printf("Ropa\n");
			}
			else if (pCentroComercial[i][j].categoria == comida){
				printf("Comida\n");
			}
			else if (pCentroComercial[i][j].categoria == entretenimiento){
				printf("Entretenimiento\n");
			}
			else{
				printf("Sin clasificar\n");
			}
}

void mostrarCentro(local_t ** pCentroComercial, int pisos, int locales){
	int i,j;
	for (i=0;i<pisos;i++){
		printf("====================================================================================\n");
		for (j=0;j<locales;j++){
			imprimir(i,j,pCentroComercial);
		}
		printf("====================================================================================\n");
	}
	printf("\n");
}

void mostrarCategorias(local_t ** pCentroComercial, int pisos, int locales){
	int i,j;
	int opcion;
	int bandera = 0;
	categoria cat;
	printf("Ingrese la categoría que desea buscar 1.ropa 2.comida 3.entretenimiento : ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			cat = ropa;
			break;
		case 2:
			cat = comida;
			break;
		case 3:
			cat  = entretenimiento;
			break;
		default:
			bandera = 1;
			break;
	}
	if (bandera == 1){
		printf("La opción ingresada no es válida\n");
		return;
	}
	for (i=0;i<pisos;i++){
		printf("====================================================================================\n");
		for(j=0;j<locales;j++){
			if (pCentroComercial[i][j].categoria == cat){
				printf("Nombre: %s - ID: %d - Piso : %d - #Local : %d - Precio : %d \n", pCentroComercial[i][j].nombreLocal, pCentroComercial[i][j].idLocal,pCentroComercial[i][j].pisoLocal+1,pCentroComercial[i][j].numxLocal+1,pCentroComercial[i][j].precioLocal);
			}
		}
		printf("====================================================================================\n");
	}
}

void mostrarLocal(local_t ** pCentroComercial, int pisos, int locales){
	int i,j;
	int opcion;
	int numPiso = 0;
	int numLocal = 0;
	int ID;
	int bandera = 0;
	printf("Desea buscar el local por nombre o por ubicacion? 1.Nombre 0.ID : ");
	scanf("%d", &opcion);
	if (opcion==1){
		char nombre[35];
		printf("Ingrese el nombre del local que desea buscar : ");scanf("%s",nombre);
		for(i=0;i<pisos;i++){
			for(j=0;j<locales;j++){
				if(!strcmp(pCentroComercial[i][j].nombreLocal, nombre)){
					printf("====================================================================================\n");
					imprimir(i,j,pCentroComercial);
					printf("====================================================================================\n");
					bandera = 0;
					break;
				}
				else{
					bandera = 1;
				}
			}
			
		}
		if(bandera == 1){
			printf("No se encontró el nombre\n");
		}
	}
	else{
		printf("Ingrese el ID del local que desea buscar : ");scanf("%d",&ID);
		for(i=0;i<pisos;i++){
			for(j=0;j<locales;j++){
				if(pCentroComercial[i][j].idLocal == ID){
					printf("====================================================================================\n");
					imprimir(i,j,pCentroComercial);
					printf("====================================================================================\n");
					bandera = 0;
					break;
				}
				else{
					bandera = 1;
				}
			}
		}
		if (bandera == 1){
			printf("No se encontró el ID\n");
		}
		
	}
}



void modificarLocal(local_t ** pCentroComercial, int pisos, int locales){
	int i = 0;
	int j = 0;
	int numPiso = 0;
	int numLocal = 0;
	int cantidad = 0;
	int catego = 0;
	categoria cat;
	int ID = 0;
	int opcion = 0;
	printf("Ingrese cuántos locales desea modificar : ");scanf("%d",&cantidad);
	while(cantidad>0){
		printf("Ingrese el ID del local que desea cambiar : ");scanf("%d",&ID);
		for(i=0;i<pisos;i++){
			for(j=0;j<locales;j++){
				if(pCentroComercial[i][j].idLocal == ID){
					numPiso = i;
					numLocal = j;
				}
			}
		}
		printf("Ingrese el cambio que desea realizar al local\n");
		printf("1. Cambiar nombre\n");
		printf("2. Cambiar ubicacion\n");
		printf("3. Cambiar categoría\n");
		printf("Opc : ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: 
				printf("Ingrese el nombre nuevo para el local : ");scanf("%s",pCentroComercial[numPiso][numLocal].nombreLocal);
				cantidad--;
				break;
			case 2:
				printf("Ingrese el nuevo piso : ");scanf("%d",&i);
				printf("Ingrese el nuevo número de local : ");scanf("%d",&j);
				if (pCentroComercial[i-1][j-1].estado == libre){
					strcpy(pCentroComercial[i-1][j-1].nombreLocal ,pCentroComercial[numPiso][numLocal].nombreLocal);
					strcpy(pCentroComercial[numPiso][numLocal].nombreLocal,"");
					pCentroComercial[i-1][j-1].idLocal = pCentroComercial[numPiso][numLocal].idLocal + crearIdLocal(i,j);
					pCentroComercial[numPiso][numLocal].idLocal = 0;
					pCentroComercial[i-1][j-1].pisoLocal = i-1;
					pCentroComercial[i-1][j-1].numxLocal = j-1;
					pCentroComercial[i-1][j-1].estado = ocupado;
					pCentroComercial[numPiso][numLocal].estado = libre;
					pCentroComercial[i-1][j-1].categoria = pCentroComercial[numPiso][numLocal].categoria;
					pCentroComercial[numPiso][numLocal].categoria = sinAsignar;
					pCentroComercial[i-1][j-1].precioLocal = pCentroComercial[numPiso][numLocal].precioLocal;
					pCentroComercial[numPiso][numLocal].precioLocal = 0;
				}
				cantidad--;
				break;
			case 3:
				printf("Ingrese la nueva categoría para su local, 1.ropa 2.comida 3.entretenimiento : ");scanf("%d",&catego);
				switch(catego){
					case 1:
						cat = ropa;
						break;
					case 2: 
						cat = comida;
						break;
					case 3:
						cat = entretenimiento;
						break;
				}
				pCentroComercial[numPiso][numLocal].categoria = cat;
				cantidad--;
				break;
			default:
				cantidad--;

		}
	}

}

void eliminarLocal(local_t ** pCentroComercial, int pisos, int locales){
	int i = 0;
	int j = 0;
	int cantidad = 0;
	int ID = 0;
	int numPiso = 0;
	int numLocal = 0;

	printf("Ingrese la cantidad de locales que desea eliminar : ");scanf("%d",&cantidad);
	while(cantidad>0){
		printf("Ingrese el ID del local que desea borrar : ");scanf("%d", &ID);
		for(i=0;i<pisos;i++){
			for(j=0;j<locales;j++){
				if(pCentroComercial[i][j].idLocal == ID){
					numPiso = i;
					numLocal = j;
				}
			}
		}
		pCentroComercial[numPiso][numLocal].estado = libre;
		pCentroComercial[numPiso][numLocal].categoria = sinAsignar;
		pCentroComercial[numPiso][numLocal].idLocal = 0;
		strcpy(pCentroComercial[numPiso][numLocal].nombreLocal, "");
		pCentroComercial[numPiso][numLocal].precioLocal = 0;
		cantidad--;
	}

}

void buscarLocalPrecio(local_t ** pCentroComercial, int pisos, int locales){
	int mayor = 0;
	int i,j;
	int numPiso = 0;
	int numLocal = 0;
	for (i=0;i<pisos;i++){
		for(j=0;j<locales;j++){
			if(pCentroComercial[i][j].precioLocal>=mayor){
				mayor = pCentroComercial[i][j].precioLocal;
				numPiso = i;
				numLocal = j;
			}
		}
	}
	printf("El local más caro es : \n");
	imprimir(numPiso,numLocal, pCentroComercial);
}