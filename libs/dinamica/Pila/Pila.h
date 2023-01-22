#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo
{
    void*dato;
    unsigned tam;
    struct sNodo* sig;
}t_nodo;

typedef t_nodo*t_pila;

void crearPila(t_pila*pila);
int apilar(t_pila*pila,const void*dato,unsigned tam);
int desapilar(t_pila*pila,void*dato,unsigned tam);
int pilaVacia(t_pila*pila);
int pilaLlena(const t_pila*pila,unsigned tam);
void vaciarPila(t_pila*pila);
int verTopePila(const t_pila*pila,void*dato,unsigned tam);



#endif // PILA_H_INCLUDED
