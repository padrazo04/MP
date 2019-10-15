#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct ficha {
  char nombre[MAX];
  int edad;
  int peso;
} Ficha;

struct ficha *reservaMemoria(int nele);
void liberaMemoria(struct ficha *v);
void rellenaVector(struct ficha *v, int nele);
void muestraVector(struct ficha *v,int nele);
float mayores65(struct ficha *v, int nele);


#endif
