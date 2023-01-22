#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char apellido[100];
    char nombre[100];
    unsigned dni;
}t_persona;

typedef struct
{
    t_persona datos;
    double sueldo;
}t_empleado;

typedef struct
{
    t_persona datos;
    float promedio;
}t_estudiante;

int crearLoteDePrueba(const char*nomArchEst,const char*nomArchEmpl);
int actualizarEmpleados(const char*nomArchEst,const char*nomArchEmpl);
int mostrarArchivoEmpleados(const char*nomArch);


#endif // FUNCIONES_H_INCLUDED
