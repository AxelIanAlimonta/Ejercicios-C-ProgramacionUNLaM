#include "mi_atoi.h"

int mi_atoi(char*cad)
{
    int signo=1;
    int resultado=0;
    while(ES_BLANCO(*cad))
        cad++;

    if(*cad=='-'||*cad=='+')
    {
        if(*cad=='-')
            signo=-1;
        cad++;
    }
    while(ES_NUMERO(*cad))
    {
        resultado*=10;
        resultado+=(*cad-'0');
        cad++;
    }
    return signo*resultado;
}
