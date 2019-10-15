#include <stdio.h>
#include "cabecera.h"

int main()
{
    char nombreFichero[MAX_LINEA];
    int encontrado;
    struct DatosPersonales p;
    int i, nEle=3;
    
    printf("\nIntroducir el nombre del fichero: ");
    scanf("%s", nombreFichero);

/*
    for(i=0; i<nEle; i++)
    {	
       printf("\nIntroducir datos de nuevo cliente (%d):\n", i);
       p = introducirDatosPersonales();
       anadirRegistro(nombreFichero, p);
    }
*/ 
   
    verFichero(nombreFichero);
   
    printf("\nEl fichero <%s> tiene %ld registros", nombreFichero, contarRegistros(nombreFichero));    

/*   
    encontrado = buscarporDni(nombreFichero, 1111, &p);
    if(encontrado)
      escribirDatosPersonales(p);
*/    
    encontrado = borrarporDni(nombreFichero, 8888);
    if(encontrado)
       printf("\nCliente borrado con exito\n");
    else
       printf("\nEl cliente no se ha encontrado y no se puede borrar\n");  
  
    encontrado = borrarporDni(nombreFichero, 2222);
    if(encontrado)
       printf("\nCliente borrado con exito\n");
    else
       printf("\nEl cliente no se ha encontrado y no se puede borrar\n");   
    
    //printf("\nIntroducir datos de nuevo cliente (%d):\n", i);
    //p = introducirDatosPersonales();
    //anadirRegistro(nombreFichero, p);    
   
    encontrado = actualizarporDni(nombreFichero, 3333);
    if(encontrado)
       printf("\nFichero actualizado con exito ");
    verFichero(nombreFichero);    
    return 0;    
}
