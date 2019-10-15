#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

int **reservaMemoria(int nFil, int nCol);
void rellenaMatriz(int **tabla, int nFil, int nCol);
void imprimeMatriz(int **tabla, int nFil, int nCol);
int *minCol(int **tabla, int nFil, int nCol);
void liberarMemoria(int **tabla, int nFil);

#endif
