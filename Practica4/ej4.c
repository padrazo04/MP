#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct monomio {
  int coef;
  int exp;
  struct monomio *sig;
} monomio ;

monomio *nuevoElemento();
void insertaMonomio(monomio **cabeza, int coef, int exp);
void verPolinomio(monomio *cabeza);
int contarMonomios(monomio *cabeza);
void valores(monomio *cabeza);
void eliminarMonomio(monomio **cabeza, int exp);

int main() {
  int nelem;
  monomio *cabeza=NULL, aux;
  printf("Numero de monomios: ");
  scanf("%d", &nelem);
  getchar();

  for(int i=0; i<nelem; i++)
  {
    printf("Coeficiente del monomio %d: ", i+1);
    scanf("%d", &aux.coef);
    getchar();
    printf("Exponente del monomio %d: ", i+1);
    scanf("%d", &aux.exp);
    getchar();

    insertaMonomio(&cabeza, aux.coef, aux.exp);
  }
  printf("\nPOLINOMIO\n");
  verPolinomio(cabeza);
  printf("NUMERO DE MONOMIOS: %d\n\n", contarMonomios(cabeza));

  valores(cabeza);
  printf("Exponente del monomio a borrar: ");
  scanf("%d", &aux.exp);
  getchar();

  eliminarMonomio(&cabeza, aux.exp);

  printf("\nPOLINOMIO CON BORRADO\n");
  verPolinomio(cabeza);
  printf("NUMERO DE MONOMIOS: %d\n\n", contarMonomios(cabeza));

  return 0;
}

monomio *nuevoElemento() {
  return ((monomio *)malloc(1*sizeof(monomio)));
}

void insertaMonomio(monomio **cabeza, int coef, int exp) {
  monomio *nuevo;
  nuevo=nuevoElemento();
  nuevo->coef=coef;
  nuevo->exp=exp;
  nuevo->sig=*cabeza;
  *cabeza=nuevo;
}

void verPolinomio(monomio *cabeza) {
  monomio *aux=NULL;
  aux=cabeza;

  while(aux!=NULL)
  {
    printf("%dx^%d\n",aux->coef, aux->exp);
    aux=aux->sig;
  }
  printf("\n");
}

int contarMonomios(monomio *cabeza) {
  int nele=0;
  monomio *aux=NULL;
  aux=cabeza;

  while(aux!=NULL)
  {
    nele++;
    aux=aux->sig;
  }

  return nele;
}

void valores(monomio *cabeza) {
  monomio *aux=NULL;
  float res=0;

  for(float i=0; i<=5; i+=0.5) //i+=0.5 equivale a i=i+0.5
  {
    aux=cabeza;
    while(aux!=NULL)
    {
      res+=aux->coef*pow(i, aux->exp);
      aux=aux->sig;
    }
    printf("x = %.2f, y = %.2f\n", i, res);
  }
  printf("\n");
}

void eliminarMonomio(monomio **cabeza, int exp) {
  monomio *aux=NULL, *ant=NULL;
  aux=*cabeza;

  while(aux->exp != exp)
  {
    ant=aux;
    aux=aux->sig;
  }
  if(aux==*cabeza) {
    *cabeza = aux->sig;
    free(aux);
  } else {
    ant->sig=aux->sig;
    free(aux);
  }
}
