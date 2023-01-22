#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codProd;
    char descripcion[50];
    int stock;
    float precio;
}t_prod;

void mostrarProd(void*prod);
int compararProd(const void*,const void*);

#endif // FUNCIONES_H_INCLUDED
