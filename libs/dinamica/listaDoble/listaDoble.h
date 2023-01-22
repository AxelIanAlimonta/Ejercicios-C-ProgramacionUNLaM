#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    unsigned tam;
    void*dato;
    struct sNodo*sig;
    struct sNodo*ant;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*lista);
int insertarOrdenado(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado);
void recorrer(t_lista*lista,void(*mostrar)(const void*));
void recorrerInverso(t_lista*lista,void(*mostrar)(const void*));


#endif // LISTADOBLE_H_INCLUDED
