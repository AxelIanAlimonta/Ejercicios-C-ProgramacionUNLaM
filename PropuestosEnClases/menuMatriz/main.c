#include "menuMatriz.h"

int main()
{
    int mat[FILAS][COLUM]=
    {
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35},
        {41,42,43,44,45},
        {51,52,53,54,55},
    };

    printf("Matriz: ");
    mostrarMatriz(mat,FILAS,COLUM);

    printf("\n\nDiagonal Principal: ");
    diagonalPrincipal(mat,FILAS);

    printf("\nDiagonal Secundaria: ");
    diagonalSecundaria(mat,FILAS);

    printf("\nTriangular Superior con Diagonal Principal: ");
    triangularSuperiorConDiagPrin(mat,FILAS);

    printf("\nTriangular Superior sin Diagonal Principal: ");
    triangularSuperiorSinDiagPrin(mat,FILAS);

    printf("\nTriangular Superior sin Diagonal Principal: ");
    triangularSuperiorSinDiagPrin(mat,FILAS);




    printf("\n");
    return 0;
}
