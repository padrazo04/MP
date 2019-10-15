#include <stdio.h>
#include <string.h>

int main () {
  char cadena[10];
  printf("Prueba scanf: ");
  scanf("%s",cadena);
  printf("CADENA: %s LONGITUD: %lu\n",cadena, strlen(cadena));

  printf("Prueba gets: ");
  getchar();
  gets(cadena);
  printf("CADENA: %s LONGITUD: %lu\n",cadena, strlen(cadena));

  printf("Prueba fgets: ");
  fgets(cadena, 10, stdin);
  printf("CADENA: %s LONGITUD: %lu\n",cadena, strlen(cadena));
}
