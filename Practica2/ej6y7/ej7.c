#include "fun6.h"
#include <stdio.h>

//int **multiplicaMatrices(int **m1, int **m2, int nFil1, int nCol1, int nCol2);  //nFil2 no se pasa ya que coincide con nCol1
void multiplicaMatrices(int **m1, int **m2, int **m3, int nFil1, int nCol1, int nCol2);


int main() {
  int **m1, **m2, **m3, nFil1, nCol1, nFil2, nCol2;
  printf("Introduce el numero de filas de la matriz 1: ");
  scanf("%d", &nFil1);
  printf("Introduce el numero de columnas de la matriz 1: ");
  scanf("%d", &nCol1);
  printf("\nIntroduce el numero de filas de la matriz 2: ");
  scanf("%d", &nFil2);
  while(nFil2!=nCol1) {
    printf("\nERROR: EL Nº DE FILAS DE M2 Y COLUMNAS DE M1 DEBEN COINCIDIR\n\n");
    printf("Introduce el numero de filas de la matriz 2: ");
    scanf("%d", &nFil2);
  }
  printf("Introduce el numero de columnas de la matriz 2: ");
  scanf("%d", &nCol2);
  m1=reservaMemoria(nFil1, nCol1);
  m2=reservaMemoria(nFil2, nCol2);
  m3=reservaMemoria(nFil1, nCol2);
  rellenaMatriz(m1, nFil1, nCol1);
  rellenaMatriz(m2, nFil2, nCol2);
  printf("\n::MATRIZ 1::\n");
  imprimeMatriz(m1, nFil1, nCol1);
  printf("\n::MATRIZ 2::\n");
  imprimeMatriz(m2, nFil2, nCol2);

  //m3=multiplicaMatrices(m1, m2, nFil1, nCol1, nCol2);
  multiplicaMatrices(m1, m2, m3, nFil1, nCol1, nCol2);

  printf("\nEl resultado de matriz1 x matriz2 es:\n");
  imprimeMatriz(m3, nFil1, nCol2);
  liberaMemoria(&m1, nFil1);
  liberaMemoria(&m2, nFil2);
  liberaMemoria(&m3, nFil2);
}

/*int **multiplicaMatrices(int **m1, int **m2, int nFil1, int nCol1, int nCol2) {
  int **aux;
  aux=reservaMemoria(nFil1, nCol2);
  for(int i=0; i<nFil1; i++)
    for(int j=0; j<nCol2; j++)
      for(int k=0; k<nCol1 ; k++)
        aux[i][j]+= m1[i][k] * m2[k][j];
  return aux;
}*/

void multiplicaMatrices(int **m1, int **m2, int **m3, int nFil1, int nCol1, int nCol2) {
  for(int i=0; i<nFil1; i++)
    for(int j=0; j<nCol2; j++)
      for(int k=0; k<nCol1 ; k++)
        m3[i][j]+= m1[i][k] * m2[k][j];
}
