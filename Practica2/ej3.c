#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ficha_jugador {
  char nombre[50];
  int dorsal;     // Nº Entero
  float peso;     // Expresado en kilos
  int estatura;   // Expresado en centimetros
};

void reservaVectorJugadores(struct Ficha_jugador **m, int nEle);
struct Ficha_jugador nuevoJugador();
void rellenaVectorJugadores(struct Ficha_jugador *m, int nEle);
void listarJugadores(struct Ficha_jugador *m, int nEle);
int borrarJugadores(struct Ficha_jugador **m, int nEle, char a);
void liberaVectorJugadores(struct Ficha_jugador *m, int nEle);

int main() {
  int n;
  char a;
  struct Ficha_jugador *lista;
  printf("Numero de Jugadores: ");
  scanf("%d",&n);

  reservaVectorJugadores(&lista, n);
  rellenaVectorJugadores(lista, n);
  listarJugadores(lista, n);
  printf("Introduzca un carácter para eliminar jugadores: ");
  scanf("%c",&a);
  getchar();  
  n=borrarJugadores(&lista, n, a);
  listarJugadores(lista, n);
  liberaVectorJugadores(lista, n);
}

void reservaVectorJugadores(struct Ficha_jugador **m, int nEle) {
  *m=(struct Ficha_jugador *)malloc(nEle*sizeof(struct Ficha_jugador));
  if(*m==NULL)
    printf("Error en la reserva de memoria");
  else printf("Memoria reservada correctamente\n\n");
}

struct Ficha_jugador nuevoJugador() {
  struct Ficha_jugador aux;
  printf("Introduzca el nombre del jugador: ");
  getchar();  // Si se quita no deja introducir el nombre
  fgets(aux.nombre, 50, stdin);
  aux.nombre[strlen(aux.nombre)-1]='\0';
  printf("Introduzca el dorsal: ");
  scanf("%d", &aux.dorsal);
  printf("Introduzca el peso: ");
  scanf("%f", &aux.peso);
  printf("Introduzca la estatura: ");
  scanf("%d", &aux.estatura);

  return aux;
}

void rellenaVectorJugadores(struct Ficha_jugador *m, int nEle) {
  for(int i=0; i<nEle; i++) {
    m[i]=nuevoJugador();
    printf("\n");
  }
}

void listarJugadores(struct Ficha_jugador *m, int nEle) {
  for(int i=0; i<nEle; i++) {
    printf("Nombre: %s\n", m[i].nombre);
    printf("Dorsal: %d\n", m[i].dorsal);
    printf("Peso: %.2f\n", m[i].peso);
    printf("Estatura: %d\n", m[i].estatura);
    printf("\n");
  }
}

int borrarJugadores(struct Ficha_jugador **m, int nEle, char a) {
  struct Ficha_jugador aux;
  int cont=0;
  for(int i=0; i<nEle; i++)
    if( strchr((*m+i)->nombre, a) != NULL )
      cont++;
  for(int i=0; i<nEle; i++)
    if( strchr((*m+i)->nombre, a) != NULL )
      for(int j=i; j<nEle; j++)
        if(strchr((*m+j)->nombre, a) == NULL) {
          aux=(*m)[i];
          (*m)[i]=(*m)[j];
          (*m)[j]=aux;
        }
  *m=(struct Ficha_jugador *)realloc(*m, (nEle-cont)*sizeof(struct Ficha_jugador));
  printf("\nJugadores eliminados\n\n");
  return (nEle-cont);
}

void liberaVectorJugadores(struct Ficha_jugador *m, int nEle) {
  free(m);
  printf("Memoria liberada correctamente\n");
}
