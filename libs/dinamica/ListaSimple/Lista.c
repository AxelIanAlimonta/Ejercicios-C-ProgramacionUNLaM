#include "Lista.h"
#include <string.h>

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int listaVacia(const t_lista*lista)
{
    return !(*lista);
}

int listaLlena(const t_lista*lista)
{
    return 0;
}

int insertarAlFinal(t_lista*lista,void*dato,unsigned tam)
{
    t_nodo*nodo;

    while(*lista)
        lista=&(*lista)->sig;

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

    nodo->sig=NULL;
    *lista=nodo;
    return 1;

}

void recorrer(t_lista*lista,void(*accion)(void*dato))
{

    while(*lista)
    {
        accion((*lista)->dato);
        lista=&(*lista)->sig;
    }

}

int insertarEnOrden(t_lista*lista,void*dato,unsigned tam,int (*comparar)(const void*dato1,const void*dato2),unsigned duplicado)
{
    t_nodo*nodo;
    int cmp=1;

    while(*lista&&((cmp=comparar(dato,(*lista)->dato))>0))
    {
        lista=&(*lista)->sig;
    }
    if(!cmp&&!duplicado)
        return 0;

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

    nodo->sig=(*lista);
    *lista=nodo;
    return 1;
}

int insertarEnOrdenYAgrupar(t_lista*lista,void*dato,unsigned tam,int (*comparar)(const void*dato1,const void*dato2),void (*accion)(void*datoIngresado,void*datoEnLista))
{
    t_nodo*nodo;
    int cmp=1;

    while(*lista&&((cmp=comparar(dato,(*lista)->dato))>0))
    {
        lista=&(*lista)->sig;
    }
    if(!cmp)
    {
        accion(dato,(*lista)->dato);
        return 1;
    }
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

    nodo->sig=(*lista);
    *lista=nodo;
    return 1;
}



int eliminarPrimerelemento(t_lista*lista)
{
    t_nodo*elim;
    if(!*lista)
        return 0;
    elim=*lista;
    *lista=elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}

int eliminarUltimoElemento(t_lista*lista)
{
    t_nodo*elim;
    if(!*lista)
        return 0;
    while((*lista)->sig)
        lista=&(*lista)->sig;
    elim=*lista;
    *lista=NULL;
    free(elim->dato);
    free(elim);
    return 1;
}

int eliminarElementoEnPos(t_lista*lista,unsigned pos)
{
    t_nodo*elim;
    while(*lista&&pos>1)
    {
        lista=&(*lista)->sig;
        pos--;
    }

    if(!*lista||pos>1)
        return 0;

    elim=*lista;
    *lista=elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}

int eliminarPorClaveYRetornarAcumulado(t_lista*lista,void*acum,void*clave,int(*f_cmp)(const void*dato,const void*clave),void(*accion)(void*acum,void*dato))
{
    t_nodo * elim;
    int contador=0;
    while(*lista)
    {
        if(!f_cmp((*lista)->dato,clave))
        {
            accion(acum,(*lista)->dato);
            contador++;
            elim=(*lista);
            (*lista)=elim->sig;
            free(elim->dato);
            free(elim);
        }
        else
            lista=&(*lista)->sig;

    }
    return contador;
}

void ordenarLista(t_lista*lista,int(*f_cmp)(const void*recor,const void*min))
{
    t_nodo*auxMinim;
    t_nodo**minimo;
    t_nodo**recorrer;

    while((*lista)->sig)
    {
        recorrer=&(*lista)->sig;
        minimo=lista;

        while(*recorrer)
        {
            if(f_cmp((*recorrer)->dato,(*minimo)->dato)<0)
                minimo=recorrer;
            recorrer=&(*recorrer)->sig;
        }
        if(*minimo!=*lista)
        {
            auxMinim=*minimo;
            *minimo=auxMinim->sig;
            auxMinim->sig=*lista;
            *lista=auxMinim;
        }
        lista=&(*lista)->sig;
    }
}
