#include "funciones.h"

int main(int argc, char const *argv[]) {
  if(argc!=4) {
    printf("Error siga la sg sintaxis: <ejecutable> <numelementos> <mayor> <menor>\n");
    return -1;
  }
  int nelem=atoi(argv[1]), mayor=atoi(argv[2]), menor=atoi(argv[3]);
  int *vector=reservaMemoria(nelem);
  rellenaVectorAleatorio(vector, nelem, mayor, menor);
  imprimeVector(vector, nelem);
  int mayorele;
  mayorElemento(vector, nelem, &mayorele);
  printf("El mayor elemento del vector es %d\n", mayorele);
  liberaVector(vector);
  return 0;

}
