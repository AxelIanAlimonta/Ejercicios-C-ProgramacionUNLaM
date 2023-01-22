#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))

typedef struct sNodo
{
    void*dato;
    struct sNodo*izq,*der;
    unsigned tam;
}t_nodo;

typedef t_nodo* t_arbol;

void crearArbol(t_arbol*arbol);
int insertarEnArbol(t_arbol*arbol,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*));
int r_insertarEnArbol(t_arbol*arbol,const void*dato,unsigned tam,int(*f_cmp)(const void*,const void*));
int insertarRaiz(t_arbol*arbol,const void*dato,unsigned tam);
int arbolVacio(const t_arbol*arbol);
void recorrerInOrden(t_arbol*arbol,void(*accion)(const void*));
void recorrerPreOrden(t_arbol*arbol,void(*accion)(const void*));
void recorrerPosOrden(t_arbol*arbol,void(*accion)(const void*));
void mostrarArbol(t_arbol*arbol,void(*mostrar)(const void*,int desplazamiento));
void mostrarArbolAux(t_arbol*arbol,void(*mostrar)(const void*,int),int desplazamiento);
void mostrarRaiz(const t_arbol*arbol,void(*accion)(const void*));
int alturaDeArbol(t_arbol*arbol);
int contarNodosDeArbol(t_arbol*arbol);
int contarHojasDeArbol(t_arbol*arbol);
int contarRamasDeArbol(t_arbol*arbol);
int esAVL(const t_arbol*arbol);
int esCompleto(t_arbol*arbol);
int contarNodosHastaNivel(t_arbol*arbol,int nivel);
int esCompletoHastaNivel(t_arbol*arbol,int nivel);
int esBalanceado(t_arbol*arbol);
int recorrerHastaNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato));
int recorrerNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato));
int recorrerAltura(const t_arbol*arbol,int altura,void(*accion)(const void*dato));
int recorrerAPartirDeNivel(const t_arbol*arbol,int nivel,void(*accion)(const void*dato));
int eliminarHojas(t_arbol*arbol);
void eliminarArbol(t_arbol*arbol);
void eliminarRaiz(t_arbol*arbol);
void podarANivel(t_arbol*arbol,int nivel);
t_arbol* buscarClaveMasGrande(t_arbol*arbol);
t_arbol* buscarClaveMasChica(t_arbol*arbol);
t_arbol* buscarClaveEnArbol(t_arbol*arbol,void*clave,int(*f_cmp)(const void*,const void*));
int cargarArbolDesdeArchivoOrdenado(t_arbol*arbol,FILE*pf,int ini,int fin,unsigned tam);
int cargarArbolDesdeArchivoPreorden(t_arbol*arbol,FILE*pf,unsigned tam);

void generarArchivoOrdenado(t_arbol*arbol,FILE*pf,FILE*pf_ordenado,void(*grabar)(FILE*orig,FILE*orden,const void*dato));
void guardarArbolEnArchivoPreOrden(t_arbol*arbol,FILE*pf_idx,unsigned tam);


#endif // ARBOL_H_INCLUDED
