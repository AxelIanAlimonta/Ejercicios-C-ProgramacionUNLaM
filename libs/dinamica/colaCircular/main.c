#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main()
{
    t_cola cola;
    int i,dato;
    int vec[]= {1,2,3,4,5,6};

    crearCola(&cola);

    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        ponerEnCola(&cola,vec+i,sizeof(*vec));


    printf("desacolar: ");
    while(!colaVacia(&cola))
    {
        sacarDeCola(&cola,&dato,sizeof(dato));
        printf("%i ",dato);
    }

//    vaciarCola(&cola);
//
    printf("\ncola vacia?: %s",colaVacia(&cola)?"si":"no");

    return 0;
}
