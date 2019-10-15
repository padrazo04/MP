#ifndef CABECERA_H
#define CABECERA_H

/* Definicion del tipo DatosPersonales */

#define MAX_LINEA 256
#define NUM_CAMPOS 4
#define BORRADO -1

struct DatosPersonales
{
  char nombre[MAX_LINEA];
  char apellido[MAX_LINEA];
  long dni; //clave unica para cada registro
  float salario;  
};

/********************************************************************/
/*
   Nombre: introducirDatosPersonales.
   Tipo: struct DatosPersonales.
   Objetivo: Introducir por teclado los datos de una persona y devolverlos
   en un struct DatosPersonales. En el caso de ficheros de texto de tipo 1 
   no se deberan introducir espacios en blanco.
   
   Parametros de entrada: Ninguno.
   Precondiciones: Ninguna.
   Valor devuelto: Datos de una persona.
*/
struct DatosPersonales introducirDatosPersonales();

/********************************************************************/
/*
   Nombre: escribirDatosPersonales.
   Tipo: void.
   Objetivo: Visualizar por pantalla los datos de una persona almacenados
   en un struct DatosPersonales.
   
   Parametros de entrada: 
      - struct DatosPersonales aux: Datos de una persona.
   Precondiciones: Ninguna.
   Valor devuelto: Ninguno.
*/
void escribirDatosPersonales(struct DatosPersonales aux);

/********************************************************************/
/*
   Nombre: existeFichero.
   Tipo: int.
   Objetivo: Comprueba si un fichero existe.
	     
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
   Precondiciones: Ninguna.
   Valor devuelto: 1 si el fichero existe y 0 si no existe.
*/
int existeFichero(char *fichero);

/*******************************************************************/
/*
   Nombre: contarBytes.
   Tipo: long.
   Objetivo: Cuenta el numero de bytes de un fichero.
	     
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
   Precondiciones: Ninguna.
   Valor devuelto: Numero de bytes del fichero.
*/
long contarBytes(char *fichero);

/*******************************************************************/
/*
   Nombre: reservarVector.
   Tipo: struct DatosPersonales*.
   Objetivo: reservar memoria para un vector de nEle elementos.
	     
   Parametros de entrada: 
      - long nEle: Numero de elementos del vector.
   Valor devuelto: Puntero a la direccion de inicio del vector.
*/
struct DatosPersonales* reservarVector(long nEle);

/*******************************************************************/
/*
   Nombre: liberarVector.
   Tipo: void.
   Objetivo: libera la memoria asignada a un vector de struct DatosPersonales.
	     
   Parametros de entrada: 
      - struct DatosPersonales** V: puntero al vector a liberar.
   Valor devuelto: nada.
*/
void liberarVector(struct DatosPersonales** V);

/*******************************************************************/
/*
   Nombre: limpiarLinea.
   Tipo: void.
   Objetivo: Si existe, elimina el \n al final de una cadena.
	     
   Parametros de entrada: 
      - char* linea: cadena de caracteres.
   Valor devuelto: nada.
*/
void limpiarLinea(char* linea);


/********************************************************************/
/*
   Nombre: verFichero.
   Tipo: void.
   Objetivo: visualizar por pantalla los registros de un fichero.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
   Precondiciones: 
      - El fichero ha de existir.
   Valor devuelto: Ninguno.
   Funciones a las que llama:
      - escribirDatosPersonales.
*/
void verFichero(char *fichero);

/********************************************************************/
/*
   Nombre: contarRegistros.
   Tipo: long
   Objetivo: contar el numero de registros del fichero. 
   En el caso de ficheros binarios con marca de BORRADO, solo se cuentan 
   los registros activos.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
   Precondiciones: 
      -El fichero ha de existir. 
   Valor devuelto: El numero de registros del fichero.
*/
long contarRegistros(char *fichero);

/********************************************************************/
/*
   Nombre: anadirRegistro.
   Tipo: void.
   Objetivo: a�ade un registro al final del fichero.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
      - struct DatosPersonales persona: Datos del registro a a�adir.
   Precondiciones: Ninguna.
   Valor devuelto: Ninguno.
*/
void anadirRegistro(char *fichero, struct DatosPersonales persona);

