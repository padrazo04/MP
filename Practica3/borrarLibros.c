#include <stdio.h>
#include "libros.h"

void borrarLibros(const char *nombreFichero);

void borrarLibros(const char *nombreFichero) {
  /*DECLARACION DE VARIABLES*/
  //------------------------------------------
  FILE *f1, *f2;
  char titulo[50];
  char autor[50];
  char datos[25];
  float precio;
  int uds;
  //------------------------------------------

  /*APERTURA DE FICHEROS*/
  //------------------------------------------
  f1=fopen(nombreFichero, "r");
  f2=fopen("temp", "w");
  //-----------------------------------------.

  /*COPIA DE DATOS*/
  //------------------------------------------
  while((fgets(titulo, 50, f1))!=NULL) {
    fgets(autor, 50, f1);
    fgets(datos, 25, f1);
    //fscanf(f1, "%f%d", &precio, &uds);
    sscanf(datos, "%f%d", &precio, &uds);
    if(uds!=0)
      fprintf(f2, "%s%s%s", titulo, autor, datos);
  }
  //------------------------------------------

  /*CIERRE Y BORRADO DE FICHEROS*/
  //------------------------------------------
  fclose(f1);
  fclose(f2);
  remove(nombreFichero);
  rename("temp", nombreFichero);
  //------------------------------------------
}
