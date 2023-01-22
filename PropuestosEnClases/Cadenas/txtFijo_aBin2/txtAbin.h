#ifndef TXTABIN_H_INCLUDED
#define TXTABIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned dni;
    char apellido[31];
    char nombre[31];
    float nota;
}t_alum;

int crearLoteDePrueba(const char*NOM_ARCH_TXT);
int pasarDeTxtABin(const char*NOM_ARCH_TXT,const char*NOM_ARCH_BIN);
int mostrarAlumnosBin(const char*NOM_ARCH_BIN);


#endif // TXTABIN_H_INCLUDED
