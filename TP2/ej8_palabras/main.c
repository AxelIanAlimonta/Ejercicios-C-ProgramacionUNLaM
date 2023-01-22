#include "funciones.h"


int main()
{
    char cad[]="hola mundo hola hola mundo asdasdasdasd hola hola ";
    char primeraPalabra[100];
    int cantPriPalab,cantPalab,letrasMax;

    funcionPrincipal(cad,primeraPalabra,&cantPriPalab,&cantPalab,&letrasMax);

    printf("Texto: %s",cad);
    printf("\n\nLa primera palabra es %s y aparece %i veces",primeraPalabra,cantPriPalab);
    printf("\nEl texto tiene %i palabras",cantPalab);
    printf("\nLa palabra mas larga tiene %i caracteres",letrasMax);




    return 0;
}

