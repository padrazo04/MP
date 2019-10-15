/**
	@file fun6.c
	@brief Fichero con las funciones de matrices
*/

#include <stdio.h>	///< Libreria stdio.h
#include <stdlib.h>	///< Libreria stdlib.h
#include <time.h>		///< Libreria time.h
#include "fun6.h"		///< Libreria con las funciones de  matrices

/**
	@fn int **reservaMemoria(int nFil,int nCol)
	@brief Reserva memoria y retorna un puntero al primer elemento de la matriz

	Reserva memoria para nFil filas y nCol columnas
	@param int nFil Numero de Filas
	@param int nCol Numero de Columnas
	@return Devuelve un puntero al primer elemento de la matriz
*/
int **reservaMemoria(int nFil, int nCol){
	int **m;
	if((m=(int **)calloc(nFil, sizeof(int *)))==NULL) {
		printf("Error en la reserva de Memoria\n\n");
		exit(-1);
	}
	for(int i=0; i<nFil; i++)
		*(m+i)=(int *)calloc(nCol,sizeof(int));
	//printf("\n::Memoria resevada correctamente::\n\n");
	return m;
}
/**
	@fn void rellenaMatriz(int **matriz,int nFil,int nCol)
	@brief Rellena la matriz con numeros aleatorios
	@param int** matriz Direccion de memoria del primer elemento de la matriz
	@param int nFil Numero de Filas
	@param int nCol Numero de Columnas
	@return nada
*/
void rellenaMatriz(int **matriz, int nFil, int nCol){
	srand(time(NULL));
	for(int i=0; i<nFil; i++) {
		for (int j=0; j <nCol; j++) {
			matriz[i][j]=rand()%20+1;
		}
	}
		//printf("::Matriz rellenada correctamente::\n\n");
}
/**
	@fn void imprimeMatriz(int **matriz,int nFil,int nCol)
	@brief Muestra la matriz por pantalla
	@param int **matriz Direccion de memoria del primer elemento de la matriz
	@param int nFil Numero de Filas
	@param int nCol Numero de Columnas
	@return nada
*/
void imprimeMatriz(int **matriz, int nFil, int nCol){
	for(int i=0; i<nFil; i++) {
		printf("Fila %d: \t",i+1);
		for (int j=0; j < nCol; j++) {
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

/**
	@fn int *minCol(int **matriz, int nFil, int nCol)
	@brief Calcula el menor elemento de cada columna
	@param int **matriz Direccion de memoria del primer elemento de la matriz
	@param int nFil Numero de Filas
	@param int nCol Numero de Columnas
	@return Puntero al primer elemento del vector con los menores de cada columna
*/
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

/**
	@fn void liberaMemoria(int ***matriz, int nFil)
	@brief Libera la memoria utilizada por el puntero matriz
	@param int ***matriz Direccion de memoria del primer elemento de la matriz
	@param int nFil Numero de Filas
	@return nada
*/
void liberaMemoria(int ***matriz, int nFil) {
	for(int i=0; i<nFil; i++)
		free((*matriz)[i]);
	free(*matriz);
	*matriz=NULL;
	//printf("\n::Memoria liberada correctamente::\n");
}
