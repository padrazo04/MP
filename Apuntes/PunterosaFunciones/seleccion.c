#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seleccion(int *v, int n, int (*orden)(int, int));
void verVector(int *v, int n);
int ascendente(int a, int b);
int descendente(int a, int b);

int main() {
  int opc=0;
  int (*orden)(int, int);
  srand(time(NULL));
  int v[10];
  for(int i=0; i<10; i++)
    v[i]=rand()%20;

  printf("VECTOR SIN ORDENAR:\n");
  verVector(v, 10);
  printf("Elige opcion para ordenar:\n1.Ascendente\n2. Descendente\nOPC: ");
  scanf("%d", &opc);
  getchar();
  if(opc==1) orden=&ascendente;
  else orden=&descendente;
  seleccion(v, 10, orden);

  printf("VECTOR ORDENADO:\n");
  verVector(v, 10);
}

void verVector(int *v, int n) {
  for(int i=0; i<n; i++)
    printf("v[%d]= %d\n", i, v[i]);
}

void seleccion(int *v, int n, int (*orden)(int, int)) {
  int i,j, menor, aux;
  for(i=0; i<n; i++)
  {
    aux=i;
    for(j=i+1; j<n; j++)
      if((*orden)(v[aux], v[j]))
          aux=j;
    menor=v[aux];
    v[aux]=v[i];
    v[i]=menor;
  }
}

int ascendente(int a, int b) {
  if(a>b) return 1;
  else return 0;
}

int descendente(int a, int b) {
  if(a<b) return 1;
  else return 0;
}
