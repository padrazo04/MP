#include <stdio.h>
#include <stdlib.h>

float **reservaMatrizDinamicaPorFilas(int nFil, int nCol){
	float **matriz1;
	matriz1=(float **)malloc(nFil*sizeof(float *));
	for(int i=0; i<nFil; i++)
		*(matriz1+i)=(float *)malloc(nCol*sizeof(float));
	return matriz1;
}

int main(int argc, char const *argv[])
{
	float **tabla;
	tabla=reservaMatrizDinamicaPorFilas(2,3);
	*(*(tabla))=1.1;
	*(*(tabla)+1)=1.2;
	*(*(tabla)+2)=1.3;
	*(*(tabla+1))=2.1;
	*(*(tabla+1)+1)=2.2;
	*(*(tabla+1)+2)=2.3;
	printf("Valor del elemento [1][2]: %.1f\n", *(*(tabla+1)+2));
	printf("Direccion de memoria de [1][2]: %p\n", (*(tabla+1)+2));
	return 0;
}

/*
void reservaMatrizDinamicaPorFilas(int ***tabla, int nFil, int nCol){
	int ***matriz1;
	*matriz1=(int **)malloc(nFil*sizeof(int));
	for(int i=0; i<nFil; i++)
		*(*(matriz1+i))=(int *)malloc(nCol*sizeof(int));
	return matriz1;
*/