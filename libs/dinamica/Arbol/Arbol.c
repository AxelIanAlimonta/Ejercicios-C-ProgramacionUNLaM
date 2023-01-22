#include "Arbol.h"

void crearArbol(t_arbol*arbol)
{
    *arbol=NULL;
}

int insertarEnArbol(t_arbol*arbol,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*))
{
    t_nodo* nodo;
    int cmp;
    while(*arbol)
    {
        cmp=f_cmp(dato,(*arbol)->dato);
        if(!cmp)
            return 0;
        if(cmp<0)
            arbol=&(*arbol)->izq;
        if(cmp>0)
            arbol=&(*arbol)->der;
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
    nodo->izq=NULL;
    nodo->der=NULL;
    *arbol=nodo;
    return 1;
}

int r_insertarEnArbol(t_arbol*arbol,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*))
{
    t_nodo* nodo;
    int cmp;
    if(*arbol)
    {
        cmp=f_cmp(dato,(*arbol)->dato);
        if(!cmp)
            return 0;
        if(cmp<0)
            return r_insertarEnArbol(&(*arbol)->izq,dato,tam,f_cmp);
        if(cmp>0)
            return r_insertarEnArbol(&(*arbol)->der,dato,tam,f_cmp);

    }

    if(!(nodo=malloc(sizeof(t_nodo))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato,dato,tam);
    nodo->der=NULL;
    nodo->izq=NULL;
    nodo->tam=tam;
    *arbol=nodo;
    return 1;
}

void recorrerInOrden(t_arbol*arbol,void(*accion)(const void*))
{
    if(!*arbol)
        return;

    recorrerInOrden(&(*arbol)->izq,accion);
    accion((*arbol)->dato);
    recorrerInOrden(&(*arbol)->der,accion);
}

void recorrerPreOrden(t_arbol*arbol,void(*accion)(const void*))
{
    if(!*arbol)
        return;

    accion((*arbol)->dato);
    recorrerPreOrden(&(*arbol)->izq,accion);
    recorrerPreOrden(&(*arbol)->der,accion);
}

void recorrerPosOrden(t_arbol*arbol,void(*accion)(const void*))
{
    if(!*arbol)
        return;

    recorrerPosOrden(&(*arbol)->izq,accion);
    recorrerPosOrden(&(*arbol)->der,accion);
    accion((*arbol)->dato);
}

int alturaDeArbol(t_arbol*arbol)
{
    int Hizq,Hder;
    if(!*arbol)
        return 0;

    Hizq=alturaDeArbol(&(*arbol)->izq);
    Hder=alturaDeArbol(&(*arbol)->der);

    return Hizq>Hder?Hizq+1:Hder+1;
}

void mostrarArbol(t_arbol*arbol,void(*mostrar)(const void*dato,int despl))
{
    mostrarArbolAux(arbol,mostrar,0);

}

void mostrarArbolAux(t_arbol*arbol,void(*mostrar)(const void*dato,int despl),int desplazamiento)
{
    if(!*arbol)
        return;
    mostrarArbolAux(&(*arbol)->der,mostrar,desplazamiento+1);
    mostrar((*arbol)->dato,desplazamiento);
    mostrarArbolAux(&(*arbol)->izq,mostrar,desplazamiento+1);
}

int contarNodosDeArbol(t_arbol*arbol)
{
    int cantIzq,cantDer;
    if(!*arbol)
        return 0;
    cantIzq=contarNodosDeArbol(&(*arbol)->izq);
    cantDer=contarNodosDeArbol(&(*arbol)->der);

    return cantDer+cantIzq+1;
}

int contarHojasDeArbol(t_arbol*arbol)
{
    int cantIzq=0,cantDer=0;
    if(!*arbol)
        return 0;
    if(!(*arbol)->izq&&!(*arbol)->der)
        return 1;
    cantDer=contarHojasDeArbol(&(*arbol)->der);
    cantIzq=contarHojasDeArbol(&(*arbol)->izq);

    return cantDer+cantIzq;
}

int contarRamasDeArbol(t_arbol*arbol)
{
    int cantIzq,cantDer;
    if(!*arbol)
        return 0;
    cantIzq=contarRamasDeArbol(&(*arbol)->izq);
    cantDer=contarRamasDeArbol(&(*arbol)->der);
    if((*arbol)->izq||(*arbol)->der)
        return cantDer+cantIzq+1;
    else
        return 0;
}

int esAVL(const t_arbol*arbol)
{
    int altIzq,altDer;
    if(!*arbol)
        return 1;
    altDer=alturaDeArbol(&(*arbol)->der);
    altIzq=alturaDeArbol(&(*arbol)->izq);

    if(ABS(altDer-altIzq)>1)
        return 0;
    return esAVL(&(*arbol)->izq)&&esAVL(&(*arbol)->der);

}

int esCompleto(t_arbol*arbol)
{
    int altura,cantNodos;
    altura=alturaDeArbol(arbol);
    cantNodos=contarNodosDeArbol(arbol);

    return (pow(2,altura)-1)==cantNodos;
}

int contarNodosHastaNivel(t_arbol*arbol,int nivel)
{
    if(!*arbol)
        return 0;
    if(!nivel)
        return 1;
    return contarNodosHastaNivel(&(*arbol)->izq,nivel-1)+contarNodosHastaNivel(&(*arbol)->der,nivel-1)+1;

}

int esCompletoHastaNivel(t_arbol*arbol,int nivel)
{
    if(!*arbol)
        return 0;
    if(nivel<0)
        return 1;
    if(!nivel)
        return 1;
    return esCompletoHastaNivel(&(*arbol)->izq,nivel-1)&&esCompletoHastaNivel(&(*arbol)->der,nivel-1);

}


int esBalanceado(t_arbol*arbol)
{
    int nivel=alturaDeArbol(arbol)-1;

    return esCompletoHastaNivel(arbol,nivel-1);
}

int recorrerHastaNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato))
{
    if(!*arbol)
        return 0;
    if(nivel<0)
        return 0;
    if(nivel>=0)
    {
        accion((*arbol)->dato);
    }

    return recorrerHastaNivel(&(*arbol)->izq,nivel-1,accion)+recorrerHastaNivel(&(*arbol)->der,nivel-1,accion)+1;
}

int recorrerNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato))
{
    if(!*arbol)
        return 0;
    if(nivel<0)
        return 0;
    if(!nivel)
    {
        accion((*arbol)->dato);
        return 1;
    }
    return recorrerNivel(&(*arbol)->izq,nivel-1,accion)+recorrerNivel(&(*arbol)->der,nivel-1,accion);
}

int recorrerAltura(const t_arbol*arbol,int altura,void(*accion)(const void*dato))
{
    return recorrerNivel(arbol,altura-1,accion);
}


int recorrerAPartirDeNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato))
{
    int contIzq,contDer;
    if(!*arbol)
        return 0;
    if(nivel<0)
    {
        accion((*arbol)->dato);
    }

    contDer=recorrerAPartirDeNivel(&(*arbol)->der,nivel-1,accion);
    contIzq=recorrerAPartirDeNivel(&(*arbol)->izq,nivel-1,accion);

    return nivel<0?(contDer+contIzq+1):(contDer+contIzq);
}

int eliminarHojas(t_arbol*arbol)
{
    if(!*arbol)
        return 0;
    if(!(*arbol)->izq&&!(*arbol)->der)
    {
        free((*arbol)->dato);
        free(*arbol);
        *arbol=NULL;
        return 1;
    }
    return eliminarHojas(&(*arbol)->izq)+eliminarHojas(&(*arbol)->der);
}

void eliminarArbol(t_arbol*arbol)
{
    if(!*arbol)
        return;
    eliminarArbol(&(*arbol)->izq);
    eliminarArbol(&(*arbol)->der);
    free((*arbol)->dato);
    free(*arbol);
    *arbol=NULL;
}

int arbolVacio(const t_arbol*arbol)
{
    return !*arbol;
}

void podarANivel(t_arbol*arbol,int nivel)
{
    if(!*arbol)
        return ;
    podarANivel(&(*arbol)->izq,nivel-1);
    podarANivel(&(*arbol)->der,nivel-1);
    if(nivel<0)
    {
        free((*arbol)->dato);
        free(*arbol);
        *arbol=NULL;
    }
}

