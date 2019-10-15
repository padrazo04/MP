#include <stdio.h>
#include <stdlib.h>

struct lista {
  int n;
  struct lista *sig;
};

struct lista *nuevoElemento();  //IMPORTANTE
void insertaDelante(struct lista **cabeza, int n);  //IMPORTANTE
void imprimirLista(struct lista *cabeza); //IMPORTANTE
void imprimirListaINVERSO(struct lista *cabeza);
void buscarElemento(struct lista *cabeza, int n); //IMPORTANTE
void insertaDetras(struct lista **cabeza, int n); //IMPORTANTE
void borrarElemento(struct lista **cabeza, int n);  //IMPORTANTE
void borrarElementoRecursivo(struct lista **cabeza, int n);
void borrarLista(struct lista **cabeza);
void borrarListaRecursiva(struct lista **elemento);
void insertarOrden(struct lista **cabeza, int n);
void insertarOrdenRecursivo(struct lista **cabeza, int n);
void ordenarLista(struct lista *cabeza);
int contarElementos(struct lista *cabeza);  //IMPORTANTE

int main() {
  int n, encontrado, ele;
  struct lista *cabeza=NULL, *nuevo;
  printf("Introduce el dato n: ");
  scanf("%d", &n );
  getchar();
  for(int i=0; i<ele; i++) {
    insertaDelante(&cabeza, n);
  }
  imprimirLista(cabeza);

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

void imprimirListaINVERSO(struct lista *cabeza) {
  if (cabeza != NULL)
  {
  imprimirListaINVERSO(cabeza->sig);
  printf(" %d\n", cabeza->n);
  }
}

void buscarElemento(struct lista *cabeza, int n) {
  int found=0;
  struct lista *aux;
  aux=cabeza;
  while (aux != NULL && encontrado ==0)
{
if (aux->n == n)
  encontrado = 1;
else
  aux = aux->sig; }
  return encontrado;
}

void insertaDetras(struct lista **cabeza, int n) {
  struct lista *nuevo=NULL, *aux=NULL;
  nuevo=nuevoElemento();
  nuevo->n=n;
  nuevo->sig=NULL;
  if (*cabeza==NULL)
    *cabeza=nuevo;
  else
  {
    aux=*cabeza;
    while((aux->sig)!=NULL) {
      aux=aux->sig;
    }
    aux->sig=nuevo;
  }
}

void borrarElemento(struct lista **cabeza, int n) {
  struct lista* ant=NULL, *aux=NULL;

  while(aux->n!=n)
  {
    ant=aux;
    aux=aux->sig;
  }

  if(aux==*cabeza)
  {
    *cabeza=aux->sig;
    free(aux);
  }
  else
  {
    ant->sig=aux->sig;
    free(aux);
  }
}

void borrarElementoRecursivo(struct lista **cabeza, int n) {
  struct lista *aux=NULL;
  if((*cabeza)->n != n)
  {
    borrarElementoRecursivo(&((*cabeza)->sig), n);
  }
  else
  {
    aux=*cabeza;
    cabeza=aux->sig;
    free(aux);
  }
}

void borrarLista(struct lista **cabeza) {
  struct lista *aux=NULL, *sig=NULL;

  aux=*cabeza
  while(aux!=NULL)
  {
    sig=aux->sig;
    free(aux);
    aux=sig;
  }
  *cabeza=NULL;
}

void borrarListaRecursiva(struct lista **elemento) {
  if(*elemento!= NULL)
  {
    borrarListaRecursiva(&((*elemento)->sig));
    free(*elemento);
    *elemento=NULL;
  }
}

void insertarOrden(struct lista **cabeza, int n) {
  struct lista *aux=NULL, *ant=NULL, *nuevo=NULL;
  int encontrado=0;

  nuevo=nuevoElemento();
  nuevo->n=n;

  if((*cabeza==NULL) || ((*cabeza)->n > n))
  {
      nuevo->sig=*cabeza;
      *cabeza=nuevo;
  }
  else
  {
    aux=*cabeza;
    while((aux != NULL) && (encontrado==0))
    {
      if(aux->n > n)
        encontrado=1;
      else
      {
        ant=aux;
        aux=aux->sig;
      }
    }
    nuevo->sig=aux;
    ant->sig=nuevo;
  }
}

void insertarOrdenRecursivo(struct lista **cabeza, int n) {
  if((*cabeza == NULL) || ((*cabeza)->n > n))
  {
    struct lista *nuevo=nuevoElemento();
    nuevo->n=n;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
  }
  else insertarOrdenRecursivo(&((*cabeza)->sig),n);
}

void ordenarLista(struct lista *cabeza) {
  struct lista *aux=NULL;
  struct lista *aux1=NULL;
  struct lista *minimo=NULL;
  int minimo_n;
  aux=cabeza;

  while(aux->sig != NULL)
  {
    aux1=aux->sig;
    minimo=aux;
    while(aux1 != NULL)
    {
      if(aux1->n < minimo->n)
        minimo = aux1;
      aux1=aux1->sig;
    }
    minimo_n = minimo->n;
    minimo->n = aux->n;
    aux->n = minimo_n;
    aux=aux->sig;
  }
}

int contarElementos(struct lista *cabeza) {
  struct lista *aux=NULL;
  int nodos=0;
  aux=cabeza;
  while(aux!=NULL)
  {
    aux=aux->sig;
    nodos++;
  }
  return nodos;
}







,
