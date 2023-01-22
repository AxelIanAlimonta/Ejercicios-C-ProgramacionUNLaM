#include <stdio.h>
#include <stdlib.h>

int esPalindromo(char*cad);

int main()
{
    char cad[]="HolaloH";

    printf("%i",esPalindromo(cad));
    return 0;
}

int esPalindromo(char*cad)
{
    char*cadIni=cad;
    while(*cad)
        cad++;
    cad--;
    while(cadIni<cad)
    {
        if(*cad!=*cadIni)
            return 0;
        cad--;
        cadIni++;
    }
    return 1;
}
