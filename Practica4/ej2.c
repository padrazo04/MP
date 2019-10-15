#include <stdio.h>

typedef struct Ficha_alumno {
  char nombre[50];
  int DNI;
  float nota;
} alumno;

alumno *reservaVector(int n);
void rellenaVector(alumno *v, int n);
void verVector(alumno *v, int n);
void ordenaVector(alumno *v, int n, int (*orden)(int, int));
int ascendente(int a, int b);
int descendente(int a, int b);
void liberaVector(alumno *v);

int main(int argc, char *argv[]) {
  int n, opc, (*orden)(int, int);
  printf("Introduce el numero de alumnos: ");
  scanf("%d", &n);
  getchar();

  alumno *clase=reservaVector(n);
  rellenaVector(clase, n);
  printf("Introduce el sentido de ordenacion\n1. Ascendente\n2. Descendente\nOPC: ");
  scanf("%d", &opc);
  if(opc==1) orden=&ascendente;
  else orden=&descendente;
  ordenaVector(v, n, orden);
  verVector(v, n);
  liberaVector(v);
}

alumno *reservaVector(int n) {

}
void rellenaVector(alumno *v, int n) {

}
void verVector(alumno *v, int n) {

}
void ordenaVector(alumno *v, int n, int (*orden)(int, int)) {

}
int ascendente(int a, int b) {

}
int descendente(int a, int b) {

}
void liberaVector(alumno *v) {
  
}
