#include <stdio.h>
#include <stdlib.h>

unsigned long factorial(unsigned nro);

int main()
{
    unsigned nro=5;

    printf("%lu",factorial(nro));

    return 0;
}

unsigned long factorial(unsigned nro)
{
    int i;
    unsigned long resultado=1;
    if(!nro)
        return 1;
    for(i=1;i<=nro;i++)
    {
        resultado*=i;
    }
    return resultado;
}
