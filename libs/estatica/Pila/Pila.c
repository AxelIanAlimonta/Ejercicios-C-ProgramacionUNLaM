#include "Pila.h"

void crearPila(t_pila*pila)
{
    pila->tope=TAM_PILA;
}

int apilar(t_pila*pila,const void*dato,unsigned tam)
{
    if((tam+sizeof(unsigned)>pila->tope))
        return 0;
    pila->tope-=tam;
    memcpy(pila->pila+pila->tope,dato,tam);

    pila->tope-=sizeof(unsigned);
    memcpy(pila->pila+pila->tope,&tam,sizeof(unsigned));
    return 1;

}

int desapilar(t_pila*pila,void*dato,unsigned tam)
{
    unsigned tamDePila;
    if(pila->tope==TAM_PILA)
        return 0;

    memcpy(&tamDePila,pila->pila+pila->tope,sizeof(unsigned));
    pila->tope+=sizeof(unsigned);

    memcpy(pila->pila+pila->tope,dato,MIN(tam,tamDePila));
    pila->tope+=tam;
    return 1;
}

int pilaVacia(t_pila*pila)
{
    return pila->tope==TAM_PILA;
}

int pilaLlena(const t_pila*pila,unsigned tam)
{
    return (tam+sizeof(unsigned))>pila->tope;
}

void vaciarPila(t_pila*pila)
{
    pila->tope=TAM_PILA;
}

int verTopePila(const t_pila*pila,void*dato,unsigned tam)
{
    unsigned tamDePila;
    if(pila->tope==TAM_PILA)
        return 0;

    memcpy(&tamDePila,pila->pila+pila->tope,sizeof(unsigned));
    memcpy(dato,pila->pila+pila->tope+sizeof(unsigned),MIN(tam,tamDePila));
    return 1;
}
