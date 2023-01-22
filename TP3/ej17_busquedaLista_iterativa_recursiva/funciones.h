#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    float precio;
}t_prod;

int compararProd(const void*,const void*);
int compararCodigos(const void*,const void*);
void recuperarProd(void*clave,const void*dato);
int mostrarCodClave(t_prod*clave);
void mostrarProd(void*);

#endif // FUNCIONES_H_INCLUDED
