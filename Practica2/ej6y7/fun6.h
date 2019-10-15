/**
  @file fun6.h
  @author Charli
  @date 3-05-2018
  @version 1.0.0
  @brief Fichero de cabecera con los prototipos de las funciones
*/

#ifndef FUN6_H

#define FUN6_H  ///<Definimos la libreria fun6.h
int **reservaMemoria(int nFil, int nCol);
void rellenaMatriz(int **matriz, int nFil, int nCol);
void imprimeMatriz(int **matriz, int nFil, int nCol);
int *minCol(int **matriz, int nFil, int nCol);
void liberaMemoria(int ***matriz, int nFil);

#endif
