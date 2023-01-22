#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#define MIN(x,y) ((x)<(y)?(x):(y))
#include <string.h>
#include <stdlib.h>

typedef struct sNodo
{
    unsigned tam;
    void*dato;
    struct sNodo*sig;
}t_nodo;

typedef t_nodo* t_cola;

void crearCola(t_cola*cola);
int colaVacia(const t_cola*cola);
int colaLlena(const t_cola*cola,unsigned tam);
void vaciarCola(t_cola*cola);
int ponerEnCola(t_cola*cola,const void*dato,unsigned tam);
int sacarDeCola(t_cola*cola,void*dato,unsigned tam);
int verPrimerElemento(const t_cola*cola,void*dato,unsigned tam);

#endif // COLA_H_INCLUDED
