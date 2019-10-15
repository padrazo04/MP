#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define TAM 10

void seleccion(int n, char **v) {
  int menor;
  char aux1[MAX];
  for(int i=0; i<n-1;i++) {
      menor=i;
      for(int k=i+1; k<n; k++)
        if(strcmp(v[k],v[menor])<0)
          menor=k;
      strcpy(aux1,v[menor]);
      strcpy(v[menor],v[i]);
      strcpy(v[i],aux1);
  }
}

int main() {
  char *v[10];
  for(int i=0; i<10; i++) {
    v[i]=(char *)malloc(TAM*sizeof(char));
    if(v[i]==NULL) {
      printf("Error");
      exit(-1);
    }
  }
  for(int i=0; i<10; i++) {
    printf("Introduce la posicion %d del vector: ",i+1);
    fgets(v[i], MAX, stdin);
    v[i][strlen(v[i])-1]='\0';
  }
  printf("VECTOR ANTES DE ORDENAR\n");
  for(int i=0; i<10; i++)
    printf("v[%d]: %s\n",i, v[i]);
  seleccion(10, v);
  printf("VECTOR DESPUES DE ORDENAR\n");
  for(int i=0; i<10; i++)
    printf("v[%d]: %s\n",i, v[i]);
}
