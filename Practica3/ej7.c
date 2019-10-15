#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

int main() {
  srand(time(NULL));
  FILE *f;
  char nombre[MAX];
  int nelem, menor, mayor;
  printf("Nombre del fichero a crear: ");
  fgets(nombre, MAX, stdin);
  nombre[strlen(nombre)-1]='\0';
  printf("Numero de enteros: ");
  scanf("%d",&nelem);
  printf("Extremo superior del intervalo: ");
  scanf("%d",&mayor);
  printf("Extremo inferior del intervalo: ");
  scanf("%d",&menor);

  f=fopen(nombre, "w");
  if(f==NULL) {
    printf("Error\n");
    exit(-1);
  }
  for(int i=0; i<nelem; i++)
    fprintf(f, "%d\n",(rand()%(mayor-menor+1))+menor);
  fclose(f);

}
