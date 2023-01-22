#include <stdio.h>
#include <stdlib.h>

unsigned long factorial(unsigned nro);
double combinatorio(unsigned,unsigned);

int main()
{
    unsigned nro1=6,nro2=5;
    printf("%.2lf",combinatorio(nro1,nro2));
    return 0;
}

double combinatorio(unsigned m,unsigned n)
{
    return factorial(m)/(factorial(n)*factorial(m-n));
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
