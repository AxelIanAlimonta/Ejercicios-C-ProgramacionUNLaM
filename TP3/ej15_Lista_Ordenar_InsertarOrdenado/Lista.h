#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))


typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*lista);
int insertarEnOrden(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*datoIngresado,const void*datoLista),int duplicado);
int insertarPrimeroEnLista(t_lista*lista,const void*dato,unsigned tam);
int sacarPrimerElemento(t_lista*lista,void*dato,unsigned tam);
void recorrerLista(t_lista*lista,void(*accion)(void*dato));
void ordenarLista(t_lista*lista,int(*f_cmp)(const void*,const void*));
int listaVacia(t_lista*lista);

#endif // LISTA_H_INCLUDED
