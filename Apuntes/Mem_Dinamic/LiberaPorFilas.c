#include <stdlib.h>
#include <stdio.h>

void **reservaMatrizDinamicaPorFilas(int nFil, int nCol){
	void **matriz1;
	matriz1=(void **)malloc(nFil*sizeof(void));
	for(int i=0; i<nFil; i++)
		*(matriz1+i)=(void *)malloc(nCol*sizeof(void));
	return matriz1;
}

void LiberaMatrizDinamicaPorFilas(float ***Matriz, int nFil){	//NO funciona con VOID
	for(int i=0; i<nFil; i++)
		free(*Matriz[i]);
	free(*Matriz);
	*Matriz=NULL;
}
int main(int argc, char const *argv[])
{
	float **tabla;
	tabla=(float**)reservaMatrizDinamicaPorFilas(2,3);
	*(*(tabla+1)+2)=3.2;
	printf("Valor del elemento [1][2]: %.1f\n", *(*(tabla+1)+2));
	printf("Direccion de memoria de [1][2]: %p\n", (*(tabla+1)+2));

	LiberaMatrizDinamicaPorFilas(&tabla, 2);	//No funciona con (void ***)

	printf("Valor del elemento [1][2]: %.1f\n", *(*(tabla+1)+2));
	printf("Direccion de memoria de [1][2]: %p\n", (*(tabla+1)+2));
	return 0;
}