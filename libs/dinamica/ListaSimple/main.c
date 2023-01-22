#include "Lista.h"

typedef struct
{
    int clave;
    int cant;
} t_info;


int compararClaves(const void*dato,const void*clave);
void acumInfo(void*acum,void*dato);

int compararEnteros(const void*n1,const void*n2);
void mostrarEnteros(void*nro);

void mostrarInfo(void*info);
int compararInfo(const void*inf1,const void*inf2);

int main()
{
    int i,acum=0,clave=3;
    t_info info[]=
    {
        {1,11},
        {2,12},
        {3,13},
        {1,14},
        {2,15},
        {3,16},
        {3,17},
        {2,18},
    };
    t_lista lista;
    crearLista(&lista);

    for(i=0; i<(sizeof(info)/sizeof(*info)); i++)
        insertarAlFinal(&lista,info+i,sizeof(*info));

//    eliminarPorClaveYRetornarAcumulado(&lista,&acum,&clave,compararClaves,acumInfo);

    ordenarLista(&lista,compararInfo);

    printf("%i",acum);
    recorrer(&lista,mostrarInfo);



//    int i;
//    int vec[]= {1,3,5,7};
//    int vec2[]= {1,1,2,2,3,3,4,4,6,6};
//    t_lista lista;
//    crearLista(&lista);
////
////    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
////        insertarAlFinal(&lista,vec+i,sizeof(*vec));
//
//    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
//        insertarEnOrden(&lista,vec+i,sizeof(*vec),compararEnteros,0);
//    recorrer(&lista,mostrarEnteros);
//
//    puts("\n");
//    for(i=0; i<(sizeof(vec2)/sizeof(*vec2)); i++)
//        insertarEnOrden(&lista,vec2+i,sizeof(*vec2),compararEnteros,0);
//    recorrer(&lista,mostrarEnteros);
//////
////    eliminarPrimerelemento(&lista);
////    eliminarUltimoElemento(&lista);
//    eliminarElementoEnPos(&lista,7);
//
//    puts("\n");
//    recorrer(&lista,mostrarEnteros);

    return 0;
}

int compararEnteros(const void*n1,const void*n2)
{
    return(*(int*)n1-*(int*)n2);
}

void mostrarEnteros(void*nro)
{
    printf("%i ",*(int*)nro);
}




int compararClaves(const void*dato,const void*clave)
{
    return ((t_info*)dato)->clave-(*(int*)clave);
}

void acumInfo(void*acum,void*dato)
{
    *(int*)acum+=((t_info*)dato)->cant;
}

void mostrarInfo(void*info)
{
    printf("\n%i %i",((t_info*)info)->clave,((t_info*)info)->cant);
}

int compararInfo(const void*inf1,const void*inf2)
{
    t_info*info1,*info2;
    info1=(t_info*)inf1;
    info2=(t_info*)inf2;

    if(!(info1->clave-info2->clave))
        return (info1->cant-info2->cant);
    return info1->clave-info2->clave;
}
