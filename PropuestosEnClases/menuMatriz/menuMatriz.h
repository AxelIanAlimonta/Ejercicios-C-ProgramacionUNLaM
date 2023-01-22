#ifndef MENUMATRIZ_H_INCLUDED
#define MENUMATRIZ_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define FILAS 5
#define COLUM 5

void mostrarMatriz(int mat[][COLUM],int fil,int col);
void diagonalPrincipal(int mat[][COLUM],int tamMat);
void diagonalSecundaria(int mat[][COLUM],int tamMat);
void triangularSuperiorConDiagPrin(int mat[][COLUM],int tamMat);
void triangularSuperiorSinDiagPrin(int mat[][COLUM],int tamMat);
void triangularSuperiorConDiagSecund(int mat[][COLUM],int tamMat);


#endif // MENUMATRIZ_H_INCLUDED
