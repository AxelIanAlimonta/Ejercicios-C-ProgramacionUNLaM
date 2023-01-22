#include "archivosBin.h"
#define NOM_ARCH "alumnos.bin"

int main()
{
    if(!grabarArchivo(NOM_ARCH))
        printf("\nError al grabar archivo!!");
    system("cls");
    printf("Lectura de Archivo: \n");
    leerArchivo(NOM_ARCH);
    return 0;
}
