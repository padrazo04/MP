#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccion(int *v, int n);
void verVector(int *v, int n);

int main() {
  srand(time(NULL));
  int v[10];
  for(int i=0; i<10; i++)
    v[i]=rand()%20;

  printf("VECTOR SIN ORDENAR:\n");
  verVector(v, 10);
  seleccion(v, 10);
  printf("VECTOR ORDENADO:\n");
  verVector(v, 10);

  return 0;
}

void verVector(int *v, int n) {
  for(int i=0; i<n; i++)
    printf("v[%d]= %d\n", i, v[i]);
}

void seleccion(int *v, int n) {
  int menor, aux;
  int i, j;
  for(i=0; i<n; i++)
  {
    aux=i;
    for(j=i+1; j<n; j++)
    {
      if(v[aux]>v[j]) {
        aux=j;
      }
    }
    menor=v[aux];
    v[aux]=v[i];
    v[i]=menor;
  }
}
