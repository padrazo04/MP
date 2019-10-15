#include "funciones.h"

int **reservaMemoria(int nFil, int nCol) {
  int **v;
  v=(int **)malloc(nFil*sizeof(int *));
  if(v==NULL) {
    printf("Error en la reserva de memoria\n");
    return 0;
  }
  for(int i=0; i<nFil; i++)
    v[i]=(int *)malloc(nCol*sizeof(int));
  return v;
}

void rellenaMatriz(int **tabla, int nFil, int nCol) {
  for(int i=0; i<nFil; i++)
    for(int j=0; j<nCol; j++) {
      printf("Introduce el elemento [%d][%d]: ",i,j);
      scanf("%d",&tabla[i][j]);
    }
}

void imprimeMatriz(int **tabla, int nFil, int nCol){
  for(int i=0; i<nFil; i++)
    for(int j=0; j<nCol; j++) {
      printf("Elemento [%d][%d]: %d\n",i,j, tabla[i][j]);
    }
}

int *minCol(int **tabla, int nFil, int nCol) {
  int *v, menor;
  v=(int *)malloc(nCol*sizeof(int));
  if(v==NULL) {
    printf("Error en la reserva de memoria\n");
    return 0;
  }
  for(int i=0; i<nCol; i++) {
    menor=tabla[0][i];
    for(int j=0; j<nFil; j++) {
      if(menor>tabla[j][i])
        menor=tabla[j][i];
    }
    v[i]=menor;
  }
  return v;
}




void liberarMemoria(int **tabla, int nFil) {
  for(int i=0; i<nFil; i++)
    free(tabla[i]);
  free(tabla);


}
