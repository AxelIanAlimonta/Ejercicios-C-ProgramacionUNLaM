#include <stdio.h>
#include <stdlib.h>
#define RDND(x) (((x)-(int)(x))>=0.5?(int)(x)+1:(int)(x))
#define MENOR(x,y) ((x)<(y)?(x):(y))
#define INTERCAMBIO(x,y) \
    aux=*(x);\
    *(x)=*(y);\
    *(y)=aux;


int menor(int nro1,int nro2);
void intercambiarEnteros(int*n1,int*n2);

int main()
{
    int n1=1,n2=2,aux;
    printf("redondeo 1: %i",RDND(10.33));
    printf("\nredondeo 2: %i",RDND(10.63));
    printf("\nmenor: %i",menor(n1,n2));
    printf("\nmenor: %i",MENOR(n1,n2));
    intercambiarEnteros(&n1,&n2);
    printf("\nn1: %i    n2: %i",n1,n2);
    INTERCAMBIO(&n1,&n2);
    printf("\nn1: %i    n2: %i",n1,n2);


    return 0;
}

int menor(int nro1,int nro2)
{
    return nro1<nro2?nro1:nro2;
}

void intercambiarEnteros(int*n1,int*n2)
{
    int aux;
    aux=*n1;
    *n1=*n2;
    *n2=aux;
}
