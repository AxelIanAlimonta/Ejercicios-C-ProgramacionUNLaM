#include <stdio.h>
#include <stdlib.h>
#include "miStringH.h"
#define TAM_CAD1 100
#define TAM_CAD2 100

int main()
{
    int i,tamCad;
    char cad1[TAM_CAD1]="Hola ",cad2[TAM_CAD2]="Mundo!! :D";
    char*miStrchrVar,*miStrrchrVar,*miStrstrVar;
    char cadMay[100]="CCC",cadMen[100]="AAA",cadMed[100]="BBB";
    char cadMay2[100]="ccc";
    char cadNro[100]="123";


    printf("Cad1: %s",cad1);
    printf("\nCad2: %s",cad2);

    printf("\nStrCat: %s\n",miStrCat(cad1,cad2));
    printf("\nmiStrLen: %i\n",miStrLen(cad1));

    miStrchrVar=miStrChr(cad1,'o');
    if(miStrchrVar)
        printf("\nmiStrChr: %s\n",miStrchrVar);
    else
        printf("\nmiStrChr No encontro el caracter en la cadena!\n");

    miStrrchrVar=miStrrchr(cad1,'o');
    if(miStrrchrVar)
        printf("\nmiStrrChr: %s\n",miStrrchrVar);
    else
        printf("\nmiStrrChr No encontro el caracter en la cadena!\n");

    tamCad=miStrLen(cad1);
    for(i=0; i<tamCad; i++)
        cad1[i]=miToupper(cad1[i]);
    printf("\nmiToupper: %s",cad1);

    tamCad=miStrLen(cad1);
    for(i=0; i<tamCad; i++)
        cad1[i]=miTolower(cad1[i]);
    printf("\nmiTolower: %s",cad1);

    printf("\n\nmiStrupr: %s",miStrupr(cad1));
    printf("\nmiStrlwr: %s\n\n",miStrlwr(cad1));


    printf("\n\nmiStrcmp: ");
    printf("\n%s - %s: %i",cadMay,cadMed,miStrcmp(cadMay,cadMed));
    printf("\n%s - %s: %i",cadMay,cadMen,miStrcmp(cadMay,cadMen));
    printf("\n%s - %s: %i",cadMed,cadMay2,miStrcmp(cadMed,cadMay));
    printf("\n%s - %s: %i",cadMed,cadMen,miStrcmp(cadMed,cadMen));
    printf("\n%s - %s: %i",cadMen,cadMay2,miStrcmp(cadMen,cadMay));
    printf("\n%s - %s: %i",cadMen,cadMed,miStrcmp(cadMen,cadMed));

    printf("\n\nmiStrcmpi: \n");
    printf("%s - %s: %i\n",cadMay,cadMay2,miStrcmpi(cadMay,cadMay2));

    miStrstrVar=miStrstr("!!",cad1);
    if(miStrstrVar)
        printf("\n\nmiStrstr: %s\n",miStrstrVar);
    else
        printf("\n\nmiStrstr no encontro la subcadena\n");

    printf("\n\natoi \"%s\": %i\n",cadNro,miAtoi(cadNro));

    return 0;
}

