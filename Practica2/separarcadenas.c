#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char linea[] = "Saludos a la gente";
  char separador[] = " ";

  char *trozo = NULL;

  trozo = strtok( linea, separador);

  while( trozo != NULL ) {
    printf( "Trozo : %s \n", trozo);
    trozo = strtok( NULL, separador);
   }
 }
