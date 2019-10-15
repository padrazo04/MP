#include <stdio.h>
#include <string.h>
#include "cabecera.h"

void verFichero(char *nombreFichero)
{
 FILE *pFichero;
 struct DatosPersonales persona;
 char linea[MAX_LINEA];

 pFichero = fopen(nombreFichero, "r");
  

 while (fgets(linea, MAX_LINEA, pFichero)!=NULL)
  { 

    sscanf(linea, "%ld", &persona.dni);
    
 
    fgets(linea, MAX_LINEA, pFichero);
    limpiarLinea(linea);
    strcpy(persona.nombre, linea);
    

    fgets(linea, MAX_LINEA, pFichero);
    limpiarLinea(linea);
    strcpy(persona.apellido, linea); 
         

    fgets(linea, MAX_LINEA, pFichero);
    sscanf(linea, "%f", &persona.salario);  
    
    escribirDatosPersonales(persona);
  }
 fclose(pFichero);
}


long contarRegistros(char *nombreFichero)
{
     FILE* f;
     char linea[MAX_LINEA];
     int cont=0;
     
      f = fopen(nombreFichero, "r");
      
      while((fgets(linea, MAX_LINEA, f))!=NULL)
      {
           cont++; 
      }
      
           
      fclose(f);
      return cont/NUM_CAMPOS;
}

int borrarporDni(char *fichero, long dni)
{
    FILE *f1, *f2;
    char linea[MAX_LINEA];
    long aux;
    int encontrado=0;
    
    f1=fopen(fichero, "r");
    f2=fopen("temporal.txt", "w");
    
    while(fgets(linea, MAX_LINEA, f1)!=NULL)
    {
         sscanf(linea, "%ld", &aux);
         if(aux!=dni)
         {
            fprintf(f2, "%s", linea);
            
            fgets(linea, MAX_LINEA, f1);
            fprintf(f2, "%s", linea);
            
            fgets(linea, MAX_LINEA, f1);
            fprintf(f2, "%s", linea);
            
            fgets(linea, MAX_LINEA, f1);
            fprintf(f2, "%s", linea);            
         }
         else
         {
            encontrado = 1;
            fgets(linea, MAX_LINEA, f1);
            fgets(linea, MAX_LINEA, f1);
            fgets(linea, MAX_LINEA, f1);
         }         
         
    }
    
    fclose(f1);
    fclose(f2);
    remove(fichero);
    rename("temporal.txt", fichero);
    return(encontrado);
}

void anadirRegistro(char *fichero, struct DatosPersonales persona)
{
    FILE* f;
    
    f = fopen(fichero, "a");

    fprintf(f, "%ld\n%s\n%s\n%.3f\n", persona.dni, persona.nombre,
         persona.apellido, persona.salario);
    
    fclose(f);
}