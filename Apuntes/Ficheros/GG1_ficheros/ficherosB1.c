#include <stdio.h>
#include "cabecera.h"


long contarRegistros(char *fichero)
{
    FILE* f;
    long tam;

    f = fopen(fichero, "rb");
    fseek(f, 0L, SEEK_END);
    tam = ftell(f);
    fclose(f);

    return tam/sizeof(struct DatosPersonales);
}

void anadirRegistro(char *fichero, struct DatosPersonales persona)
{
    FILE* f;

    f = fopen(fichero, "ab");
    fwrite(&persona, sizeof(struct DatosPersonales), 1, f);

    fclose(f);
}


void verFichero(char *nombreFichero)
{
	FILE* f;
	int nEle, i;
	struct DatosPersonales * V;


	nEle = contarRegistros(nombreFichero);
	V = reservarVector(nEle);
	f = fopen(nombreFichero, "rb");
	fread(V, sizeof(struct DatosPersonales), nEle, f);
	fclose(f);

    for(i=0; i<nEle; i++)
    {
    	escribirDatosPersonales(V[i]);
	}

  liberarVector(&V);
}

/*
void verFichero(char *nombreFichero)
{
    FILE* f;
    struct DatosPersonales p;

    f = fopen(nombreFichero, "rb");

    while(fread(&p, sizeof(struct DatosPersonales), 1, f) == 1)
    {
         escribirDatosPersonales(p);
    }

    fclose(f);
}
*/

int borrarporDni(char *nombreFichero, long dni)
{
    FILE *f1, *f2;
    struct DatosPersonales p;
    int encontrado = 0;

    f1=fopen(nombreFichero, "rb");
    f2=fopen("temporal.bin", "wb");

    while(fread(&p, sizeof(struct DatosPersonales), 1, f1)==1)
    {
        if(dni!=p.dni)
          fwrite(&p, sizeof(struct DatosPersonales), 1, f2);
        else
          encontrado = 1;
    }


    fclose(f1);
    fclose(f2);

    remove(nombreFichero);
    rename("temporal.bin", nombreFichero);

    return encontrado;
}



int actualizarporDni(char* nombreFichero, long dni)
{
   FILE* f;
   int encontrado = 0;
   struct DatosPersonales p;

   f = fopen(nombreFichero, "r+b");
   while(fread(&p, sizeof(struct DatosPersonales), 1, f)==1)
   {
       if(dni == p.dni)
       {
         p = introducirDatosPersonales();
         fseek(f, -1*sizeof(struct DatosPersonales), SEEK_CUR);
         fwrite(&p, sizeof(struct DatosPersonales), 1, f);
         fflush(f);
         encontrado = 1;
       }
   }


   fclose(f);
   return encontrado;

}
