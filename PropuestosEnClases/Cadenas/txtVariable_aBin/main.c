#include "funciones.h"
#define NOM_ARCH_TXT "estudiantes.txt"
#define NOM_ARCH_BIN "estudiantes.bin"

int main()
{

    if(!crearLoteDePrueba(NOM_ARCH_TXT))
        return 101;
    if(!pasarDeTxtABin(NOM_ARCH_TXT,NOM_ARCH_BIN))
        return 102;
    if(!mostrarBin(NOM_ARCH_BIN))
        return 103;

    return 0;
}
