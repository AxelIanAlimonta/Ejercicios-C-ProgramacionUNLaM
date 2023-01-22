#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

typedef struct
{
    int clave;
    int datoRecuperado;
}t_clave;

void mostrarEnteros(const void*nro);
void recuperarEntero(const void*dato,void*clave);
int compararEnteroConClave(const void*nro,const void*clave);

int main()
{
    t_listaC lista;
    int vec[]={1,2,3,3,5},i;
    t_clave clave={3,0};

    crearLista(&lista);

    for(i=0;i<(sizeof(vec)/sizeof(*vec));i++)
        insertarEnListaCircular(&lista,vec+i,sizeof(*vec));

    printf("Lista Original: ");
    recorrerListaCircular(&lista,mostrarEnteros);

    printf("\n\nClave: %i",clave.clave);
    eliminarPorClaveDeListaCircular(&lista,&clave,compararEnteroConClave,recuperarEntero,1);
    printf("\nLista modificada: ");
    recorrerListaCircular(&lista,mostrarEnteros);
    printf("\nClave Recuperada: %i\n\n",clave.datoRecuperado);

    return 0;
}

void mostrarEnteros(const void*nro)
{
    printf("%i ",*(int*)nro);
}



void recuperarEntero(const void*dato,void*clave)
{
    ((t_clave*)clave)->datoRecuperado=*(int*)dato;
}

int compararEnteroConClave(const void*nro,const void*clave)
{
    return *(int*)nro - ((t_clave*)clave)->clave;
}
