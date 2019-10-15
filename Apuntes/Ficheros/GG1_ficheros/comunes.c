#include "cabecera.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/********************************************************************/
struct DatosPersonales introducirDatosPersonales()
{
 struct DatosPersonales aux;

 /*Introduccion de datos */
 printf("DNI : ");
 scanf("%ld", &aux.dni);
 getchar();

 printf("Nombre : ");
 fgets(aux.nombre, MAX_LINEA, stdin);
 limpiarLinea(aux.nombre);

 printf("Apellido :");
 fgets(aux.apellido, MAX_LINEA, stdin);
 limpiarLinea(aux.apellido);

 printf("Salario:");
 scanf("%f", &aux.salario);
 getchar();

 /* devolucion de los datos de la persona */
 return aux;
}

/********************************************************************/
void escribirDatosPersonales(struct DatosPersonales aux)
{
 printf("DNI: %ld\n\tNombre: %s  Apellido: %s  Salario: %.3f\n",
         aux.dni, aux.nombre, aux.apellido, aux.salario);
}

/********************************************************************/
int existeFichero(char *fichero)
{
 FILE *pFichero;

 pFichero = fopen(fichero, "r"); /* abre fichero para lectura */
 if (pFichero == NULL) /* el fichero no existe */
  {
   return 0;
  }
 else /* el fichero existe */
  {
   fclose (pFichero);
   return 1;
  }
}

/********************************************************************/
long contarBytes(char *fichero)
{
  FILE* f;
  long tam;

  if((f=fopen(fichero, "r"))==NULL)
  {
    fprintf(stderr, "\nError: no puedo abrir <%s>", fichero);exit(-1);
  }
  if(fseek(f, 0L, SEEK_END))
  {
    fprintf(stderr, "\nError: no puedo usar <%s>", fichero); exit(-1);
  }
  tam = ftell(f);
  fclose(f);
  return(tam);
}

/********************************************************************/
struct DatosPersonales* reservarVector(long nEle)
{
	struct DatosPersonales* V=NULL;

	if((V=(struct DatosPersonales*)malloc(nEle*sizeof(struct DatosPersonales)))==NULL)
	{
		printf("\nError: No se ha podido reservar la memoria");
		exit(-1);
	}
	return(V);
}

/********************************************************************/
void liberarVector(struct DatosPersonales** V)
{
   free(*V);
   *V=NULL;
}

/*******************************************************************/


/********************************************************************/
void limpiarLinea(char* linea)
{
  if(linea[strlen(linea)-1]=='\n')
     linea[strlen(linea)-1] = '\0';
}
