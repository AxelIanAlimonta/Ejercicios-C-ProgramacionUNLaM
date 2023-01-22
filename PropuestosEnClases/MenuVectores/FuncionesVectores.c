#include "FuncionesVectores.h"
#define OPC_VALIDA(x) (((x)>=1&&(x)<=6)||(x)==0)

int desplegarMenu()
{
    int opcion;
    system("cls");
    printf("~~~~~ Menu ~~~~~");
    printf("\n1 - Insertar en posicion");
    printf("\n2 - Insertar ordenado");
    printf("\n3 - Eliminar de posicion");
    printf("\n4 - Eliminar primera aparicion de elemento");
    printf("\n5 - Eliminar todas las apariciones de elemento");
    printf("\n6 - Mostrar Vector: ");
    printf("\n0 - Salir");
    printf("\n\nOpcion: ");
    scanf("%i",&opcion);
    while(!OPC_VALIDA(opcion))
    {
        printf("\nOpcion invalida, ingrese otra: ");
        scanf("%i",&opcion);
    }
    return opcion;

}

int ejecutarOpcion(int opcion,int cantElem,int* vec)
{
    switch(opcion)
    {
    case 1:
        insertarEnPosicion(cantElem,vec);
        cantElem++;
        break;
    case 2:
        insertarOrdenado(vec,cantElem);
        cantElem++;
        break;
    case 3:
        eliminarDePosicion(vec,cantElem);
        cantElem--;
        break;
    case 4:
        eliminarPrimeraAparicion(vec,cantElem);
        cantElem--;
        break;
    case 5:
        cantElem=eliminarTodasLasApariciones(vec,cantElem);
        break;
    case 6:
        mostrarVector(vec,cantElem);
    case 0:
        break;

    }
    return cantElem;
}

void insertarEnPosicion(int cantElem,int*vec)
{
    int pos,elem,aux,i;
    system("cls");
    printf("\nIngrese la posicion en la que desea insertar: ");
    scanf("%i",&pos);
    while(pos<1||pos>(cantElem+1))
    {
        printf("\nPosicion ingresada invalida, Ingrese otra (%i a %i): ",1,cantElem+1);
        scanf("%i",&pos);
    }
    printf("\nIngrese el elemento a insertar: ");
    scanf("%i",&elem);
    vec+=(pos-1);
    for(i=0; i<=(cantElem-pos+1); i++)
    {
        aux=*vec;
        *vec=elem;
        elem=aux;
        vec++;
    }
    printf("\nElemento insertado exitosamente!! Presione enter para continuar...");
    getch();
}

void mostrarVector(int*vec,int cantElem)
{
    int i;
    system("cls");
    printf("\n\nVector:");
    for(i=0; i<cantElem; i++)
    {
        printf(" %i",*vec);
        vec++;
    }
    printf("\nPresione enter para continuar...");
    getch();
}

void insertarOrdenado(int*vec,int cantElem)
{
    int elem,pos=1,i,aux;
    system("cls");
    printf("\nIngrese el elemento que desea insertar: ");
    scanf("%i",&elem);
    while(*vec<elem&&pos<TAM_VEC&&pos<=cantElem)
    {
        vec++;
        pos++;
    }
    if(pos>TAM_VEC)
        return;
    else
    {
        for(i=0; i<=(cantElem-pos+1); i++)
        {
            aux=*vec;
            *vec=elem;
            elem=aux;
            vec++;
        }
    }
    printf("\n\nElemento insertado exitosamente!! presione enter para copntinuar...");
    getch();

}

void eliminarDePosicion(int*vec,int cantElem)
{
    int pos,i;
    system("cls");
    if(!cantElem)
    {
        printf("\nNo hay elementos para eliminar!!");
        printf("\nPresione enter para continuar...");
        getch();
        return;
    }
    printf("\nIngrese posicion de elemento a eliminar: ");
    scanf("%i",&pos);
    while(pos>cantElem)
    {
        printf("\nPosicion invalida ingrese otra (de %i a %i): ",1,cantElem);
        scanf("%i",&pos);
    }
    vec+=(pos-1);
    for(i=0; i<(cantElem-pos); i++)
    {
        *vec=*(vec+1);
        vec++;
    }
    printf("\nElemento eliminado exitosamente!!! presione enter para continuar...");
    getch();
}

void eliminarPrimeraAparicion(int*vec,int cantElem)
{
    int elemen,pos=1,i;
    system("cls");
    printf("\nIngrese el elemento que desea eliminar: ");
    scanf("%i",&elemen);
    while(pos<=TAM_VEC&&*vec!=elemen)
    {
        vec++;
        pos++;
    }
    if(pos<=TAM_VEC)
    {
        for(i=0; i<=(cantElem-pos); i++)
        {
            *vec=*(vec+1);
            vec++;
        }
    }
    printf("\nElemento eliminado exitosamente!!! presione enter para continuar...");
    getch();
}

int eliminarTodasLasApariciones(int*vec,int cantElem)
{
    int elem,pos=1,desplazamiento=0;
    system("cls");
    printf("\nIngrese el elemento que desea eliminar: ");
    scanf("%i",&elem);
    while(pos<=cantElem)
    {
        if(*vec==elem)
            desplazamiento++;
        else
            vec++;
        *vec=*(vec+desplazamiento);
        pos++;
    }
    printf("\nElementos eliminados exitosamente!!! presione enter para continuar...");
    getch();
    return cantElem-desplazamiento;
}
