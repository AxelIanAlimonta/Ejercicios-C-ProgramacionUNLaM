#include <stdio.h>
#include <stdlib.h>

long unsigned sumarNumParesMenoresAN(unsigned long nro);

int main()
{
    unsigned long nro=10;
    printf("%lu",sumarNumParesMenoresAN(nro));
    return 0;
}

long unsigned sumarNumParesMenoresAN(unsigned long nro)
{
    unsigned long suma=0,i;
    for(i=2; i<nro; i++)
    {
        if(!(i%2))
            suma+=i;
    }
    return suma;
}
