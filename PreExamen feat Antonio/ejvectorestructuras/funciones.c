#include "funciones.h"

struct ficha *reservaMemoria(int nele) {
  Ficha *v;
  v=(struct ficha *)malloc(nele*sizeof(struct ficha));
  if (v==NULL) {
    printf("Error en la reserva de memoria\n");
    return 0;
  }
  return v;
}

void rellenaVector(struct ficha *v, int nele){
  for(int i=0; i<nele; i++) {
    printf("Introduce el nombre: ");
    getchar();
    fgets(v[i].nombre, MAX, stdin);
    printf("Introduce la edad: ");
    scanf("%d", &v[i].edad);
    printf("Introduce el peso: ");
    scanf("%d", &v[i].peso);
  }
}

void muestraVector(struct ficha *v, int nele){
  for(int i=0; i<nele; i++) {
    printf("Nombre: %sEdad:%d\nPeso: %d\n", v[i].nombre, v[i].edad, v[i].peso);
  }
}

float mayores65(struct ficha *v, int nele) {
  float media=0, cont=0;
  printf("\nMAYORES 65:\n");
  for(int i=0; i<nele; i++) {
    media+=v[i].edad;
    if(v[i].edad>65) {
      printf("Nombre: %sEdad:%d\nPeso: %d\n", v[i].nombre, v[i].edad, v[i].peso);
      cont++;
    }
  }
  if(cont==0) return 0;
  else media/=cont;
  return media;
}

void liberaMemoria(struct ficha *v) {
  free(v);
}
