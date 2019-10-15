#include <stdio.h>
#include "carlos.h"

int main(int argc, char const *argv[]) {
  int nFil, nCol, **m;
  printf("Introduce el numero de filas: ");
  scanf("%d", &nFil);
  printf("Introduce el numero de columnas: ");
  scanf("%d", &nCol);

  m=reservaMatrizEnteros(nFil, nCol);
  leeMatrizEnteros(m, nFil, nCol);
  imprimeMatrizEnteros(m, nFil, nCol);
  liberaMatrizEnteros(&m, nFil, nCol);

  return 0;
}
