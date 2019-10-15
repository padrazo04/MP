#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void rellenaFichero(const char *nombre, int *ptr, int nEle);
int *creaVectorDinamico(const char *nombre, int nEle, int mayor, int menor);

int main(int argc, char *argv[]){
  if(argc!=5) {
    printf("Error, introduzca los argumentos siguiendo la sintaxis:\n");
    printf("./<ejecutable> <nombreFichero> <nºelementos> <extremosuperior> <extremoinferior>\n");
    return -1;
  }
   char nombreFichero[MAX];
   int nEle, mayor, menor;

   strcpy(nombreFichero, argv[1]);
   nEle=atoi(argv[2]);
   mayor=atoi(argv[3]);
   menor=atoi(argv[4]);

   int *n=creaVectorDinamico(nombreFichero, nEle, mayor, menor);
   rellenaFichero(nombreFichero, n, nEle);

}

void rellenaFichero(const char *nombre, int *ptr, int nEle) {
  FILE *f;
  f=fopen(nombre, "wb");
  if(f==NULL) {
    printf("Ha habido un error al abrir el fichero %s\n", nombre);
    exit(-1);
  }

  for(int i = 0 ; i<nEle ; i++) {
    fwrite(ptr + i, sizeof(int), 1, f);
  }
  fclose(f);
}

int *creaVectorDinamico(const char *nombre, int nEle, int mayor, int menor) {
  int *ptr;
  ptr=(int *)malloc(nEle*sizeof(int));

  for(int i = 0 ; i < nEle ; i++)
    ptr[i]=(rand()%(mayor+1-menor)+menor);

  return ptr;
}
