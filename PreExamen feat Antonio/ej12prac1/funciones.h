#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *reservaMemoria(int n);
void rellenaVectorAleatorio(int *v, int n, int may, int men);
void imprimeVector(int *v, int n);
void mayorElemento(int *v, int n, int *mayorele);
void liberaVector(int *v);


#endif
