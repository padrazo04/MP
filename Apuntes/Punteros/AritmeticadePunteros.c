#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, *b;
	b=&a;
	printf("Dirección a la que apunta b: %p\n", b);
	b++;		//Aumenta la direccion en n bytes siendo n el tamaño que ocupa el tipo de dato al que apunta.
	printf("Ahora b apunta hacia: %p\n", b);
	b+=10;
	printf("Ahora b apunta hacia: %p\n", b);
	b--;
	printf("Ahora b apunta hacia: %p\n", b);	
	return 0;
}