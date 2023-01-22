#include <stdio.h>
#include <stdlib.h>
#define TOL 0.1

double eALaX(unsigned x,double tol);

int main()
{
    unsigned x=4;

    printf("e a la %u: %lf",x,eALaX(x,TOL));

    return 0;
}

double eALaX(unsigned x,double tol)
{
    double termino=1,result=1;
    unsigned long exp=1,factorial=1,cont=1;

    while(termino>tol)
    {
        termino=((exp*=x)/(double)(factorial*=cont));
        cont++;
        result+=termino;
    }
return result;
}
