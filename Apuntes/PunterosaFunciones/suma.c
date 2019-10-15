#include <stdio.h>

int suma(int a, int b);
int resta(int a, int b);
int mult(int a, int b);
int div(int a, int b);
int mod(int a, int b);

int main() {
  int a=10,b=5,
  int res=0;
  int (*pf)(int, int);
  pf=&suma:
  res=(*pf)(a,b);
  printf("SUMA: %d\n",res);
  pf=&resta:
  res=(*pf)(a,b);
  printf("RESTA: %d\n",res);
  pf=&mult:
  res=(*pf)(a,b);
  printf("MULTIPLICACION: %d\n",res);
  pf=&div:
  res=(*pf)(a,b);
  printf("DIVISION: %d\n",res);
  pf=&mod:
  res=(*pf)(a,b);
  printf("MODULO: %d\n",res);
}

int suma(int a, int b) {
  return a+b;
}
int resta(int a, int b) {
  return a-b;
}
int mult(int a, int b) {
  return a*b;
}
int div(int a, int b) {
  return a/b;
}

int mod(int a, int b) {
  return a%b;
}
