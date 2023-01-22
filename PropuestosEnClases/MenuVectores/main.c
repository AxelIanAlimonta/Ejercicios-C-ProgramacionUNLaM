#include "FuncionesVectores.h"

int main()
{
    int fin=0,cantElem=6,vec[TAM_VEC]= {1,2,2,4,2,6},opcion;
    while(!fin)
    {
        opcion=desplegarMenu();
        if(opcion)
            cantElem=ejecutarOpcion(opcion,cantElem,vec);
        else
            fin++;
    }

    return 0;
}
