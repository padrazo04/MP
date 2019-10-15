#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplica(char *origen);

int main() {
  char origen[10];
  char *destino;
  printf("Introduce la cadena origen: ");
  fgets(origen, 10, stdin);
  origen[strlen(origen)-1]='\0';
  destino=duplica(origen);

  printf("Origen: <%s> Longitud: %lu\n",origen, strlen(origen));
  printf("Destino: <%s> Longitud: %lu\n",destino, strlen(destino));
  free(destino);
  return 0;
}

char* duplica(char* origen) {
  char *ptr;
  ptr=(char*)malloc(sizeof(char*)*(strlen(origen)));  //+1 para el '\0'
  if(ptr==NULL) {
    printf("Error en la reserva de memoria\n");
    ptr=0;
  } else strcpy(ptr, origen);
  return ptr;
}
