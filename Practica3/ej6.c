#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

int main(int argc, char const *argv[]) {
	FILE *f1, *f2;
	char s[MAX];
	int c;
	printf("Introduce el nombre del fichero: ");
	scanf("%s", s);
	sprintf(s2, "mayusculas-%s", s);


	f1=fopen(s, "r");
	if(f1==0) {
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	f2=fopen(s2, "w");
	if(f2==0) {
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while((c=fgetc(f1))!=EOF)
		fputc(toupper(c), f2);

	fclose(f1);
	fclose(f2);

	if(remove(s)==0)
		printf("Fichero borrado\n");

	return 0;
}
