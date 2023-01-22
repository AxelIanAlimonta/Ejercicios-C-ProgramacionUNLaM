#include <stdio.h>
#include <stdlib.h>

unsigned long multiplicacionRusa(unsigned long nro1,unsigned long nro2);

int main()
{
    unsigned long n1=35,n2=8;
    printf("%lu",multiplicacionRusa(n1,n2));
    return 0;
}

unsigned long multiplicacionRusa(unsigned long nro1,unsigned long nro2)
{
    unsigned long resultado=0;
    if(nro1%2)
        resultado+=nro2;
    while(nro1!=1)
    {
        nro1/=2;
        nro2*=2;
        if(nro1%2)
            resultado+=nro2;
    }
    return resultado;
}
