#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char apellido[30];
    char nombre[30];
    float prom;
}t_est;

int crearLoteDePruebas(const char*NOM_ARCH_TXT);
int pasarTxtABin(const char*NOM_ARCH_TXT,const char*NOM_ARCH_BIN);
void desglosarLinea(char*linea,t_est*datos);
void eliminarEspaciosIniciales(char*cad);
int mostrarBin(const char*NOM_ARCH_BIN);


#endif // FUNCIONES_H_INCLUDED
