#include "funciones.h"

int main(int argc, char const *argv[]) {
  if(argc!=2) {
    printf("Error, SINTAXIS: <ejecutable> <nombreFichero>\n");
    return -1;
  }
  char nombreFichero[MAX];
  strcpy(nombreFichero, argv[1]);
  int opc=0;

  if((FILE *f1=fopen(nombreFichero, "rb"))==NULL) {
    f1=fopen(nombreFichero, "wb");
    fclose(f1);
  } else fclose(f1);

  while(opc!=7) {
    printf("MENU\n");
    printf("1. Comprobar libro\n");
    printf("2. Nuevo Libro\n");
    printf("3. Contar Libros\n");
    printf("4. Listar libros\n");
    printf("5. Vender libro\n");
    printf("6. Borrar libros\n");
    printf("7. Salir\n");

    printf("OPCION: ");
    scanf("%d",&opc);
    getchar();
    switch (opc) {
      case 1: compruebalibro(char *nombreFichero);
      case 2: nuevolibro(char *nombreFichero);
      case 3: contarlibros(char *nombreFichero);
      case 4: mostrarlibrosenVector(char *nombreFichero);
      case 5: venderlibro(char *nombreFichero);
      case 6: borraragotados(char *nombreFichero);
      case 7: printf("ADIOS\n");
      default: printf("Introduzca un valor correcto\n");
    }
  }




  return 0;
}
