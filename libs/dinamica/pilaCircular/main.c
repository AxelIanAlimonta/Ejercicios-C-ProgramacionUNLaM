#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    t_pila pila;
    int i,dato;
    int vec[]= {1,2,3,4,5,6};

    crearPila(&pila);

    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        apilar(&pila,vec+i,sizeof(*vec));


//    printf("desapilar: ");
//    while(!pilaVacia(&pila))
//    {
//        desapilar(&pila,&dato,sizeof(dato));
//        printf("%i ",dato);
//    }

    vaciarPila(&pila);

    printf("pila vacia?: %s",pilaVacia(&pila)?"si":"no");

    return 0;
}
