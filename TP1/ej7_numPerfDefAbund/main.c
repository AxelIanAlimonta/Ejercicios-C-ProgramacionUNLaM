#include <stdio.h>
#include <stdlib.h>

int esPerfDefAbun(unsigned long nro);

int main()
{
    unsigned long nroDef=10,nroPerf=6,nroAbun=12;
    printf("deficiente: %i",esPerfDefAbun(nroDef));
    printf("\nperfecto: %i",esPerfDefAbun(nroPerf));
    printf("\nabundante: %i",esPerfDefAbun(nroAbun));
    return 0;
}

int esPerfDefAbun(unsigned long nro)
{
    int i;
    unsigned long acum=0;

    for(i=1; i<nro-1; i++)
    {
        if(!(nro%i))
            acum+=i;
    }
    return acum-nro;
}
