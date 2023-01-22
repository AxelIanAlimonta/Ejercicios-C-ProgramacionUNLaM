#include "menuMatriz.h"

void mostrarMatriz(int mat[][COLUM],int fil,int col)
{
    int i,j;
    for(i=0; i<fil; i++)
    {
        printf("\n");
        for(j=0; j<col; j++)
        {
            printf("%4i",mat[i][j]);
        }
    }
}

void diagonalPrincipal(int mat[][COLUM],int tamMat)
{
    int i;
    for(i=0; i<tamMat; i++)
    {
        printf("%4i",mat[i][i]);
    }
}

void diagonalSecundaria(int mat[][COLUM],int tamMat)
{
    int i,j=0;
    for(i=tamMat-1; i>=0; i--)
    {
        printf("%4i",mat[i][j]);
        j++;
    }
}

void triangularSuperiorConDiagPrin(int mat[][COLUM],int tamMat)
{
    int i,j;
    for(i=0; i<tamMat; i++)
    {
        for(j=i; j<tamMat; j++)
        {
            printf("%4i",mat[i][j]);
        }
    }
}

void triangularSuperiorSinDiagPrin(int mat[][COLUM],int tamMat)
{
    int i,j;
    for(i=0; i<tamMat-1; i++)
    {
        for(j=i+1; j<tamMat; j++)
            printf("%4i",mat[i][j]);
    }
}

void triangularSuperiorConDiagSecund(int mat[][COLUM],int tamMat)
{
    int i,j;
    for(i=0; i<tamMat; i++)
    {
        for(j=0; j<tamMat-i; j++)
            printf("%4i",mat[i][j]);

    }
}
