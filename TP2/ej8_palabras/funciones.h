#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ES_LETRA(x) (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))

void funcionPrincipal(const char*cadena,char*primeraPalabra,int* contPriPalabra,int* contPalabras,int*letrasMax);
int proximaPalabra(const char*cad,char**iniPalabra,char**finPalabra);
void copiarPrimPalabra(char*primPalab,const char*iniPal,const char*finPal);
int compararPrimPalab(const char*cad,const char*primPalabra);



#endif // FUNCIONES_H_INCLUDED
