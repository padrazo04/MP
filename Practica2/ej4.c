#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **reservaMemoria(int nFil, int nCol){
	int **m;
	if((m=(int **)calloc(nFil, sizeof(int *)))==NULL) {
		printf("Error en la reserva de Memoria\n\n");
		exit(-1);
	}
	for(int i=0; i<nFil; i++)
		*(m+i)=(int *)calloc(nCol,sizeof(int));
	printf("\n::Memoria resevada correctamente::\n\n");
	return m;
}

void rellenaMatriz(int **matriz, int nFil, int nCol){
	srand(time(NULL));
	for(int i=0; i<nFil; i++) {
		for (int j=0; j <nCol; j++) {
			matriz[i][j]=rand()%20+1;
		}
	}
		printf("::Memoria rellenada correctamente::\n\n");
}

void imprimeMatriz(int **matriz, int nFil, int nCol){
	for(int i=0; i<nFil; i++) {
		printf("Fila %d: \t",i+1);
		for (int j=0; j < nCol; j++) {
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

int *minCol(int **matriz, int nFil, int nCol){
	int *minimos;
	int j=0, i=0;
	minimos=(int *)calloc(nCol,sizeof(int));
	for(; i<nCol; i++) {
		minimos[i]=matriz[j][i];				//minimos[i]=*(minimos+i)
		for(j=0; j<nFil; j++) {
			if(matriz[j][i]<minimos[i])		//matriz[i][j]=*(*(matriz+i)+j)
				minimos[i]=matriz[j][i];
		}
		j=0;
	}
	printf("\n");
	return minimos;
}

void liberaMemoria(int ***matriz, int nFil) {
	for(int i=0; i<nFil; i++)
		free((*matriz)[i]);
	free(*matriz);
	*matriz=NULL;
	printf("\n::Memoria liberada correctamente::\n");
}

int main(int argc, char const *argv[])
{
	int **tabla, *minint, nFil=0, nCol=0;
	printf("Numero de Filas: ");
	scanf("%d", &nFil);
	printf("Numero de Columnas: ");
	scanf("%d", &nCol);

	tabla=reservaMemoria(nFil, nCol);
	rellenaMatriz(tabla, nFil, nCol);
	imprimeMatriz(tabla, nFil, nCol);
	minint=minCol(tabla, nFil, nCol);
	for(int i=0; i<nCol; i++)
		printf("Menor Elemento de la columna %d: %d\n",i+1, minint[i]);
	liberaMemoria(&tabla, nFil);
	return 0;
}
