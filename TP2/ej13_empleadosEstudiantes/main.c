#include "funciones.h"
#define NOM_ARCH_EST "estudiantes.bin"
#define NOM_ARCH_EMPL "empleados.bin"

int main()
{
    int err;
    if(!(err=crearLoteDePrueba(NOM_ARCH_EST,NOM_ARCH_EMPL)))
        return err;
    if(!(err=actualizarEmpleados(NOM_ARCH_EST,NOM_ARCH_EMPL)))
        return err;
    mostrarArchivoEmpleados(NOM_ARCH_EMPL);

    return 0;
}
