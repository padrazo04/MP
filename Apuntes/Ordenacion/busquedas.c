#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccion(int *v, int n);
void verVector(int *v, int n);
int busquedaDicotomica(int *v, int n, int elemento);

int main() {
  srand(time(NULL));
  int v[10], n;
  for(int i=0; i<10; i++)
    v[i]=rand()%20;

  printf("VECTOR:\n");
  verVector(v, 10);
  seleccion(v, 10);
  printf("VECTOR ORDENADO:\n");
  verVector(v, 10);
  printf("Introduce el elemento a buscar: ");
  scanf("%d", &n);
  int pos=busquedaDicotomica(v, 10, n);
  if(pos>=0) {
    printf("El elemento esta en la posicion %d\n",pos);
  } else printf("No se encuentra el elemento\n");

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
      if(v[aux]>v[j])
        aux=j;
    menor=v[aux];
    v[aux]=v[i];
    v[i]=menor;
  }
}

int busquedaDicotomica(int *v, int n, int elemento) {
  int found=0, inf=0, sup=n, medio;
  while((inf<=sup) && (!found))
  {
    medio=(inf+sup)/2;
    if(v[medio]==elemento)
      found=1;
    else if(v[medio]>elemento)
      sup=medio-1;
    else inf=medio+1;
  }

  if(found)
    return medio;
  else return -1;
}
