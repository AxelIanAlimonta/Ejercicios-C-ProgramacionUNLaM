#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) (x)<(y)?(x):(y)


typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*lista);
int insertarOrdenadoEnLista(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado);
int buscar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int eliminar);
int r_buscar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int eliminar);
int contar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),int eliminar);
int r_contar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),int eliminar);
int buscar_cla_n(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int ocurrencia);
int r_buscar_cla_n(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int ocurrencia);
void recorrerLista(t_lista*lista,void(*accion)(void*));

#endif // LISTA_H_INCLUDED
