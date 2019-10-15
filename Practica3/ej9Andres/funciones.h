#ifndef FUNCIONES_H
#define FUNCIONES_H

struct libro{
	char titulo[50];
	char autor[50];
	float precio;
	int udsd;
};

int menuppal();
void inlibro(char *nfich, struct libro *libros, int *nlibros);
//void cargadatos(FILE *fichero, struct libro *libros, int *nlibros);



#endif