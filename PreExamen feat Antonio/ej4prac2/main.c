#include "funciones.h"

int main(int argc, char const *argv[]) {
  int nFil, nCol;
  printf("Num. Filas: ");
  scanf("%d", &nFil);
  printf("Num. Columnas: ");
  scanf("%d", &nCol);
  int **tabla;
  tabla=reservaMemoria(nFil, nCol);
  if(tabla==NULL)
    return -1;
  rellenaMatriz(tabla, nFil, nCol);
  imprimeMatriz(tabla, nFil, nCol);
  int *menor=minCol(tabla, nFil, nCol);
  for(int i=0; i<nCol; i++)
    printf("menor[%d]= %d\n",i, menor[i]);
  liberarMemoria(tabla, nFil);
  printf("Fin de Programa\n");
  return 0;
}
