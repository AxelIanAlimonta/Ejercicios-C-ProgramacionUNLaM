#include "listaDoble.h"

void crearLista(t_listaDoble*lista)
{
    *lista=NULL;
}

int insertarEnListaDoble(t_listaDoble*lista,const void*dato,unsigned tam)
{
    t_nodoLista*actual,*auxAnt,*auxSig,*nodo;
    if(!*lista)
    {
        auxAnt=NULL;
        auxSig=NULL;
    }
    else
    {
        actual=*lista;
        auxAnt=actual;
        auxSig=actual->sig;
    }


    if(!(nodo=malloc(sizeof(t_nodoLista))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato,dato,tam);
    nodo->tam=tam;
    nodo->sig=auxSig;
    nodo->ant=auxAnt;
    if(auxAnt)
        auxAnt->sig=nodo;
    if(auxSig)
        auxSig->ant=nodo;
    *lista=nodo;
    return 1;
}

void recorrerListaDoble(t_listaDoble*lista,void(*accion)(void*))
{
    if(!*lista)
        return;
    while((*lista)->ant)
        lista=&(*lista)->ant;
    while(*lista)
    {
        accion((*lista)->dato);
        lista=&(*lista)->sig;
    }
}

void vaciarLista(t_listaDoble*lista)
{
    t_nodoLista*elim,*auxAnt,*auxSig;
    if(!*lista)
        return;
    while((*lista)->sig)
    {
        elim=(*lista)->sig;
        auxAnt=elim->ant;
        auxSig=elim->sig;
        auxAnt->sig=auxSig;
        if(auxSig)
            auxSig->ant=auxAnt;
        free(elim->dato);
        free(elim);
    }

    while((*lista)->ant)
    {
        elim=(*lista)->ant;
        auxAnt=elim->ant;
        auxSig=elim->sig;
        if(auxAnt)
            auxAnt->sig=auxSig;
        auxSig->ant=auxAnt;
        free(elim->dato);
        free(elim);
    }
    free((*lista)->dato);
    free(*lista);
    *lista=NULL;
}

int insertarOrdenadoEnLista(t_listaDoble*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado)
{
    t_nodoLista*nodo,*auxAnt,*auxSig,*actual;
    int cmp;
    if(*lista)
    {
        actual=(*lista);
        cmp=f_cmp(dato,actual->dato);
        while(cmp<0&&actual->ant)
        {
            actual=actual->ant;
            cmp=f_cmp(dato,actual->dato);
        }

        while(cmp>0&&actual->sig)
        {
            actual=actual->sig;
            cmp=f_cmp(dato,actual->dato);
        }

        if(!cmp&&!duplicado)
            return 0;

        if(cmp>0)
        {
            auxAnt=actual;
            auxSig=actual->sig;
        }
        else
        {
            auxAnt=actual->ant;
            auxSig=actual;
        }
    }
    else
    {
        auxAnt=NULL;
        auxSig=NULL;
    }

    if(!(nodo=malloc(sizeof(t_nodoLista))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato,dato,tam);
    nodo->tam=tam;
    nodo->sig=auxSig;
    nodo->ant=auxAnt;
    if(auxAnt)
        auxAnt->sig=nodo;
    if(auxSig)
        auxSig->ant=nodo;
    *lista=nodo;
    return 1;
}

int buscarPorClaveEnListaOrdenada(t_listaDoble*lista,void*clave,unsigned tam,int(*f_cmp)(const void*,const void*))
{
    t_nodoLista*actual;
    int cmp;
    if(!*lista)
        return 0;

    actual=*lista;

    cmp=f_cmp(clave,actual->dato);
    while(cmp<0&&actual->ant)
    {
        actual=actual->ant;
        cmp=f_cmp(clave,actual->dato);
    }

    while(cmp>0&&actual->sig)
    {
        actual=actual->sig;
        cmp=f_cmp(clave,actual->dato);
    }

    if(cmp)
        return 0;

    memcpy(clave,actual->dato,MIN(tam,actual->tam));
    return 1;
}
