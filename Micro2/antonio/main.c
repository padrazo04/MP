#include "funciones.h"

int main(int argc, char const *argv[]) {
  if(argc!=3) {
    printf("Error, sintaxis: <ejecutable> <Fichero1><Fichero2>\n");
    exit(-1);
  }
  char nombreFichero[MAX];
  char nombreFichero1[MAX];
  strcpy(nombreFichero, argv[1]);
  strcpy(nombreFichero1, argv[2]);
  if(!compruebaFichero(nombreFichero,nombreFichero1)) {
    printf("\nError, el fichero no existe o no es posible abrirlo\n\n");
    return -1;
  }
  if(fusionficheros(nombreFichero,nombreFichero1)){
    printf("Fichero fusionado.\n");
  }else{
    printf("Error al fusionar fichros.\n" );
  }
  return 0;
}
