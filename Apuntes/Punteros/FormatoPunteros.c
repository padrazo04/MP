#include <stdio.h>

int main()
{
	int a;
	printf("\nDirecciones de memoria de a por formato:\n");
	printf("--------------------------------------------\n");
	printf("%%lu: %lu\n%%X: %X\n%%x: %x\n%%p:%p\n\n", &a, &a, &a, &a);
	return 0;
}
/*
%lu --> Numero Entero 140732545514756
%X  --> Hexadecimal en mayúsculas D8B8DDA4
%x  --> Hexadecimal en minúsculas d8b8dda4
%p  --> Hexadecimal en minúsculas con el prefijo 0x 0x7ffed8b8dda4
*/