/********************************************************************/
/*
   Nombre: verRegistro_i.
   Tipo: struct DatosPersonales.
   Objetivo: devolver el registro i_esimo del fichero.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
      - int i: indice del registro a visualizar [1..num_registros]
   Precondiciones: 
      - El fichero ha de existir. 
      - La posicion estar� entre [1..num_registros]
   Valor devuelto: Un struct con el registro i-esimo.
*/
struct DatosPersonales registro_i(char *fichero, long i);

/********************************************************************/
/*
   Nombre: buscarporDni.
   Tipo: int.
   Objetivo: Busca un registro por su dni.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
      - long dni: Dni del registro a buscar.
      - struct DatosPersonales *persona: Datos de la persona buscada.
        En caso de que exista el registro, esta variable lo contiene.
   Precondiciones: 
      - El fichero ha de existir.
   Valor devuelto: 0 si el registro no se encuentra y 1 si se encuentra.
*/
int buscarporDni(char *fichero, long dni, struct DatosPersonales *persona);

/********************************************************************/
/*
   Nombre: mostrarPorNombre.
   Tipo: int.
   Objetivo: Visualiza TODOS los registros que tengan un nombre dado
             por el usuario.
	     
   Parametros de entrada:
      - char *fichero: Nombre del fichero.
      - char *auxNombre: Nombre de los registros a visualizar.
   Precondiciones: 
      - El fichero ha de existir.
   Valor devuelto: 0 si no se encuentra ning�n registro y 1 si se 
                   encuentra alguno.
   Funciones a las que llama:
      - escribirDatosPersonales.
*/
int mostrarporNombre(char *fichero, char *auxnombre);

/********************************************************************/
/*
   Nombre: borrarporDni.
   Tipo: int.
   Objetivo: borra el registro correspondiente a una persona 
         dado su dni, haciendo un volcado de los registros
	     que no se borran a un fichero auxiliar, y renombrando
	     finalmente el auxiliar con el nombre del fichero
	     original.         
	     
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
      - long dni: dni del registro a borrar.
   Precondiciones: Ha de existir el fichero y el registro a borrar.
*/
int borrarporDni(char *fichero, long dni);

/********************************************************************/
/*
   Nombre: actualizarporDNI.
   Tipo: void.
   Objetivo: Actualiza todos los datos de una persona dado su dni. 
        
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
      - long dni: dni del registro a actualizar.
   Precondiciones: Ha de existir el fichero y el registro a actualizar.
   Valor devuelto: Ninguno.
*/
int actualizarporDni(char* fichero, long dni);

/********************************************************************/
/*
   Nombre: ficheroAVector.
   Tipo: struct DatosPersonales*.
   Objetivo: Lee el fichero y pasa los datos a un vector en memoria
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
      - long* nEle: numero de elementos del vector, parametro por referencia.
   Precondiciones: Ha de existir el fichero.
   Postcondiciones: En el caso de ficheros binarios con marca de BORRADO, 
   solo se copian en el vector los registros activos. 
   Valor devuelto: El vector.
   Funciones a las que llama:
      - reservarVector.
      - contar registros.
*/
struct DatosPersonales* ficheroAVector(char* fichero, long* nEle);

/********************************************************************/
/*
   Nombre: vectorAFichero.
   Tipo: void.
   Objetivo: Pasa a un fichero en disco los contenidos del vector en memoria
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
      - struct DatosPersonales*: El vector
      - long* nEle: numero de elementos del vector, parametro por referencia.
   Precondiciones: Ha de existir el fichero.
   Postcondicones: En el caso de ficheros binarios con marca de BORRADO, 
   solo se escriben al fichero los registros activos.
   Valor devuelto: nada.
   Funciones a las que llama:
      - reservarVector.
      - contar registros.
*/
void vectorAFichero(char* fichero, struct DatosPersonales* V, long nEle);

/********************************************************************/
/*
   Nombre: incrementarSalarios.
   Tipo: void.
   Objetivo: Incrementa todos los salarios del fichero una cierta cantidad
   Parametros de entrada: 
      - char *fichero: Nombre del fichero.
      - float incremento: incremento del salario que se sumara al salario actual.
      Si el valor es negativo, se restara al salario.
   Precondiciones: Ha de existir el fichero.
   Valor devuelto: nada.
   Funciones a las que llama:
      - ficheroAVector.
      - vectorAFichero.
      - liberarVector.
*/
void incrementarSalarios(char* fichero, float incremento);

#endif
