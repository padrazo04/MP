#include <stdio.h>
#include <stdlib.h>
#include "carlos.h"

int **reservaMatrizEnteros(int nFil, int nCol){
  int **m;
  if((m=(int **)malloc(nFil*sizeof(int **)))==NULL){
    printf("Error en reserva de memoria\n");
    exit(-1);
  }
  for(int i=0; i<nFil; i++)
    if((m[i]=(int *)malloc(nCol*sizeof(int)))==NULL) {
      printf("Error en reserva de memoria\n");
      exit(-1);
    }
  return m;
}

void liberaMatrizEnteros(int ***m, int nFil, int nCol) {
  for(int i=0; i<nFil; i++)
    free((*m)[i]);
  free(*m);
  (*m)=NULL;
}

void leeMatrizEnteros(int **m, int nFil, int nCol) {
  for(int i=0; i<nFil; i++)
    for (int j=0; j<nCol; j++) {
      printf("m[%d][%d]: ",i+1,j+1);
      scanf("%d", &m[i][j]);
    }
}

void imprimeMatrizEnteros(int **m, int nFil, int nCol) {
  for(int i=0; i<nFil; i++) {
    for (int j=0; j<nCol; j++)
      printf("%d\t",m[i][j]);
    printf("\n");
  }
}
