#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

char **creaVectorCadenas(char *cad, int n);
int numEspacios(char *cad);
void length(char **cad, int n, float *med, int *mayor, int *menor);
int *freqlength(char **cad, int n, int mayor);

int main () {
  char cad[MAX], **vectcad;
  int n, mayor, menor;
  float med;
  printf("Introduzca una frase: ");
  fgets(cad, MAX, stdin);
  cad[strlen(cad)-1]='\0';
  printf("\n%s\n",cad);
  n=numEspacios(cad);

  vectcad=creaVectorCadenas(cad, n);
  length(vectcad, n, &med, &mayor, &menor);
  printf("\nLongitud media: %.2f\n",med);
  printf("Longitud mayor: %d\n", mayor);
  printf("Longitud menor: %d\n",menor);
  int *v=freqlength(vectcad, n, mayor);
  printf("\nFRECUENCIA DE APARICION DE CADA LONGITUD:\n");
  for(int i=0; i<mayor; i++)
    printf("Longitud = %d ; aparece %d veces\n", i+1, v[i]);
}

char **creaVectorCadenas(char *cad, int n) {
  char **aux;
  int i=0;
  aux=(char **)malloc((n+1)*sizeof(char *));  //Los castings no son obligatorios
  aux[i]=strtok(cad, " ");
  while(i<=n) {
    printf( "Trozo : %s \n", aux[i]);
    i++;
    aux[i] = strtok( NULL, " ");
  }
  return aux;
}

int numEspacios(char *cad) {
	int nEsp=0;
	for(int i=0; cad[i]!='\0'; i++)
		if((isspace(cad[i]))!=0)
			nEsp++;
	return nEsp;
}

void length(char **cad, int n, float *med, int *mayor, int *menor) {
  *mayor=0;
  *menor=MAX;
  for(int i=0; i<=n; i++) {
    *med+=strlen(cad[i]);
    if(*mayor<strlen(cad[i]))
      *mayor=strlen(cad[i]);
    if(*menor>strlen(cad[i]))
      *menor=strlen(cad[i]);
  }
  *med/=n+1;
}

int *freqlength(char **cad, int n, int mayor) {
  int *aux;
  aux=(int *)malloc(mayor*sizeof(int));   //ERROR DE EJECUCIÓN para "Hola a todos"
  for(int i=0; i<mayor; i++)
    for(int j=0; j<=n; j++) {
      //printf("CADENA: %s\tLONGITUD: %lu\n",cad[j], strlen(cad[j]));
      if((i+1)==strlen(cad[j]))
        aux[i]++;
    }
  return aux;
}
