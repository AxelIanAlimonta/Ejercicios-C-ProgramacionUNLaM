#include "funciones.h"
#define NOM_ARCH "datos.txt"

int main()
{
    int err;


    if(!(err=crearLoteDePruebas(NOM_ARCH)))
        return err;
    if(!(err=ejercicio11(NOM_ARCH)))
        return err;

    return 0;
}
