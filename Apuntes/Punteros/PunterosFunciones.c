#include <stdio.h>

void imprimeElementos(int *v, int tope){	//int *v es equivalente a int v[]
	for(int i=0; i<tope; i++){
		printf("elemento %d: %d\n",i+1, *(v+i));
	}
}

void imprimeElementos2(int w[][], int m, int n){
	//Para arrays bidimensionales usaremos el formato anterior con memoria estática
	//NO DEBEMOS USAR: int **w, ya que no es un puntero
}

int main(int argc, char const *argv[])
{
	int v[5]={1,2,3,4,5};
	imprimeElementos(v,5);
	return 0;
}
