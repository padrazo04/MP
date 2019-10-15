#include "funciones.h"

int compruebaFichero(char *nombreFichero);
int actualizaFichero(char *nombreFichero, int cod);
void verFichero(char *nombreFichero);

int compruebaFichero(char *nombreFichero)
{
    FILE *f;
    f=fopen(nombreFichero, "rb");
    if(f==NULL)
      return 0;
    else fclose(f);
    return 1;
}

int actualizaFichero(char *nombreFichero, int cod)
{
  FILE *f1;
  f1=fopen(nombreFichero, "r+b");
  if(f1==NULL)
    printf("Eror\n");
  struct producto aux;
  int found=0;
  while(fread(&aux, sizeof(struct producto), 1, f1)==1)
  {
    printf("%d\t%d\n",aux.cod, cod);
    if(cod==aux.cod) {
      found=1;
      fseek(f1, -(int)sizeof(struct producto), SEEK_CUR);
      printf("Introduce el nuevo precio: ");
      scanf("%f", &aux.price);
      fwrite(&aux, sizeof(struct producto), 1, f1);
      fflush(f1);
    }
  }
  fclose(f1);
  return found;
}
