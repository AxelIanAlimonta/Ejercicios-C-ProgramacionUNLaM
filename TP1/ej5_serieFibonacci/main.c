#include <stdio.h>
#include <stdlib.h>

int serieFibonacci(int nro);

int main()
{
    int nro=34;
    printf("%i",serieFibonacci(nro));
    return 0;
}

int serieFibonacci(int nro)
{
    unsigned long termino1=1,termino2=1,result;

    while(result<nro)
    {
        result=termino1+termino2;
        termino1=termino2;
        termino2=result;
    }
    return result==nro;
}
