#ifndef FUNCIONESVECTORES_H_INCLUDED
#define FUNCIONESVECTORES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM_VEC 100

int desplegarMenu();
int ejecutarOpcion(int opc,int cantElem,int* vec);
void insertarEnPosicion(int cantElem,int*vec);
void mostrarVector(int*vec,int cantElem);
void insertarOrdenado(int*vec,int cantElem);
void eliminarDePosicion(int*vec,int cantElem);
void eliminarPrimeraAparicion(int*vec,int cantElem);
int eliminarTodasLasApariciones(int*vec,int cantElem);

#endif // FUNCIONESVECTORES_H_INCLUDED
