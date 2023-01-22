#include "contarOcurrencias.h"

int main()
{
    char cad[]="anananananananana";
    char subcad[]="ana";
    printf("\nCantidad de ocurrencias con solapamiento: %i",contarOcurrenciasConSolapamiento(cad,subcad));
    printf("\nCantidad de ocurrencias sin solapamiento: %i",contarOcurrenciasSinSolapamiento(cad,subcad));
    return 0;
}
