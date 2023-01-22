#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    float promedio;
}t_estudiante;

int crearLoteDePrueba(const char*nomArch);
int pasarDeTxtABin(const char*NOM_ARCH_TXT,const char*NOM_ARCH_BIN);
void desglosarLinea(char*cad,t_estudiante*datoEst);
int mostrarBin(const char*NOM_ARCH_BIN);



#endif // FUNCIONES_H_INCLUDED
