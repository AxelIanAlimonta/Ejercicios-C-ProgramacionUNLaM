#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo
{
    void*dato;
    unsigned tam;
    struct sNodo*sig;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila*pila);
int apilar(t_pila*pila,const void*dato,unsigned tam);
int desapilar(t_pila*pila,void*dato,unsigned tam);
int verTopeDePila(t_pila*pila,void*dato,unsigned tam);

#endif // PILA_H_INCLUDED
