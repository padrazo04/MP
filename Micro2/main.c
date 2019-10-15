#include "funciones.h"

int main(int argc, char const *argv[]) {
  if(argc!=2) {
    printf("Error, sintaxis: <ejecutable> <Fichero>\n");
    exit(-1);
  }
  char nombreFichero[MAX];
  strcpy(nombreFichero, argv[1]);
  if(!compruebaFichero(nombreFichero)) {
    printf("\nError, el fichero no existe o no es posible abrirlo\n\n");
    return -1;
  }
  int cod;
  printf("Codigo del producto: ");
  scanf("%d", &cod);
  if(actualizaFichero(nombreFichero, cod))
    printf("\nFichero actualizado\n\n");
  else printf("\nNo se ha encontrado el codigo\n\n");

  return 0;
}