void mostrarRaiz(const t_arbol*arbol,void(*accion)(const void*))
{
    if(!*arbol)
        return ;
    accion((*arbol)->dato);
}

t_arbol* buscarClaveMasGrande(t_arbol*arbol)
{
    if(!*arbol)
        return NULL;
    if((*arbol)->der)
        return buscarClaveMasGrande(&(*arbol)->der);
    return arbol;
}

t_arbol* buscarClaveMasChica(t_arbol*arbol)
{
    if(!*arbol)
        return NULL;
    if((*arbol)->izq)
        return buscarClaveMasChica(&(*arbol)->izq);
    return arbol;
}

t_arbol* buscarClaveEnArbol(t_arbol*arbol,void*clave,int(*f_cmp)(const void*,const void*))
{
    int cmp;
    if(!*arbol)
        return NULL;
    cmp=f_cmp(clave,(*arbol)->dato);
    if(cmp<0)
        return buscarClaveEnArbol(&(*arbol)->izq,clave,f_cmp);
    if(cmp>0)
        return buscarClaveEnArbol(&(*arbol)->der,clave,f_cmp);

    return arbol;
}

void eliminarRaiz(t_arbol*arbol)
{
    t_nodo**rempl;
    t_nodo*elim;
    if(!*arbol)
        return;
    elim=*arbol;
    free(elim->dato);
    if(!(*arbol)->izq&&!(*arbol)->der)
    {
        free(elim);
        *arbol=NULL;
        return;
    }
    rempl=alturaDeArbol(&(*arbol)->izq)>alturaDeArbol(&(*arbol)->der)?buscarClaveMasChica(&(*arbol)->izq):buscarClaveMasGrande(&(*arbol)->der);
    *arbol=*rempl;
    if((*rempl)->der)
        *rempl=(*rempl)->der;
    else
        *rempl=(*rempl)->izq;
    (*arbol)->izq=elim->izq;
    (*arbol)->der=elim->der;
    free(elim);

}

void generarArchivoOrdenado(t_arbol*arbol,FILE*pf,FILE*pf_ordenado,void(*grabar)(FILE*orig,FILE*orden,const void*dato))
{
    if(!*arbol)
        return;

    generarArchivoOrdenado(&(*arbol)->izq,pf,pf_ordenado,grabar);
    grabar(pf,pf_ordenado,(*arbol)->dato);
    generarArchivoOrdenado(&(*arbol)->der,pf,pf_ordenado,grabar);
}

int cargarArbolDesdeArchivoOrdenado(t_arbol*arbol,FILE*pf,int ini,int fin,unsigned tam)
{
    int medio;
    t_nodo* nodo;
    if(ini>fin)
        return 1;
    medio=(ini+fin)/2;

    nodo=malloc(sizeof(t_nodo));
    if(!nodo)
        return 0;
    nodo->dato=malloc(tam);
    if(!nodo->dato)
    {
        free(nodo);
        return 0;
    }
    fseek(pf,medio*tam,SEEK_SET);
    fread(nodo->dato,tam,1,pf);
    nodo->izq=NULL;
    nodo->der=NULL;
    nodo->tam=tam;
    *arbol=nodo;

    if(!cargarArbolDesdeArchivoOrdenado(&(*arbol)->izq,pf,ini,medio-1,tam))
        return 0;
    return cargarArbolDesdeArchivoOrdenado(&(*arbol)->der,pf,medio+1,fin,tam);

}

void guardarArbolEnArchivoPreOrden(t_arbol*arbol,FILE*pf_idx,unsigned tam)
{
    if(!*arbol)
        return;

    fwrite((*arbol)->dato,tam,1,pf_idx);
    guardarArbolEnArchivoPreOrden(&(*arbol)->izq,pf_idx,tam);
    guardarArbolEnArchivoPreOrden(&(*arbol)->der,pf_idx,tam);
}

//int cargarArbolDesdeArchivoPreorden(t_arbol*arbol,FILE*pf,unsigned tam)
//{
//
//}

int insertarRaiz(t_arbol*arbol,const void*dato,unsigned tam)
{
    t_nodo*nodo;
    if(!(nodo=malloc(sizeof(t_nodo))))
        return 0;
    if(!(nodo->dato=malloc(tam)))
    {
        free(nodo);
        return 0;
    }
}
