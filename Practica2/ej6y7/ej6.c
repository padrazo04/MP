/**
	@file ej6.c
	@author Charli
	@date 3-Mayo-2018
	@version 1.0.0
	@var tabla
	@brief Fichero principal del ejercicio 6
	@mainpage BIENVENIDO AL EJERCICIO 6 DE LA PRACTICA 2 JEJE

	En este ejercicio se usan las bibliotecas y Doxygen
*/
#include <stdio.h>
#include "fun6.h"
/**
	@fn int main (int argc, char const *argv[])
	@brief Funcion main
	@return Nada
	*/
int main(int argc, char const *argv[])
{
	int **tabla, *minint, nFil=0, nCol=0;
	printf("Numero de Filas: ");
	scanf("%d", &nFil);	/**Hola me llamo Juan Tetete*/
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
