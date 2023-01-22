#include "funciones.h"

int desplegarMenu(float *vec,int cantElem)
{
    int opc;
    system("cls");
    printf("\n ~~~~ Menu ~~~~ ");
    printf("\n1- Busca el minimo elemento");
    printf("\n2- Calcula prom de posiciones pares");
    printf("\n3- Mostrar en orden inverso");
    printf("\n0- Salir\n");

    scanf("%i",&opc);

    switch(opc)
    {
    case 1:
        printf("\nMinimo del vector: %.2f\n",minimoElemento(vec,cantElem));
        system("pause");
        break;
    case 2:
        printf("\nProm de pos pares: %.2f\n",promPosPares(vec,cantElem));
        system("pause");
        break;
    case 3:
        printf("\nVector en orden inverso: ");
        mostrarInverso(vec,cantElem);
        puts("\n");
        system("pause");
        break;
    }
    return opc;
}

int ingresarDatos(float*vec,int cantMaxElem)
{
    float nro;
    int elemIngresados=0;
    char seguirIngresando;

    printf("Desea ingresar un flotante? s/n: ");
    fflush(stdin);
    scanf("%c",&seguirIngresando);

    while(seguirIngresando=='s'||seguirIngresando=='S')
    {
        printf("\nIngrese el flotante: ");
        scanf("%f",&nro);
        *vec=nro;
        elemIngresados++;
        printf("\nDesea ingresar un otro flotante? s/n: ");
        fflush(stdin);
        scanf("%c",&seguirIngresando);
    }
    return elemIngresados;
}

float minimoElemento(float*vec,int cantElem)
{
    float minimo=*vec;
    while(cantElem)
    {
        if(*vec<minimo)
            minimo=*vec;
        vec++;
        cantElem--;
    }
    return minimo;
}

float promPosPares(float *vec,int cantElem)
{
    float acum;
    int cantPares=0;
    vec++;
    cantElem--;
    while(cantElem>0)
    {
        acum+=*vec;
        vec+=2;
        cantPares++;
        cantElem-=2;
    }
    return acum/cantPares;
}

void mostrarInverso(float*vec,int cantElem)
{
    int i;
    vec+=cantElem-1;
    for(i=0; i<cantElem; i++)
    {
        printf("%.2f ",*vec);
        vec--;
    }

}

int grabarArchivo(float* vec,int cantElem)
{
    FILE*pf;
    int i;
    if(!(pf=fopen("archivo.txt","wt")))
    {
        printf("No se pudo abrir archivo.txt para escritura");
        return 0;
    }
    for(i=0;i<cantElem;i++)
    {
        fprintf(pf,"%f\n",*vec);
        vec++;
    }
    fclose(pf);
    return 1;

}

