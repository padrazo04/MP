#include <stdio.h>

int main(){
	int a, *b, **c;		//Sistema Operativo de 64 bits : Punteros de 8 bytes; 64 bits
	double d, *e, *f;
	char g, *h, **i;

	printf("El tamaño de la variable int a es %lu bytes/%lu bits\n", sizeof(int), sizeof(a)*8 );
	printf("El tamaño de la variable int *b es %lu bytes/%lu bits\n", sizeof(int *), sizeof(b)*8 );
	printf("El tamaño de la variable int **c es %lu bytes/%lu bits\n\n", sizeof(int **), sizeof(c)*8 );

	printf("El tamaño de la variable double d es %lu bytes/%lu bits\n", sizeof(d), sizeof(d)*8 );
	printf("El tamaño de la variable double *e es %lu bytes/%lu bits\n", sizeof(e), sizeof(e)*8 );
	printf("El tamaño de la variable double **f es %lu bytes/%lu bits\n\n", sizeof(f), sizeof(f)*8 );

	printf("El tamaño de la variable char g es %lu byte/%lu bits\n", sizeof(g), sizeof(g)*8 );
	printf("El tamaño de la variable char *h es %lu bytes/%lu bits\n", sizeof(h), sizeof(h)*8 );
	printf("El tamaño de la variable char **i es %lu bytes/%lu bits\n", sizeof(i), sizeof(i)*8 );

	return 0;
}
