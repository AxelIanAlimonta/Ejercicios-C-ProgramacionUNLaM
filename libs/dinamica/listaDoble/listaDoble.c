#include "listaDoble.h"

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int insertarOrdenado(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado)
{
    t_nodo*nue,*actual,*auxSig,*auxAnt;
    int cmp;
    if(*lista)
    {
        actual=*lista;
        while((cmp=f_cmp(actual->dato,dato))>0&&(actual->ant))
            actual=actual->ant;

        while((cmp=f_cmp(actual->dato,dato))<0&&(actual->sig))
            actual=actual->sig;

        if(cmp<0)
        {
            auxSig=actual->sig;
            auxAnt=actual;
        }
        else
        {
            if(!duplicado&&!cmp)
                return 0;
            auxAnt=actual->ant;
            auxSig=actual;
        }
    }
    else
    {
        auxAnt=NULL;
        auxSig=NULL;
    }

    nue=malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato=malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,tam);
    nue->tam=tam;
    nue->sig=auxSig;
    nue->ant=auxAnt;
    *lista=nue;

    if(auxAnt)
        auxAnt->sig=nue;
    if(auxSig)
        auxSig->ant=nue;

    return 1;
}

void recorrer(t_lista*lista,void(*mostrar)(const void*))
{
    t_nodo*recorrer=*lista;
    if(!*lista)
        return;
    while(recorrer->ant)
        recorrer=recorrer->ant;

    while(recorrer)
    {
        mostrar(recorrer->dato);
        recorrer=recorrer->sig;
    }

}

void recorrerInverso(t_lista*lista,void(*mostrar)(const void*))
{
    t_nodo*recorrer=*lista;
    if(!*lista)
        return;
    while(recorrer->sig)
        recorrer=recorrer->sig;

    while(recorrer)
    {
        mostrar(recorrer->dato);
        recorrer=recorrer->ant;
    }

}
