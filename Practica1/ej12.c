#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rellenaVectorAleatorio(int *v, int *r);
void imprimirVector(int *v);
void crearIndiceImpares(int *v, int **v2);
void crearIndiceDivisibles(int *v, int *v3[]);
void imprimeIndice(int *v[], int n);

int main(int argc, char const *argv[]) {
  int v[10], *v2[5], *v3[4], rango;
  rellenaVectorAleatorio(v, &rango);
  imprimirVector(v);
  crearIndiceImpares(v, v2);
  crearIndiceDivisibles(v, v3);
  printf("Direcciones de los elementos impares: \n");
  imprimeIndice(v2, 5);
  printf("Direcciones de los elementos divisibles entre 3: \n");
  imprimeIndice(v3, 4);
  return 0;
}

void rellenaVectorAleatorio(int *v, int *r) {
  srand(time(NULL));
  printf("Introduce el rango: ");
  scanf("%d",r);
  for(int i=0; i<10; i++)
    v[i]=rand() % (*(r)+1);
}

void imprimirVector(int *v) {
  for(int i=0; i<10; i++)
    printf("v[%d]: %d\n",i+1,*(v+i));
}

void crearIndiceImpares(int *v, int *v2[]){
  int j=0;
  for(int i=1; i<10; i+=2) {
    v2[j]=(v+i);
    j++;
  }
}

void crearIndiceDivisibles(int *v, int *v3[]){
  int j=0;
  for(int i=0; i<10; i+=3) {
    v3[j]=(v+i);
    j++;
  }
}

void imprimeIndice(int **v, int n){
  for(int i=0; i<n; i++)
    printf("%p\n",*(v+i));
}
