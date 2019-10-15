/*
void qsort(void *base, size_t nelem, size_t size,
int (*cmp)(const void *e1, const void *e2))
void *base: Vector a ordenar
int nelem: Nº Elementos del Vector
int size: Tamaño de los Elementos del Vector
int (*cmp) (const void *e1, const void *e2):
  Funcion que compara dos Elementos. Devuelve:
    - Valor negativo, si e1 va antes que e2
    - 0 si son iguales
    - Valor positivo, si e1 va despues que e2
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int comparaEnteros(const void *e1, const void *e2);
void verVector(int *v, int n);
int ascendente(const void *a, const void *b);
int descendente(const void *a, const void *b);


int main() {
  int (*orden)(const void *, const void *), opc;
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
  qsort((int *)v, 10, sizeof(int), orden);
  printf("VECTOR ORDENADO:\n");
  verVector(v, 10);
}

void verVector(int *v, int n) {
  for(int i=0; i<n; i++)
    printf("v[%d]= %d\n", i, v[i]);
}

/*int comparaEnteros(const void *e1, const void *e2) {
  int *a, *b;
  a=(int *)e1;
  b=(int *)e2;
  if(*a<*b)
    return -1;
  else if(*a==*b)
    return 0;
  else return 1;
}*/

int ascendente(const void *e1, const void *e2) {
  int *a, *b;
  a=(int *)e1;
  b=(int *)e2;
  if(*a>*b) return 1;
  else if(*a==*b) return 0;
  else return -1;
}

int descendente(const void *e1, const void *e2) {
  int *a, *b;
  a=(int *)e1;
  b=(int *)e2;
  if(*a<*b) return 1;
  else if(*a==*b) return 0;
  else return -1;
}
