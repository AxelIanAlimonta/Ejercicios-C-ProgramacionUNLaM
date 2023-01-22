#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#define NOM_ARCH "alumnos.bin"
#define NOM_ARCH_FINAL "alumnos2.bin"

typedef struct
{
    unsigned dni;
    char NyA[50];
    float notaFinal;
}t_alum;

int crearLoteDePrueba();
int cargarLoteEnPila(t_pila*pila);
int desplegarMenu();
void ejecutarOpcion(int opc,t_pila*pila);
void cargarAlumnoNuevo(t_pila*pila);
void verUltimoAlumno(t_pila*pila);
void sacarUltimoAlumno(t_pila*pila);
void eliminarSaltoDeLinea(char*cad);
void mostrarAlum(t_alum* alum);
#endif // FUNCIONES_H_INCLUDED
