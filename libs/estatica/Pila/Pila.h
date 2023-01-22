#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
#define TAM_PILA 500

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}t_pila;

void crearPila(t_pila*pila);
int apilar(t_pila*pila,const void*dato,unsigned tam);
int desapilar(t_pila*pila,void*dato,unsigned tam);
int pilaVacia(t_pila*pila);
int pilaLlena(const t_pila*pila,unsigned tam);
void vaciarPila(t_pila*pila);
int verTopePila(const t_pila*pila,void*dato,unsigned tam);


#endif // PILA_H_INCLUDED
