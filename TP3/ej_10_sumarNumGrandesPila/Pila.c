#include "Pila.h"
void crearPila(t_pila*pila)
{
    *pila=NULL;
}

int apilar(t_pila*pila,const void*dato,unsigned tam)
{
    t_nodo*nodo;

    if(!(nodo=malloc(sizeof(t_nodo))))
        return 0;
    if(!(nodo->dato= malloc(tam)))
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

int pilaVacia(t_pila*pila)
{
    return !*pila;
}

int desapilar(t_pila*pila,void*dato,unsigned tam)
{
    if(!*pila)
        return 0;
    t_nodo*elim;
    memcpy(dato,(*pila)->dato,MIN((*pila)->tam,tam));
    elim=*pila;
    *pila=elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
