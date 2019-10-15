#include <stdio.h>
#define MAXLINEA 256

void verFichero(char *nombreFichero) {
	FILE *f;
	struct persona p;
	char nombreFichero[MAXLINEA];
	printf("Escribir el nombre del fichero: ");
	scanf("%s", nombreFichero);

	f=fopen(nombreFichero, "r");
	fscanf(f, "%s%s%ld%f", p.nombre, p.apellido, &p.dni, &p.salario)
	//while(fscanf(f, "%s%s%ld%f", p.nombre, p.apellido, &p.dni, &p.salario)==4)
	//fscanf devuelve un entero de los datos que ha leido
	while(fscanf(f, "%s%s%ld%f", p.nombre, p.apellido, &p.dni, &p.salario)!=EOF);
	//ESCRIBIRDATOSPERSONALES(p);	
	fclose(f);
}

void verFichero2(char *nombreFichero) {
	FILE *f;

	f=fopen(nombreFichero, "r");

	while((fgets(linea, MAXLINEA, f)!=NULL) {
		//limpiarLinea(linea);
		strcpy(p.nombre, linea);
		fgets(linea, MAXLINEA, f);
		sscanf(linea, "%ld", &p.dni);

		fgets(linea, MAXLINEA, f);
		sscanf(linea, "%f", &p.salario);
	}
}

