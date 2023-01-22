#include "Lista.h"

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int insertarOrdenadoEnLista(t_lista*lista,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*),int duplicado)
{
    int cmp;
    t_nodo*nodo;
    while(*lista)
    {
        cmp=f_cmp(dato,(*lista)->dato);
        if(!cmp&&!duplicado)
            return 0;
        if(cmp>0)
            lista=&(*lista)->sig;
        else
        {
            if(!(nodo=malloc(sizeof(t_nodo))))
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
    }
    if(!*lista)
    {
        if(!(nodo=malloc(sizeof(t_nodo))))
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
    }
    return 1;
}

int buscar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int eliminar)
{
    int cmp;
    t_nodo*elim;
    while(*lista)
    {
        cmp=f_cmp(clave,(*lista)->dato);
        if(cmp<0)
            return 0;
        if(cmp>0)
            lista=&(*lista)->sig;
        else
        {
            recuperar(clave,(*lista)->dato);
            if(eliminar)
            {
                elim=*lista;
                *lista=elim->sig;
                free(elim->dato);
                free(elim);
                return 1;
            }
        }
    }
    return 0;
}

int r_buscar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int eliminar)
{
    int cmp;
    t_nodo*elim;
    if(!*lista)
        return 0;
    cmp=f_cmp(clave,(*lista)->dato);
    if(cmp<0)
        return 0;
    if(cmp>0)
        return r_buscar_cla(&(*lista)->sig,clave,f_cmp,recuperar,eliminar);
    else
    {
        recuperar(clave,(*lista)->dato);
        if(eliminar)
        {
            elim=*lista;
            *lista=elim->sig;
            free(elim->dato);
            free(elim);
        }
        return 1;
    }
}

void recorrerLista(t_lista*lista,void(*accion)(void*))
{
    while(*lista)
    {
        accion((*lista)->dato);
        lista=&(*lista)->sig;
    }
}

int contar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),int eliminar)
{
    int cont=0;
    t_nodo*elim;
    while(*lista&&f_cmp(clave,(*lista)->dato))
        lista=&(*lista)->sig;

    while((*lista)&&!f_cmp(clave,(*lista)->dato))
    {
        cont++;
        if(eliminar)
        {
            elim=*lista;
            *lista=elim->sig;
            free(elim->dato);
            free(elim);
        }
        else
            lista=&(*lista)->sig;
    }
    return cont;
}

int r_contar_cla(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),int eliminar)
{
    t_nodo*elim;
    int cmp;
    if(!*lista)
        return 0;
    cmp=f_cmp(clave,(*lista)->dato);
    if(cmp>0)
        return r_contar_cla(&(*lista)->sig,clave,f_cmp,eliminar);
    if(cmp<0)
        return 0;
    if(eliminar)
    {
        elim=*lista;
        *lista=elim->sig;
        free(elim->dato);
        free(elim);
        return r_contar_cla(lista,clave,f_cmp,eliminar)+1;
    }
    return r_contar_cla(&(*lista)->sig,clave,f_cmp,eliminar)+1;
}

int buscar_cla_n(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int ocurrencia)
{
    while(*lista&&f_cmp((*lista)->dato,clave))
        lista=&(*lista)->sig;
    while(*lista&&!f_cmp((*lista)->dato,clave))
    {
        ocurrencia--;
        if(!ocurrencia)
        {
            recuperar(clave,(*lista)->dato);
            return 1;
        }
        lista=&(*lista)->sig;
    }
    return 0;
}

int r_buscar_cla_n(t_lista*lista,void*clave,int(*f_cmp)(const void*,const void*),void(*recuperar)(void*clave,const void*dato),int ocurrencia)
{
    int cmp;
    if(!*lista)
        return 0;

    cmp=f_cmp(clave,(*lista)->dato);
    if(cmp>0)
        return r_buscar_cla_n(&(*lista)->sig,clave,f_cmp,recuperar,ocurrencia);
    if(cmp<0)
        return 0;
    if(--ocurrencia)
        return r_buscar_cla_n(&(*lista)->sig,clave,f_cmp,recuperar,ocurrencia-1);

    recuperar(clave,(*lista)->dato);
    return 1;
}
