#include <stdio.h>
#include <stdlib.h>
#include "normalizarCad.h"
#define ES_BLANCO(x) (((x)==' ')||((x)=='\n'))
#define ES_MAYUSCULA(x) (((x)>='A')&&((x)<='Z'))
#define ES_MINUSCULA(x) (((x)>='a')&&((x)<='z'))
#define ES_LETRA(x) (ES_MAYUSCULA(x)||ES_MINUSCULA(x))
#define TO_LWR(x) (ES_MAYUSCULA(x)?((x)+('a'-'A')):(x))
#define TO_UPR(x) (ES_MINUSCULA(x)?((x)-('a'-'A')):(x))
#define ES_SIMBOLO(x) ((x)==','||(x)=='!'||(x)==':'||(x)=='?'||(x)=='.'||(x)=='-'||(x)=='_')

char* normalizarCad(char*cad)
{
    char*recorrer=cad,*cadIni=cad;
    int primeraLetra=1;

    while(ES_BLANCO(*recorrer))
        recorrer++;
    while(*recorrer)
    {
        if(ES_SIMBOLO(*recorrer))
        {
            if(ES_BLANCO(*(cad-1)))
            {
                *(cad-1)=*recorrer;
                recorrer++;
            }
            else
            {

                *cad=*recorrer;
                recorrer++;
                cad++;
            }
        }

        while(ES_LETRA(*recorrer))
        {
            if(primeraLetra)
            {
                *cad=TO_UPR(*recorrer);
                primeraLetra=0;
            }
            else
                *cad=TO_LWR(*recorrer);
            cad++;
            recorrer++;
        }
        primeraLetra=1;
        if(ES_BLANCO(*recorrer))
        {
            *cad=*recorrer;
            cad++;
            recorrer++;
        }
        while(ES_BLANCO(*recorrer))
            recorrer++;
    }
    if(*(cad-1)==' ')
        *(cad-1)='\0';
    else
        *cad='\0';
    return cadIni;
}
