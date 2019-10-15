#include <stdio.h>
#include <stdlib.h>
#define MAXLINEA 256

int main(int argc, char* argv[]) {
  FILE *f;
  int num;
  float suma=0, cont=0, media;
  char aux[MAXLINEA];
  if(argc!=2) {
    printf("Error, numero de argumentos incorrecto\n");
    exit(-1);
  }
  f=fopen(argv[1], "r");
  while((fgets(aux, MAXLINEA, f))!=NULL) {
    num=atoi(aux);
    if((num%2)==0) {
      suma+=num;
      cont++;
    }
  }
  media=suma/cont;
  printf("La suma de los elementos pares del fichero %s es %.4f\n",argv[1], media);
}
