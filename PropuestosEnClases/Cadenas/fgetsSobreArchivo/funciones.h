#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    int edad;
}t_persona;

int crearLoteDePrueba();
int pasarABin();
void mostrarBin();

#endif // FUNCIONES_H_INCLUDED
