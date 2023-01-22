#include "funciones.h"


int main()
{
    if(!(crearLoteDePrueba(ARCH_LOTE)))
    {
        printf("No se pudo crear lote de prueba!!");
        return 101;
    }

    if(!crearDatos1(ARCH_LOTE,NOM_ARCH_1))
    {
        printf("No se pudo crear datos1");
        return 102;
    }
    if(!(crearDatos2(ARCH_LOTE,NOM_ARCH_2)))
    {
        printf("No se pudo crear datos2");
        return 103;
    }

    printf("Arch1: \n");
    mostrarArchProd(NOM_ARCH_1);

    printf("Arch2: \n");
    mostrarArchProd(NOM_ARCH_2);


    return 0;
}
