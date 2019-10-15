#include <stdio.h>
#include <stdlib.h>

int main() {
  char c, *cad=NULL;
  int nEle=0, i;
  //Lee una cadena caracter a caracter utilizando realloc
  while((c=getchar())!='\n') {
    cad = (char*) realloc (cad, (nEle+1)*sizeof(char));
    cad[nEle]= c;
    nEle++;
  }
  //Añade el '\0'
  cad = (char*) realloc (cad, (nEle+1)*sizeof(char));
  cad[nEle]='\0';
  printf("\nLa cadena leida es <%s>\n",cad);
  return 0;
}
