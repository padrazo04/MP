#include <stdio.h>

int main(){
	int a, *b, **c;
	a=5;
	b=&a;
	c=&b;
	printf("Dirección de memoria de a: %p\n",&a);	//¿Cuanto ocupa una posición de memoria?¿¿1 byte, 1 bit, 4 bits??
	printf("Dirección de memoria a la que apunta b: %p\n",b);
	printf("Contenido de b: %d\n", *b);
	printf("Dirección de memoria a la que apunta c: %p\n",c);
	printf("Dirección de memoria a la que apunta *c: %p\n",*c);
	printf("Contenido de c: %d\n", **c);
	return 0;
}