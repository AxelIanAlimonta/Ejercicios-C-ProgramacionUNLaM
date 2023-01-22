#include <string.h>
#include <stdlib.h>
#include "Cola.h"

void crearCola(t_cola*cola)
{
    cola->pri=NULL;
    cola->ult=NULL;
}

int colaVacia(const t_cola*cola)
{
    return !cola->pri;
}

int colaLlena(const t_cola*cola,unsigned tam)
{
    return 0;
}

void vaciarCola(t_cola*cola)
{
    t_nodo*elim;
    while(cola->pri)
    {
        elim=cola->pri;
        cola->pri=elim->sig;
        free(elim->dato);
        free(elim);
    }
    cola->ult=NULL;
}

int ponerEnCola(t_cola*cola,const void*dato,unsigned tam)
{
    t_nodo*nodo;
    if(!(nodo=malloc(sizeof(t_nodo))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato,dato,tam);
    nodo->tam=tam;
    nodo->sig=NULL;
    if(!cola->pri)
        cola->pri=nodo;
    else
        cola->ult->sig=nodo;
    cola->ult=nodo;
    return 1;
}

int sacarDeCola(t_cola*cola,void*dato,unsigned tam)
{
    t_nodo*elim;
    if(!cola->pri)
        return 0;
    elim=cola->pri;
    memcpy(dato,elim->dato,MIN(tam,elim->tam));
    if(elim==cola->ult)
        cola->ult=NULL;
    cola->pri=elim->sig;
    free(elim->dato);
    free(elim);

    return 1;

}

int verPrimerElemento(const t_cola*cola,void*dato,unsigned tam)
{
    if(!cola->pri)
        return 0;
    memcpy(dato,cola->pri->dato,MIN(tam,cola->pri->tam));
    return 1;
}
