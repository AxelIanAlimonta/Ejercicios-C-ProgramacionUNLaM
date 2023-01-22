#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "Arbol.h"

typedef struct
{
    int cod;
    int stock;
}t_prod;

typedef struct
{
    int idx;
    int cod;
}t_idx;


//void mostrarEnteroEnArbol(const void*dato,int despl);
//int compararEnteros(const void*,const void*);
//void mostrarEnteros(const void*nro);

void mostrarProdEnArbol(const void*dato,int despl);
void mostrarProd(const void*prod);
int compararCodProd(const void*prod1,const void*prod2);

int compararIdx(const void*,const void*);
void mostrarIdxEnArbol(const void*dato,int despl);

int  crearLoteDePruebas(const char*nombArch);
int generarArbolDesdeArchivo(t_arbol*arbol,FILE*pf);

void grabar(FILE*orig,FILE*orden,const void*dato);


#endif // FUNCIONES_H_INCLUDED
