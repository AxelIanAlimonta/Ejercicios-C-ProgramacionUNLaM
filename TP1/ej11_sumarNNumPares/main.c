#include <stdio.h>
#include <stdlib.h>

unsigned long sumaNNumNaturales(unsigned long nro);

int main()
{
    long unsigned nro=10;
    printf("%lu",sumaNNumNaturales(nro));
    return 0;
}

unsigned long sumaNNumNaturales(unsigned long nro)
{
    long unsigned suma,i;

    for(i=2;i<=nro;i++)
    {
        if(!(i%2))
            suma+=i;
    }
    return suma;
}
