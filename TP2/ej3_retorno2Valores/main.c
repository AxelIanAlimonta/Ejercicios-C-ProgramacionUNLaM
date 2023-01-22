#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float prom;
    long suma;
}t_datos;

float sumaYProm(int*vec,int cantElem,long* suma);
t_datos sumaYProm2(int*vec,int cantElem);


int main()
{
    int vec[]={1,2,3,4,5,6,7};
    int cantElem=sizeof(vec)/sizeof(*vec);
    long suma=0;
    t_datos datos;

    float prom=sumaYProm(vec,cantElem,&suma);
    printf("Prom1: %.2f\tSuma1: %li",prom,suma);

    datos=sumaYProm2(vec,cantElem);
    printf("\nProm2: %.2f\tSuma2: %li",datos.prom,datos.suma);


    return 0;
}

float sumaYProm(int*vec,int cantElem,long *suma)
{
    int i;
    for(i=0;i<cantElem;i++)
    {
        *suma+=*vec;
        vec++;
    }
    return *suma/(float)cantElem;
}

t_datos sumaYProm2(int*vec,int cantElem)
{
    int i;
    t_datos datos;
    datos.suma=0;
    for(i=0;i<cantElem;i++)
    {
        datos.suma+=*vec;
        vec++;
    }
    datos.prom=datos.suma/cantElem;
    return datos;
}
