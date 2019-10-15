#include "funciones.h"

int compruebalibro(char *nombreFichero, char *titulo);
int nuevolibro(char *nombreFichero);
int contarlibros(char *nombreFichero);
void mostrarlibrosenVector(char *nombreFichero);
void venderlibro(char *nombreFichero);
void borraragotados(char *nombreFichero);

int compruebalibro(char *nombreFichero) {
  FILE *f1;
  f1=fopen(nombreFichero, "rb");
  if(f1==NULL)
    return 0;
  else {
    fclose(f1);
    return 1;
  }
}
int nuevolibro(char *nombreFichero) {

}
int contarlibros(char *nombreFichero) {

}
void mostrarlibrosenVector(char *nombreFichero) {

}
void venderlibro(char *nombreFichero) {

}
void borraragotados(char *nombreFichero) {

}
