#ifndef ARCHIVOSBIN_H_INCLUDED
#define ARCHIVOSBIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>




typedef struct
{
    unsigned dni;
    char NyA[50];
    float notaFinal;
}t_alumno;

int grabarArchivo(const char*nomArch);
void ingresarDatos(t_alumno*datosIngresados);
void eliminarSaltoDeLinea(char*linea);
int leerArchivo(const char*nomArch);

#endif // ARCHIVOSBIN_H_INCLUDED
