#include "listaCircular.h"
#include <string.h>
#include <stdlib.h>

void crearLista(t_listaC*lista)
{
    *lista=NULL;
}

int insertarEnListaCircular(t_listaC*lista,const void*dato,unsigned tam)
{
    t_nodo*nodo;
    nodo=malloc(sizeof(t_nodo));
    if(!nodo)
        return 0;
    nodo->dato=malloc(tam);
    if(!nodo->dato)
    {
        free(nodo);
        return 0;
    }

    memcpy(nodo->dato,dato,tam);
    nodo->tam=tam;

    if(!*lista)
    {
        (*lista)=nodo;
        nodo->sig=nodo;
    }
    else
    {
        nodo->sig=(*lista)->sig;
        (*lista)->sig=nodo;
    }
    return 1;
}

void recorrerListaCircular(t_listaC*lista,void(*accion)(const void*dato))
{
    t_nodo*recorrer;
    if(!*lista)
        return;

    recorrer = (*lista);

    do
    {
        accion(recorrer->dato);
        recorrer=recorrer->sig;
    }
    while(recorrer!=(*lista));
}

int eliminarPorClaveDeListaCircular(t_listaC*lista,void*clave,int(*f_cmp)(const void*dato,const void*clave),void recuperarInfo(const void*info,void*clave),int duplicado)
{
    t_nodo**recorrer,**iniRecorrer;
    t_nodo*elim;

    if(!*lista)
        return 0;
    recorrer=&(*lista)->sig;
    iniRecorrer=recorrer;


    do
    {
        if(!f_cmp((*recorrer)->dato,clave))
        {
            recuperarInfo((*recorrer)->dato,clave);
            elim=*recorrer;

            if(elim->sig==elim)
            {
                *lista=NULL;
                free(elim->dato);
                free(elim);
                return 1;
            }

            if(*recorrer==*lista)
            {
                *lista=*iniRecorrer;
                *recorrer=*iniRecorrer;
                free(elim->dato);
                free(elim);
                return 1;
            }

            *recorrer=elim->sig;
            free(elim->dato);
            free(elim);
            if(!duplicado)
                return 1;
        }
        else
            recorrer=&(*recorrer)->sig;
    }
    while(*recorrer!=*iniRecorrer);
    return 1;
}
