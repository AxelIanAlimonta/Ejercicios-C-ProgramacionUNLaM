#include "pila.h"

void crearPila(t_pila*pila)
{
    (*pila)=NULL;
}

int apilar(t_pila*pila,const void*dato,unsigned tam)
{
    t_nodo*nue;

    nue=malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato=malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,dato,tam);
    nue->tam=tam;

    if(!(*pila))
    {
        *pila=nue;
        nue->sig=nue;
    }
    else
    {
        nue->sig=(*pila)->sig;
        (*pila)->sig=nue;
    }
    return 1;
}

int desapilar(t_pila*pila,void*dato,unsigned tam)
{
    t_nodo*elim;

    if(!(*pila))
        return 0;

    elim=(*pila)->sig;

    if(elim==*pila)
        (*pila)=NULL;
    else
    {
        (*pila)->sig=elim->sig;
    }
    memcpy(dato,elim->dato,MIN(tam,elim->tam));
    free(elim->dato);
    free(elim);
    return 1;
}


int pilaVacia(t_pila*pila)
{
    return !(*pila);
}


int pilaLlena(const t_pila*pila,unsigned tam)
{
    return 0;
}

void vaciarPila(t_pila*pila)
{
    t_nodo*elim;

    while(*pila)
    {
        elim=(*pila)->sig;
        if((*pila)==elim)
            *pila=NULL;
        else
        {
            (*pila)->sig=elim->sig;
        }
        free(elim->dato);
        free(elim);
    }
}

int verTopePila(const t_pila*pila,void*dato,unsigned tam)
{
    if(!(*pila))
        return 0;
    memcpy(dato,(*pila)->sig->dato,MIN(tam,(*pila)->sig->tam));
    return 1;
}
