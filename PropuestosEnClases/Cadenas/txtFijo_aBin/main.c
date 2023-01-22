#include "funciones.h"
#define NOM_ARCH_TXT "estuduiantes.txt"
#define NOM_ARCH_BIN "estuduiantes.bin"

int main()
{
    if(!crearLoteDePruebas(NOM_ARCH_TXT))
        return 101;
    if(!pasarTxtABin(NOM_ARCH_TXT,NOM_ARCH_BIN))
        return 102;
    if(!mostrarBin(NOM_ARCH_BIN))
        return 103;

    return 0;
}
