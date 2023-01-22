#include <stdio.h>
#include <stdlib.h>
#define TOL 0.01
#define ABS(x) ((x)>=0?(x):(-x))

double senoDeX(double x,double tol);

int main()
{
    double x=(3.14159265/2);
    printf("%lf",senoDeX(x,TOL));
    return 0;
}

double senoDeX(double x,double tol)
{
    unsigned long fact=1,cont=1;
    double potencia=x,termino,result;
    int signo=-1;

    termino=potencia/fact;
    result=termino;

    while(ABS(termino)>tol)
    {
        potencia*=(x*x);
        fact*=((cont+1)*(cont+2));
        termino=signo*(potencia/fact);
        result+=termino;
        signo*=-1;
        cont+=2;
    }
    return result;

}
