#include "funciones.h"

void funcionPrincipal(const char*cadena,char*primeraPalabra,int* contPriPalabra,int* contPalabras,int*letrasMax)
{
    int cantLetras;
    char*iniPal,*finPal;
    *letrasMax=0;
    *contPriPalabra=0;
    *contPalabras=0;

    if(!(*letrasMax=proximaPalabra(cadena,&iniPal,&finPal)))
        return;
    copiarPrimPalabra(primeraPalabra,iniPal,finPal);
    (*contPriPalabra)++;
    (*contPalabras)++;

    while((cantLetras=proximaPalabra(finPal+1,&iniPal,&finPal)))
    {
        if(!compararPrimPalab(iniPal,primeraPalabra))
            (*contPriPalabra)++;
        (*contPalabras)++;
        if(cantLetras>*letrasMax)
            (*letrasMax)=cantLetras;
    }
}
int proximaPalabra(const char*cad,char**iniPalabra,char**finPalabra)
{
    int cantLetras=0;
    if(!*cad)
        return 0;
    while(*cad&&!ES_LETRA(*cad))
        cad++;
    if(!*cad)
        return 0;
    *iniPalabra=(char*)cad;
    while(ES_LETRA(*cad))
    {
        cad++;
        cantLetras++;
    }
    *finPalabra=(char*)cad-1;
    return cantLetras;
}

void copiarPrimPalabra(char*primPalab,const char*iniPal,const char*finPal)
{
    while(iniPal<=finPal)
    {
        *primPalab=*iniPal;
        primPalab++;
        iniPal++;
    }
    *primPalab='\0';
}

int compararPrimPalab(const char*cad,const char*primPalabra)
{
    while(*cad&&*primPalabra&&(*cad==*primPalabra))
    {
        cad++;
        primPalabra++;
    }
    if(!*primPalabra&&!ES_LETRA(*cad))
        return 0;
    else
        return 1;
}
