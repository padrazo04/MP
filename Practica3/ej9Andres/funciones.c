#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menuppal(){
	int menu;
	printf("--------------------------------------------------------------------\n");
	printf("1. Comprobar la existencia de un libro en stock buscado por titulo.\n");
	printf("2. Introducir un nuevo libro en stock.\n");
	printf("3. Contar el número de libros en stock.\n");
	printf("4. Listar los libros almacenados en stock\n");
	printf("5. Vender un libro buscado por titulo\n");
	printf("6. Borrar los titulos con 0 unidades en stock\n");
	printf("7. Salir\n");
	printf("--------------------------------------------------------------------\n");
	printf("\n");

	printf("Escoja una opción: ");
	scanf("%i", &menu);

	return menu;
}

void inlibro(char *nfich, struct libro *libros, int *nlibros){
	FILE *fichero;//se abre y cierra en el msmo archibo
	if((fichero = fopen(nfich,"a")) == NULL){
		printf("ERROR!!,no se encuentra el fichero;\n");
		exit(-1);
	}
	int m=1;
	do{
		printf("Introduzca el titulo\n");
		setbuf(stdin, NULL);
		fgets(libros[(*nlibros)].titulo, 50, stdin);
		printf("Introduzca el autor\n");
		fgets(libros[(*nlibros)].autor, 50, stdin);
		printf("Introduzca el precio: ");
		scanf("%f", &libros[(*nlibros)].precio);
		printf("Introduzca la cantidad de unidades disponibles: ");
		scanf("%i", &libros[(*nlibros)].udsd);

		//Escribo en el archivo, podria ponerlos todos en un solo fprintf
		fprintf(fichero, "%s%s", libros[(*nlibros)].titulo, libros[(*nlibros)].autor);
		fprintf(fichero, "%f %i\n", libros[(*nlibros)].precio, libros[(*nlibros)].udsd);

		(*nlibros)++;
		if((libros=(struct libro *)realloc(libros, ((*nlibros)+1)*sizeof(struct libro))) == NULL){
			printf("ERROR!!, falta memoria\n");
			fclose(fichero);
			exit(-1);
		}
		printf("Quiere introducir otro libro\n\t1. Si\n\t2. No\nOpción:");
		scanf("%i", &m);
	}
	while(m != 2);

	fclose(fichero);


	//lee el vector de estructuras


	for(int i=0; i<(*nlibros); i++){
					printf("--------------------------------\n");
					printf("Titulo: %s\n", libros[i].titulo);					
					printf("Autor: %s\n", libros[i].autor);
					printf("Precio: %f\n", libros[i].precio);
					printf("Unidades disponibles: %i\n", libros[i].udsd);
					printf("--------------------------------\n");
					
				}
}
/*
void cargadatos(FILE *fichero, struct libro *libros, int *nlibros){



}*/