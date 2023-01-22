#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../../libs/dinamica/Pila/Pila.h"

void cargarPila(FILE*archivo,t_pila*pila);
void sumarPilas(t_pila*pila1,t_pila*pila2,t_pila*result);
void grabarArchivo(t_pila*pila,FILE*archivo);


#endif // FUNCIONES_H_INCLUDED
