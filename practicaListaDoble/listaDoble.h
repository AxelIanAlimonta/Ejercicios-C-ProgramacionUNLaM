#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodoLista
{
    void*dato;
    unsigned tam;
    struct sNodoLista*sig;
    struct sNodoLista*ant;
}t_nodoLista;

typedef t_nodoLista* t_listaDoble;

void crearLista(t_listaDoble*lista);
int insertarEnListaDoble(t_listaDoble*lista,const void*dato,unsigned tam);
int insertarOrdenadoEnLista(t_listaDoble*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado);
void recorrerListaDoble(t_listaDoble*lista,void(*accion)(void*));
void vaciarLista(t_listaDoble*lista);
int buscarPorClaveEnListaOrdenada(t_listaDoble*lista,void*clave,unsigned tam,int(*f_cmp)(const void*,const void*));

#endif // LISTADOBLE_H_INCLUDED
