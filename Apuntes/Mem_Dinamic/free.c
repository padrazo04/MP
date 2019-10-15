#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int* p, b=2;
	p=&b;
	printf("%p\n",p);
	p =(int*)malloc(5*sizeof(int)); //NO inicializa elementos del vector
	printf("%p\n",p);
	free(p);
	p=(int*)calloc (5, sizeof(int));// SI inicializa a 0 elementos del vector
	printf("%p\n",p);
	free(p);
	return 0;
}