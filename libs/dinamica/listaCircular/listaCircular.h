#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

typedef struct sNodo
{
    void*dato;
    struct sNodo*sig;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_listaC;

void crearLista(t_listaC*lista);
int insertarEnListaCircular(t_listaC*lista,const void*dato,unsigned tam);
void recorrerListaCircular(t_listaC*lista,void(*accion)(const void*dato));
int eliminarPorClaveDeListaCircular(t_listaC*lista,void*clave,int(*f_cmp)(const void*dato,const void*clave),void recuperarInfo(const void*info,void*clave),int duplicado);


int listaVacia(t_listaC*lista);

#endif // LISTACIRCULAR_H_INCLUDED
