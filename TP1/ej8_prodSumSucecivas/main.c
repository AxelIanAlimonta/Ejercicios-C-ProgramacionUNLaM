#include <stdio.h>
#include <stdlib.h>

unsigned long prodPorSumasSucesivas(unsigned long nro1,unsigned long nro2);

int main()
{
    long unsigned nro1=6,nro2=9;
    printf("%lu * %lu: %lu",nro1,nro2,prodPorSumasSucesivas(nro1,nro2));
    return 0;
}

unsigned long prodPorSumasSucesivas(unsigned long nro1,unsigned long nro2)
{
    int i;
    unsigned long resultado=0;

    for(i=0; i<nro2; i++)
    {
        resultado+=nro1;
    }
    return resultado;
}
