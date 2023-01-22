#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#define NOM_ARCH_1 "datos1.bin"
#define NOM_ARCH_2 "datos2.bin"
#define ARCH_LOTE "lote.bin"

typedef struct
{
    int codProd;
    unsigned cantProd;
}t_producto;

int crearLoteDePrueba(const void*archLote);
int crearDatos1(const void*lote,const void *nomArch1);
int crearDatos2(const void*lote,const void *nomArch1);
int compararProductos(const void*,const void*);
int mostrarArchProd(const void*nomArch);

#endif // FUNCIONES_H_INCLUDED
