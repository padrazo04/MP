#include <stdio.h>
#include <string.h>
#define MAX 50

int es_prefijo(char *cadena, char *prefijo);
int es_sufijo(char *cadena, char *sufijo);

int main(int argc, char const *argv[]) {
  char cad1[50], cad2[50];
  printf("Introduzca la cadena 1: ");
  fgets(cad1, MAX, stdin);
  cad1[strlen(cad1)-1]='\0';
  printf("Introduzca la cadena 2: ");
  fgets(cad2, MAX, stdin);
  cad2[strlen(cad2)-1]='\0';
  if(es_prefijo(cad1, cad2)==1)
    printf("\nLa cadena %s es prefijo de %s\n", cad2, cad1);
  else printf("\nLa cadena %s no es prefijo de %s\n", cad2, cad1);

  if(es_sufijo(cad1, cad2)==1)
    printf("\nLa cadena %s es sufijo de %s\n\n", cad2, cad1);
  else printf("\nLa cadena %s no es sufijo de %s\n\n", cad2, cad1);

  return 0;
}

int es_prefijo(char *cadena, char *prefijo){
  if(strlen(cadena)<strlen(prefijo))
    return 0;
  for(int i=0; i<strlen(prefijo); i++)
    if(cadena[i]!=prefijo[i])
      return 0;
  return 1;
}

int es_sufijo(char *cadena, char *sufijo){
  if(strlen(cadena)<strlen(sufijo))
    return 0;
  int dif=strlen(cadena)-strlen(sufijo);
  for(int i=0; i<strlen(sufijo); i++)
    if(cadena[i+dif]!=sufijo[i])
      return 0;
  return 1;
}
