#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

int *creaVectorDinamico(const char *nombre, int *nEle);
float media(int *n, int nEle);

int main () {
  char nombreFichero[MAX];
  int *n, nEle;
  float med;

  printf("Introduce el nombre del fichero binario: ");
  fgets(nombreFichero, MAX, stdin);
  nombreFichero[strlen(nombreFichero)-1]='\0';
  /*printf("Introduce el numero de elementos a leer: ");
  scanf("%d", &nEle);*/

  n = creaVectorDinamico(nombreFichero, &nEle);
  med = media(n, nEle);

  printf("La media de los elementos pares es %.2f\n",med);
  return 0;
}

int *creaVectorDinamico(const char *nombre, int *nEle) {
  FILE *f;
  int *ptr;

  f=fopen(nombre, "rb");
  if(f==NULL) {
    printf("Ha habido un error al abrir el fichero %s\n", nombre);
    exit(-1);
  }

  fseek(f, 0, SEEK_END);
  *nEle=ftell(f)/sizeof(int);
  rewind(f);

  ptr=(int *)malloc(*nEle*sizeof(int));
  for(int i = 0 ; i < *nEle ; i++)
    fread(ptr + i , sizeof(int), 1, f);

  fclose(f);
  return ptr;
}

float media(int *n, int nEle) {
  float aux=0;
  for(int i = 0 ; i < nEle ; i++)
  {
    if((n[i]%2)==0)
      aux+=n[i];
  }
  return aux/nEle;
}
