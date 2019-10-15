#include "funciones.h"

int *reservaMemoria(int n) {
  int *v=(int *)malloc(n*sizeof(int));
  if(v==NULL) {
    printf("Error al reservar memoria\n");
    return 0;
  }
  return v;
}

void rellenaVectorAleatorio(int *v, int n,int may,int men) {
  srand(time(NULL));
  for(int i=0; i<n; i++)
    v[i]=rand()%(may-men+1)+men;
}

void imprimeVector(int *v, int n) {
  for(int i=0; i<n; i++)
    printf("v[%d]= %d\n",i, v[i]);
}

void mayorElemento(int *v, int n, int* mayorele) {
  *mayorele=-9999;
  for(int i=0; i<n; i++)
    if(*mayorele<v[i])
      *mayorele=v[i];
}

void liberaVector(int *v) {
  free(v);
}
