#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila*pila);
int apilar(t_pila*pila,const void*dato,unsigned tam);
int desapilar(t_pila*pila,void*dato,unsigned tam);
int verTopeDePila(t_pila*pila,void*dato,unsigned tam);
int pilaVacia(t_pila*pila);

#endif // PILA_H_INCLUDED
