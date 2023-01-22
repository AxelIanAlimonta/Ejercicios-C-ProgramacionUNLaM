#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int cargarPilaDesdeArchivo(t_pila*pila,const char*nomArch);
int grabarArchivoDesdePila(t_pila*pila,const char*nomArch);
void sumarPilas(t_pila*pila1,t_pila*pila2,t_pila*pilaSuma);

#endif // FUNCIONES_H_INCLUDED
