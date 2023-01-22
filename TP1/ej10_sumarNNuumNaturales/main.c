#include <stdio.h>
#include <stdlib.h>

unsigned long sumaNNumNaturales(unsigned long nro);

int main()
{
    long unsigned nro=9;
    printf("%lu",sumaNNumNaturales(nro));

    return 0;
}

unsigned long sumaNNumNaturales(unsigned long nro)
{
    unsigned long suma=0,i;
    for(i=1;i<=nro;i++)
    {
        suma+=i;
    }
    return suma;
}
