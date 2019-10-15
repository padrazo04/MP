#include "funciones.h"

int main() {
  int nele;
  printf("Introduce el numero de elementos: ");
  scanf("%d", &nele);
  Ficha *vector=reservaMemoria(nele);
  if(vector==NULL)
    return -1;
  rellenaVector(vector, nele);
  muestraVector(vector, nele);
  float media=mayores65(vector, nele);
  if(media==0) {
    printf("No habia mayores de 65\n");
  } else printf("MEDIA EDAD: %.2f\n", media);
  liberaMemoria(vector);
}
