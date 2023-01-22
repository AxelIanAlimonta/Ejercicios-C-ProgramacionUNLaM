#include <stdio.h>
#include <stdlib.h>
#include "normalizarCad.h"

int main()
{
    char cad[]="   hoLa    muNDo ! Esta eS uNA cAdena NorMALIzaDa  !!    ";

    printf("Cadena normalizada: %s",normalizarCad(cad));

    return 0;
}
