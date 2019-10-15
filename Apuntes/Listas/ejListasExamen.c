#include <stdio.h>
#include <stdlib.h>

struct lista {
  int n;
  struct lista *sig;
} ;

struct lista *reservaElemento();
void insertaDelante(struct lista **cabeza, int n);
void imprimirLista(struct lista *cabeza);
void imprimirListaRecursivo(struct lista *cabeza);
void mayormenor(struct lista *cabeza, int *mayor, int *menor);

int main(int argc, char const *argv[]) {
  int n, encontrado;
  struct lista *cabeza=NULL;
  printf("Introduce el numero de elemetos n: ");
  scanf("%d", &n );
  getchar();
  for(int i=0; i<n; i++) {
    int n2=rand()%30 + 1;
    insertaDelante(&cabeza, n2);
  }

  imprimirListaRecursivo(cabeza);

  int mayor, menor;
  mayormenor(cabeza, &mayor, &menor);
  printf("MAYOR: %d\nMENOR: %d\n", mayor, menor);

  return 0;
}

struct lista *nuevoElemento() {
    return ((struct lista *)malloc(1*sizeof(struct lista)));
}

void insertaDelante(struct lista **cabeza, int n) {
  struct lista *nuevo;
  nuevo= nuevoElemento();
  nuevo->n=n;

  nuevo-> sig = *cabeza;
  *cabeza=nuevo;
}

void imprimirLista(struct lista *cabeza) {
  struct lista *aux = NULL;
  aux=cabeza;
  while(aux!=NULL) {
    printf("%d\n",aux->n);
    aux=aux->sig;
  }
}

void imprimirListaRecursivo(struct lista *cabeza) {
  if(cabeza!=NULL) {
    printf("%d\n", cabeza->n);
    imprimirLista(cabeza->sig);
  }
}

void mayormenor(struct lista *cabeza, int *mayor, int *menor) {
  struct lista *aux = NULL;
  aux=cabeza;
  *mayor= aux->n;
  *menor = aux->n;
  while(aux!=NULL) {
    if(aux->n<*menor) *menor=aux->n;
    if(aux->n>*mayor) *mayor=aux->n;
    aux=aux->sig;
  }

}
