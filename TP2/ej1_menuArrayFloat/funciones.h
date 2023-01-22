#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int desplegarMenu(float *vec,int cantElem);
int ingresarDatos(float*vec,int cantMaxElem);
float minimoElemento(float*vec,int cantElem);
float promPosPares(float *vec,int cantElem);
void mostrarInverso(float*vec,int cantElem);
int grabarArchivo(float* vec,int cantElem);

#endif // FUNCIONES_H_INCLUDED
