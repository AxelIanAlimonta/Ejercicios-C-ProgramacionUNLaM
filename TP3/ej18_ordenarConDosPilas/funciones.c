#include "funciones.h"

int crearLoteDePruebas(const void*nombArch)
{
    FILE*pf;
    int vec[]= {4,2,6,1,8,3,9,5,7};
    pf=fopen(nombArch,"wb");
    if(!pf)
        return 0;
    fwrite(vec,sizeof(vec),1,pf);
    fclose(pf);
    return 1;
}

void apilarDato(int dato,t_pila*pila1,t_pila*pila2)
{
    int datoPila;
    if(pilaVacia(pila1))
    {
        apilar(pila1,&dato,sizeof(dato));
        return ;
    }

    verTopeDePila(pila1,&datoPila,sizeof(datoPila));
    while(!pilaVacia(pila1)&&compararEnteros(dato,datoPila)>0)
    {
        desapilar(pila1,&datoPila,sizeof(datoPila));
        apilar(pila2,&datoPila,sizeof(datoPila));
        verTopeDePila(pila1,&datoPila,sizeof(datoPila));
    }

    verTopeDePila(pila2,&datoPila,sizeof(pila2));
    while(!pilaVacia(pila2)&&compararEnteros(dato,datoPila)<0)
    {
        desapilar(pila2,&datoPila,sizeof(pila2));
        apilar(pila1,&datoPila,sizeof(datoPila));
        verTopeDePila(pila2,&datoPila,sizeof(pila2));
    }
    apilar(pila1,&dato,sizeof(dato));
}

int compararEnteros(int n1,int n2)
{
    return n1-n2;
}

void juntarPilasMenorAMayor(t_pila*pila1,t_pila*pila2)
{
    int dato;
    while(!pilaVacia(pila2))
    {
        desapilar(pila2,&dato,sizeof(dato));
        apilar(pila1,&dato,sizeof(dato));
    }
}
