#include <stdio.h>
#include "cabecera.h"
#include <stdlib.h>

void verFichero(char *nombreFichero)
{
FILE *pFichero;
 struct DatosPersonales persona;

 if((pFichero = fopen(nombreFichero, "r"))==NULL)
 {   printf("\nError al abrir fichero <%s>", nombreFichero);
     exit -1;   
 }
                                                         
 while (fscanf(pFichero, "%ld%s%s%f", &persona.dni, persona.nombre,
               persona.apellido, &persona.salario)==NUM_CAMPOS)
 {
    escribirDatosPersonales(persona);
 }
 
 fclose(pFichero);  
}


long contarRegistros(char *nombreFichero)
{
 FILE *pFichero;
 long nRegistros=0;
 struct DatosPersonales persona;

 pFichero = fopen(nombreFichero, "r"); 
 

  /*  Tambien serviría un while (fscanf(...)!=EOF) */
  while (fscanf(pFichero, "%ld%s%s%f", &persona.dni, persona.nombre,
                persona.apellido, &persona.salario)==NUM_CAMPOS)          
  {
    nRegistros++;
  }
  
 fclose(pFichero);
 return(nRegistros);
}


int buscarporDni(char *nombreFichero, long dni, struct DatosPersonales *p)
{
 FILE *pFichero;
 int encontrado = 0; 
 int cont;
 struct DatosPersonales auxiliar;

 pFichero = fopen(nombreFichero, "r");     
 
 /*evaluacion en cortocircuito*/
 while (!encontrado && (fscanf(pFichero, "%ld%s%s%.3f",
        &auxiliar.dni, auxiliar.nombre, auxiliar.apellido,
	      &auxiliar.salario) == NUM_CAMPOS))
  {
    if (auxiliar.dni == dni) 
     {
      encontrado = 1;
      *p = auxiliar; 
     }
   }
 fclose(pFichero); 
 return encontrado;
}

int borrarporDni(char *fichero, long dni)
{
     FILE *f1, *f2;
     struct DatosPersonales auxiliar;
     int encontrado = 0;
      
     f1 = fopen(fichero, "r");
     f2 = fopen("temporal.txt", "w");
     
     while(fscanf(f1, "%ld%s%s%f", &auxiliar.dni, auxiliar.nombre,
           auxiliar.apellido, &auxiliar.salario)!=EOF)
     {
        if(auxiliar.dni != dni)
           fprintf(f2, "%ld %s %s %.3f\n", auxiliar.dni, auxiliar.nombre,
           auxiliar.apellido, auxiliar.salario);
        else   
            encontrado=1;
     }
     
     fclose(f1);
     fclose(f2);
 
     remove(fichero);
     rename("temporal.txt", fichero); 
     return encontrado;   
}

void anadirRegistro(char *fichero, struct DatosPersonales persona)
{
    FILE* f;
    
    f=fopen(fichero, "a");
    
    fprintf(f, "%ld %s %s %.3f\n", persona.dni, persona.nombre,
              persona.apellido, persona.salario);
    
    fclose(f);
} 