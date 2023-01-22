#include "funciones.h"

int cargarPilaDesdeArchivo(t_pila*pila,const char*nomArch)
{
    FILE*pf;
    char numC;
    int num;
    if(!(pf=fopen(nomArch,"rt")))
        return 0;

    while(fscanf(pf,"%c",&numC)!=EOF&&numC!='\n')
    {
        num=numC-'0';
        apilar(pila,&num,sizeof(num));
    }
    fclose(pf);
    return 1;
}

void sumarPilas(t_pila*pila1,t_pila*pila2,t_pila*pilaSuma)
{
    int carry=0,suma,num1,num2;
    while(!pilaVacia(pila1)&&!pilaVacia(pila2))
    {
        desapilar(pila1,&num1,sizeof(num1));
        desapilar(pila2,&num2,sizeof(num2));
        suma=(num1+num2+carry)%10;
        carry=(num1+num2+carry)/10;
        apilar(pilaSuma,&suma,sizeof(suma));
    }
    while(!pilaVacia(pila1))
    {
        desapilar(pila1,&num1,sizeof(num1));
        suma=(num1+carry)%10;
        carry=(num1+carry)/10;
        apilar(pilaSuma,&suma,sizeof(suma));
    }
    while(!pilaVacia(pila2))
    {
        desapilar(pila2,&num2,sizeof(num2));
        suma=(num2+carry)%10;
        carry=(num2+carry)/10;
        apilar(pilaSuma,&suma,sizeof(suma));
    }
    if(carry)
        apilar(pilaSuma,&carry,sizeof(carry));
}

int grabarArchivoDesdePila(t_pila*pila,const char*nomArch)
{
    FILE*pf;
    int nro;
    if(!(pf=fopen(nomArch,"wt")))
        return 0;
    while(desapilar(pila,&nro,sizeof(nro)))
    {
        fprintf(pf,"%i",nro);
    }
    fclose(pf);
    return 1;
}
