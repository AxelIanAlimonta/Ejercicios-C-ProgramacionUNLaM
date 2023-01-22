#include <stdio.h>
#include <stdlib.h>
#include "mi_atof.h"
#define ES_BLANCO(x) (((x)==' ')||((x)=='\n'))

float mi_atof(const char*cad)
{
    float signo=1,parteEntera=0,mantiza=0,despMant=10;
    while(ES_BLANCO(*cad))
        cad++;
    if(*cad=='+'||*cad=='-')
    {
        if(*cad=='-')
            signo=-1;
        cad++;
    }
    while(*cad>='0'&&*cad<='9')
    {
        parteEntera*=10;
        parteEntera+=*cad-'0';
        cad++;
    }
    if(*cad=='.')
        cad++;
    while(*cad>='0'&&*cad<='9')
    {
        mantiza+=((*cad-'0')/(float)despMant);
        despMant*=10;
        cad++;
    }
    return signo*(parteEntera+mantiza);


}
