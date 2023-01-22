#include "txtAbin.h"
#define NOM_ARCH_BIN "alumnos.bin"
#define NOM_ARCH_TXT "alumnos.txt"
int main()
{

    if(!crearLoteDePrueba(NOM_ARCH_TXT))
        return 10;
    if(!pasarDeTxtABin(NOM_ARCH_TXT,NOM_ARCH_BIN))
        return 11;

    printf("Mostrar BIN: \n");
    mostrarAlumnosBin(NOM_ARCH_BIN);


    return 0;
}
