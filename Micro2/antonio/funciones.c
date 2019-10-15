#include "funciones.h"

int compruebaFichero(char *nombreFichero, char *nombreFichero1);
int actualizaFichero(char *nombreFichero, int cod);

int compruebaFichero(char *nombreFichero, char *nombreFichero1)
{
    FILE *pf;
    pf=fopen(nombreFichero, "r");
    FILE *pa;
    pa=fopen(nombreFichero1, "r");
    if((pf==NULL)||(pa==NULL))
      return 0;
    else
    fclose(pf);
    fclose(pa);
    return 1;

}

int fusionficheros(char *nombreFichero, char *nombreFichero1)
{
  FILE *pf;
  pf=fopen(nombreFichero, "r");
  FILE *pa;
  pa=fopen(nombreFichero1, "r");
  FILE *pt;
  pt=fopen("ficheromicro.txt", "w");
  if(pt==NULL){
    printf("Error al abrir el fichero.\n" );
    return 0;
  }
  else{
    printf("Fichero comprobado.\n" );
  }
  char nombre[100], nombre1[100];
  int codigo=0, codigo1=0;
  float precio=0,precio1=0;
  int unidades=0, unidades1=0;
  while(feof(pf)==0){
    fscanf(pf,"%s %d %f %d",nombre,&codigo,&precio,&unidades);
    fprintf(pt, "%s %d %f %d\n",nombre,codigo,precio,unidades);
  }
  while(feof(pa)==0){
    fscanf(pa,"%s %d %f %d",nombre1,&codigo1,&precio1,&unidades1);
    fprintf(pt, "%s %d %f %d\n",nombre1,codigo1,precio1,unidades1);
  }
fclose(pf);
fclose(pa);
fclose(pt);
return 1;
}
