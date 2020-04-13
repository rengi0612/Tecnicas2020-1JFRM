#include "FuncionesCC.h"
#include <stdio.h>

void menu(int pisos,int locales,local_t ** pCentroComercial){
	int opc=0;
	do{
		printf("Estas son las operaciones que puede realizar sobre su centro comercial\n");
		printf("1. Ingresar nuevo local\n");
		printf("2. Mostrar centro comercial\n");
		printf("3. Mostrar locales por categorías\n");
		printf("4. Mostrar Local \n");
		printf("5. Modificar locales\n");
		printf("6. Eliminar locales\n");
		printf("7. Buscar local más caro  \n");
		printf("0. Salir\n");
		printf("opc : ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				ingresarNuevoLocal(pCentroComercial,pisos, locales);
				break;
			case 2:
				mostrarCentro(pCentroComercial, pisos, locales);
				break;
			case 3:
				mostrarCategorias(pCentroComercial,pisos,locales);
				break;
			case 4:
				mostrarLocal(pCentroComercial,pisos,locales);
				break;
			case 5:
				modificarLocal(pCentroComercial,pisos,locales);
				break;
			case 6:
				eliminarLocal(pCentroComercial,pisos,locales);
				break;
			case 7:
				buscarLocalPrecio(pCentroComercial,pisos,locales);
				break;

		}
	}while(opc!=0);


}


int main(){
	int pisos=0;
	int locales=0;
	int i,j;
	local_t ** pCentroComercial;

	printf("Bienvenido a su nuevo centro comercial\n");
	printf("Por favor, ingrese el número de pisos que desea : ");
	scanf("%d",&pisos);
	printf("Por favor, ingrese el número de locales por piso que desea : ");
	scanf("%d",&locales);
	pCentroComercial = crearCentroComercial( pisos, locales);
	for (i=0;i<pisos;i++){
		for(j=0;j<locales;j++){
			pCentroComercial[i][j].estado = libre;
			pCentroComercial[i][j].categoria = sinAsignar;
			pCentroComercial[i][j].idLocal = 0;
			pCentroComercial[i][j].pisoLocal = i;
			pCentroComercial[i][j].numxLocal = j;
			strcpy(pCentroComercial[i][j].nombreLocal, "");
			pCentroComercial[i][j].precioLocal = 0;
		}
	}
	menu(pisos, locales, pCentroComercial);
	free(pCentroComercial);
	return 0;
}

