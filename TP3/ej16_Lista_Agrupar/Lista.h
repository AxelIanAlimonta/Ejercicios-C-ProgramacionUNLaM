#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lista.h"
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*lista);
int insertarAlFinalDeListaYAgrupar(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),void(f_agrupar)(void*info,const void*dato));
int eliminarDuplicadosDeListaYGrabarEnArch(t_lista*lista,int(*f_cmp)(const void*,const void*),FILE*pf,void(*accion)(void*dato,FILE*pf));
void recorrerLista(t_lista*lista,void(*accion)(void*dato));
void ordenarLista(t_lista*lista,int(f_cmp)(const void*,const void*));

#endif // LISTA_H_INCLUDED
