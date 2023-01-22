#include "Pila.h"

void crearPila(t_pila*pila)
{
    *pila=NULL;
}

int apilar(t_pila*pila,const void*dato,unsigned tam)
{
    t_nodo* nodo;
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
    nodo->tam=tam;
    nodo->sig=*pila;
    *pila=nodo;
    return 1;
}

int verTopeDePila(t_pila*pila,void*dato,unsigned tam)
{
    if(!*pila)
        return 0;
    memcpy(dato,(*pila)->dato,MIN((*pila)->tam,tam));
    return 1;
}

int desapilar(t_pila*pila,void*dato,unsigned tam)
{
    t_nodo *elim;
    if(!*pila)
        return 0;
    memcpy(dato,(*pila)->dato,MIN(tam,(*pila)->tam));

    elim=*pila;
    *pila=elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
