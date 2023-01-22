#include "cola.h"

void crearCola(t_cola*cola)
{
    (*cola)=NULL;
}

int colaVacia(const t_cola*cola)
{
    return !(*cola);
}

int colaLlena(const t_cola*cola,unsigned tam)
{
    return 0;
}

int verPrimerElemento(const t_cola*cola,void*dato,unsigned tam)
{
    if(!(*cola))
        return 0;
    memcpy(dato,(*cola)->sig->dato,MIN((*cola)->sig->tam,tam));
    return 1;
}


int ponerEnCola(t_cola*cola,const void*dato,unsigned tam)
{
    t_nodo*nue;

    if(!(nue=malloc(sizeof(t_nodo))))
        return 0;
    if(!(nue->dato=malloc(tam)))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,dato,tam);
    nue->tam=tam;

    if(*cola)
    {
        nue->sig=(*cola)->sig;
        (*cola)->sig=nue;
        (*cola)=nue;
    }
    else
    {
        (*cola)=nue;
        nue->sig=nue;
    }
    return 1;

}

void vaciarCola(t_cola*cola)
{
    t_nodo*elim;

    while(*cola)
    {
        elim=(*cola)->sig;
        if(elim==(*cola))
            *cola=NULL;
        else
            (*cola)->sig=elim->sig;
        free(elim->dato);
        free(elim);
    }
}


int sacarDeCola(t_cola*cola,void*dato,unsigned tam)
{
    t_nodo*elim;

    if(!*cola)
        return 0;

    elim=(*cola)->sig;

    memcpy(dato,elim->dato,MIN(elim->tam,tam));

    if(elim==*cola)
        *cola=NULL;
    else
        (*cola)->sig=elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}
