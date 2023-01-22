#include "Lista.h"

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int insertarEnOrden(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*datoIngresado,const void*datoLista),int duplicado)
{
    int cmp;
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

    while(*lista&&((cmp=f_cmp(dato,(*lista)->dato))>0))
        lista=&(*lista)->sig;
    if(*lista&&!cmp&&!duplicado)
        return 0;
    nodo->sig=*lista;
    *lista=nodo;
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

int listaVacia(t_lista*lista)
{
    return !*lista;
}

int sacarPrimerElemento(t_lista*lista,void*dato,unsigned tam)
{
    t_nodo*elim;
    if(!*lista)
        return 0;
    elim=*lista;
    memcpy(dato,elim->dato,MIN(tam,elim->tam));
    *lista=elim->sig;
    free(elim->dato);
    free(elim);
    return 0;

}

int insertarPrimeroEnLista(t_lista*lista,const void*dato,unsigned tam)
{
    t_nodo*nodo;

    if(!(nodo=malloc(sizeof(nodo))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
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

void ordenarLista(t_lista*lista,int(*f_cmp)(const void*,const void*))
{
    t_nodo**recorrer,**minimo,*auxMinimo;

    while(*lista)
    {
        minimo=lista;
        recorrer=&(*lista)->sig;
        while(*recorrer)
        {
            if(f_cmp((*minimo)->dato,(*recorrer)->dato)>0)
            {
                minimo=recorrer;
            }
            recorrer=&(*recorrer)->sig;
        }
        auxMinimo=*minimo;
        *minimo=auxMinimo->sig;
        auxMinimo->sig=*lista;
        *lista=auxMinimo;
        lista=&(*lista)->sig;
    }

}
