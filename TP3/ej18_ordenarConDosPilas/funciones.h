#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int crearLoteDePruebas(const void*nomArch);
void apilarDato(int dato,t_pila*pila1,t_pila*pila2);
int compararEnteros(int n1,int n2);
void juntarPilasMenorAMayor(t_pila*pila1,t_pila*pila2);

#endif // FUNCIONES_H_INCLUDED
