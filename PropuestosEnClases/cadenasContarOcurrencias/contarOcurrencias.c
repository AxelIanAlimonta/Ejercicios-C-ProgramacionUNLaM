#include "contarOcurrencias.h"

unsigned contarOcurrenciasConSolapamiento(char*cad,char*subcad)
{
    unsigned contador=0;
    while(*cad)
    {
        if(coincidencia(cad,subcad))
            contador++;
        cad++;
    }
    return contador;
}

int coincidencia(char*cad,char*subcad)
{
    while(*subcad)
    {
        if(*cad==*subcad)
        {
            cad++;
            subcad++;
        }
        else return 0;
    }
    return 1;
}

unsigned contarOcurrenciasSinSolapamiento(char*cad,char*subcad)
{
    unsigned contador=0;
    while(*cad)
    {
        cad=coincidenciaConSolapamiento(cad,subcad,&contador);
    }
    return contador;
}

char* coincidenciaConSolapamiento(char*cad,char*subcad,unsigned *contador)
{
    char*cadIni=cad;
    while(*subcad)
    {
        if(*subcad==*cad)
        {
            cad++;
            subcad++;
        }
        else
            return cadIni+1;
    }
    (*contador)++;
    return cad;
}
