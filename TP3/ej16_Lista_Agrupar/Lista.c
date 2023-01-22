#include "Lista.h"

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int insertarAlFinalDeListaYAgrupar(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),void(*f_agrupar)(void*info,const void*dato))
{
    t_nodo* nodo;
    while(*lista)
    {
        if(!f_cmp(dato,(*lista)->dato))
        {
            f_agrupar((*lista)->dato,dato);
            return 1;
        }
        else
        {
            lista=&(*lista)->sig;
        }
    }
    nodo=malloc(sizeof(t_nodo));
    if(!nodo)
        return 0;
    nodo->dato=malloc(tam);
    if(!(nodo->dato))
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato,dato,tam);
    nodo->tam=tam;
    nodo->sig=*lista;
    *lista=nodo;
    return 1;
}

int eliminarDuplicadosDeListaYGrabarEnArch(t_lista*lista,int(*f_cmp)(const void*,const void*),FILE*pf,void(*accion)(void*dato,FILE*pf))
{
    t_nodo**recorrer,*elim;
    while(*lista)
    {
        recorrer=&(*lista)->sig;
        while(*recorrer)
        {
            if(!f_cmp((*lista)->dato,(*recorrer)->dato))
            {
                elim=*recorrer;
                accion(elim->dato,pf);
                *recorrer=elim->sig;
                free(elim->dato);
                free(elim);
            }
            else
                recorrer=&(*recorrer)->sig;
        }
        lista=&(*lista)->sig;
    }
    return 1;
}

void recorrerLista(t_lista*lista,void(*accion)(void*dato))
{
    while(*lista)
    {
        accion((*lista)->dato);
        lista=&(*lista)->sig;
    }
}

void ordenarLista(t_lista*lista,int(*f_cmp)(const void*,const void*))
{
    t_nodo**minimo,**recorrer,*auxMin;
    while(*lista)
    {
        minimo=lista;
        recorrer=&(*lista)->sig;
        while(*recorrer)
        {
            if((f_cmp((*recorrer)->dato,(*minimo)->dato))<0)
                minimo=recorrer;
            recorrer=&(*recorrer)->sig;
        }
        if(*minimo!=*lista)
        {
            auxMin=*minimo;
            *minimo=auxMin->sig;
            auxMin->sig=*lista;
            *lista=auxMin;
        }
        lista=&(*lista)->sig;
    }
}
