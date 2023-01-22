#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*lista);
int listaVacia(const t_lista*lista);
int listaLlena(const t_lista*lista);
int insertarAlFinal(t_lista*lista,void*dato,unsigned tam);
void recorrer(t_lista*lista,void(*accion)(void*dato));
int insertarEnOrden(t_lista*,void*dato,unsigned tam,int (*comparar)(const void*dato1,const void*dato2),unsigned duplicado);
int insertarEnOrdenYAgrupar(t_lista*lista,void*dato,unsigned tam,int (*comparar)(const void*dato1,const void*dato2),void (*accion)(void*datoIngresado,void*datoEnLista));

int eliminarPorClaveYRetornarAcumulado(t_lista*lista,void*acum,void*clave,int(*f_cmp)(const void*dato,const void*clave),void(*accion)(void*acum,void*dato));
void ordenarLista(t_lista*lista,int(f_cmp)(const void*,const void*));

int eliminarPrimerelemento(t_lista*lista);
int eliminarUltimoElemento(t_lista*lista);
int eliminarElementoEnPos(t_lista*lista,unsigned pos);


#endif // LISTA_H_INCLUDED
