#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
	char nfich[50];
	int nlibros=0, menu=0;
	struct libro *libros;
	if((libros=(struct libro*)malloc(sizeof(struct libro))) == NULL){
		printf("ERROR, no hay memoria.\n");
	}

	printf("Que base de datos quiere usar\n \t1. Una existente\n \t2. Una nueva\nOpción: ");
	scanf("%i", &menu);
	printf("Indique el nombre completo del fichero:\n");
	setbuf(stdin, NULL);
	scanf("%s", nfich); //Si usas fgets rompes el explorador de archivos con el \n
	FILE *fichero;
	switch(menu){
		default:{
			printf("ERROR!!\n");
			break;
		};
		case 1:{
			if((fichero = fopen(nfich,"r")) == NULL){
				printf("ERROR!!,no se encuentra el fichero;\n");
				return -1;
			}
			break;
		};
		case 2:{
			if((fichero = fopen(nfich,"w")) == NULL){
				printf("ERROR!!,no se pudo crear el fichero;\n");
				return -1;
			}
			break;
		};
	}

	fclose(fichero); //El archivo se mantiene abierto entre funciones?

	//Si el fichero ya existe hayque cargar los datos que tenga guardados
/*	if(menu == 1){
		cargadatos(fichero, libros, &nlibros);
	}*/

	///

	for(menu=0; menu != 7;){
		menu= menuppal();
		switch(menu){
			default:{
				printf("ERROR!!, opción no válida.\n");
				break;
			};
			case 1:{
				printf("Caso 1\n");
				break;
			};
			case 2:{
				printf("Caso 2\n");
				inlibro(nfich, libros, &nlibros);
				break;
			};
			case 3:{
				printf("Caso 3\n");
				break;
			};
			case 4:{
				printf("Caso 4\n");
				break;
			};
			case 5:{
				printf("Caso 5\n");
				break;
			};
			case 6:{
				printf("Caso 6\n");
				break;
			};
			case 7:{
				printf("Salir.\n");
				break;
			};
			case 8:{
				printf("nlibros: %i\n", nlibros);
				for(int i=0; i<nlibros; i++){
					printf("--------------------------------\n");
					printf("Titulo: %s\n", libros[i].titulo);					
					printf("Autor: %s\n", libros[i].autor);
					printf("Precio: %f\n", libros[i].precio);
					printf("Unidades disponibles: %i\n", libros[i].udsd);
					printf("--------------------------------\n");
					
				
			break;
			}
		}
	}
	return 0;
}