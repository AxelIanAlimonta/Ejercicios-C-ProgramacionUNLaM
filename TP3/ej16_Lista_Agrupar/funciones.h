#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} t_fecha;

typedef struct
{
    int cod;
    char descripcion[50];
    int cantidad;
    float precio;
    t_fecha fechaVenc;
} t_prod;

int crearLoteDePrueba(const char*lotes);
int cargarListaDesdeArchivo(t_lista*lista,const char*nomArch);
int compararProductos(const void*prod1,const void*prod2);
void agruparProductos(void*info,const void*dato);
int compararFechas(t_fecha*,t_fecha*);
int compararCodProd(const void*prod1,const void*prod2);
void informarYGrabarErrores(void*dato,FILE*pf);
void mostrarProd(void*prod);


#endif // FUNCIONES_H_INCLUDED
