#include <stdio.h>
#include <string.h>
#define MAX 30

int cuentaltras (char *cad, char c, int pos);

int main() {
  char cad[MAX], c;
  printf("Introduce una cadena: ");
  fgets(cad, MAX, stdin);
  cad[strlen(cad)-1]='\0';
  printf("Letra a buscar: ");
  scanf("%c",&c);

  printf("La letra <%c> aparece en <%s> --> %d veces\n", c, cad, cuentaltras(cad, c, 0));

}

int cuentaltras (char *cad, char c, int pos) {
  if(pos==strlen(cad))
    return 0;
  else if(cad[pos]==c)
      return 1+cuentaltras(cad, c, pos+1);
  else return cuentaltras(cad, c, pos+1);
}
