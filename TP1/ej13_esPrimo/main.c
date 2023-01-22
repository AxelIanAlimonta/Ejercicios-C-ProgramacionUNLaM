#include <stdio.h>
#include <stdlib.h>

int esPrimo(unsigned nro);

int main()
{
    unsigned nro=54;
    printf("%i",esPrimo(nro));
    return 0;
}

int esPrimo(unsigned nro)
{
    int i;
    for(i=2;i<nro;i++)
    {
        if(!(nro%i))
            return 0;
    }
    return 1;
}
