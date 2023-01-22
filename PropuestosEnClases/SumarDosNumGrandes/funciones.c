#include "funciones.h"
void cargarPila(FILE*archivo,t_pila*pila)
{
    int nro;
    char linea[100];
    char*p_linea=linea;
    fgets(linea,100,archivo);

    while(*p_linea)
    {
        nro=*p_linea-'0';
        apilar(pila,&nro,sizeof(int));
        p_linea++;
    }
}

void sumarPilas(t_pila*pila1,t_pila*pila2,t_pila*result)
{
    int carry=0,num1,num2,suma;

    while(!pilaVacia(pila1)&&!pilaVacia(pila2))
    {
        desapilar(pila1,&num1,sizeof(int));
        desapilar(pila2,&num2,sizeof(int));
        suma=(num1+num2+carry)%10;
        carry=(num1+num2+carry)/10;
        apilar(result,&suma,sizeof(int));
    }

    while(!pilaVacia(pila1))
    {
        desapilar(pila1,&num1,sizeof(int));
        suma=(num1+carry)%10;
        carry=(num1+carry)/10;
        apilar(result,&suma,sizeof(int));
    }

    while(!pilaVacia(pila2))
    {
        desapilar(pila2,&num2,sizeof(int));
        suma=(num2+carry)%10;
        carry=(num2+carry)/10;
        apilar(result,&suma,sizeof(int));
    }
    if(carry)
        apilar(result,&carry,sizeof(int));
}

void grabarArchivo(t_pila*pila,FILE*archivo)
{
    int nro;
    while(desapilar(pila,&nro,sizeof(int)))
    {
        fprintf(archivo,"%d",nro);
    }
}
