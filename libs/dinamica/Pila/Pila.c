#include "Pila.h"

void crearPila(t_pila*pila)
{
    *pila=NULL;
}

int apilar(t_pila*pila,const void*dato,unsigned tam)
{
    t_nodo*nodo;

    nodo=malloc(sizeof(t_nodo));
    if(!nodo)
        return 0;
    nodo->dato=malloc(tam);
    if(!nodo->dato)
    {
        free(nodo);
        return 0;
    }

    memcpy(nodo->dato,dato,tam);
    nodo->sig=*pila;
    nodo->tam=tam;
    (*pila)=nodo;

    return 1;
}

int desapilar(t_pila*pila,void*dato,unsigned tam)
{
    t_nodo*elim=*pila;

    if(!*pila)
        return 0;

    memcpy(dato,elim->dato,MIN(tam,elim->tam));

    (*pila)=elim->sig;
    free(elim->dato);
    free(elim);

    return 1;
}

int pilaVacia(t_pila*pila)
{
    return !*pila;
}

int pilaLlena(const t_pila*pila,unsigned tam)
{
    return 0;
}

void vaciarPila(t_pila*pila)
{
    t_nodo *elim;
    while(*pila)
    {
        elim=*pila;
        *pila=elim->sig;
        free(elim->dato);
        free(elim);
    }
}

int verTopePila(const t_pila*pila,void*dato,unsigned tam)
{
    if(!*pila)
        return 0;
    memcpy(dato,(*pila)->dato,MIN(tam,(*pila)->tam));
    return 1;
}
