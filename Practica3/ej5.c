#include <stdio.h>

int sumaDigitos(int num);

int main(int argc, char const *argv[]) {
  int n;
  printf("Vamos a sumar los digitos de este numero --> ");
  scanf("%d", &n);
  printf("La suma de los digitos de %d es %d\n", n, sumaDigitos(n));
  return 0;
}

int sumaDigitos(int num) {
if(num<10)
  return (num);
else return(num%10+sumaDigitos(num/10));
}
