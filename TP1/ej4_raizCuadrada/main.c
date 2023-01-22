#include <stdio.h>
#include <stdlib.h>
#define TOL 0.1
#define ABS(x) (((x)>=0)?(x):(-x))

double raizCuadrada(int x,double tol);

int main()
{
    int nro=4;
    printf("%lf",raizCuadrada(nro,TOL));
    return 0;
}

double raizCuadrada(int x,double tol)
{
    double terminoAnterior=1,terminoActual;
    double restaTerm;
    terminoActual=(0.5)*(terminoAnterior+(x/terminoAnterior));
    restaTerm=terminoActual-terminoAnterior;
    while((ABS(restaTerm))>tol)
    {
        terminoAnterior=terminoActual;
        terminoActual=(0.5)*(terminoAnterior+(x/terminoAnterior));
        restaTerm=terminoActual-terminoAnterior;
    }
    return terminoActual;
}
