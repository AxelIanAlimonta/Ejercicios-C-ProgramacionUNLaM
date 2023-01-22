
#include "listaDoble.h"

int compararEnteros(const void*n1,const void*n2);
void mostrarEnteros(const void*nro);

int main()
{
    t_lista lista;
    int vec[]= {11,2,36,4,15,6},i;

    crearLista(&lista);

    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        insertarOrdenado(&lista,vec+i,sizeof(*vec),compararEnteros,1);

    recorrer(&lista,mostrarEnteros);

    printf("\n");
    recorrerInverso(&lista,mostrarEnteros);
    return 0;
}

int compararEnteros(const void*n1,const void*n2)
{
    return *(int*)n1-*(int*)n2;
}

void mostrarEnteros(const void*nro)
{
    printf("%i ",*(int*)nro);
}
