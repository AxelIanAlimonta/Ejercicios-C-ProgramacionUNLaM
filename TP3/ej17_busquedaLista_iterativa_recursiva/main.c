#include "funciones.h"
#include "Lista.h"

int main()
{
    int i;
    t_lista lista;
    t_prod clave= {6,0};

    t_prod vec[]=
    {
        {1,50},
        {2,550},
        {2,550},
        {2,550},
        {3,230},
        {3,230},
        {4,190},
        {5,180},
        {6,100},
        {6,200},
        {6,300},
        {6,400},
        {6,500},
    };

    crearLista(&lista);

    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        insertarOrdenadoEnLista(&lista,vec+i,sizeof(*vec),compararProd,1);
    printf("Insertar Ordenado: \n");
    recorrerLista(&lista,mostrarProd);

//    r_buscar_cla(&lista,&clave,compararCodigos,recuperarProd,1);
//    printf("\nClave Recuperada: cod>-%i   precio->%.2f",clave.cod,clave.precio);
//    printf("\nLista despues de recuperar Clave:\n");
//    recorrerLista(&lista,mostrarProd);


//    printf("\nContar clave( %i ): %i",mostrarCodClave(&clave),r_contar_cla(&lista,&clave,compararCodigos,0));
//    printf("\nLista Despues de contar:\n");
//    recorrerLista(&lista,mostrarProd);

    int ocurrencia=1;
    printf("\nRecuperar clave (%i), en ocurrencia (%i): ",mostrarCodClave(&clave),ocurrencia);
    if(r_buscar_cla_n(&lista,&clave,compararCodigos,recuperarProd,ocurrencia))
    {
        printf("\nClave Recuperada: ");
        mostrarProd(&clave);
    }
    else printf("\nNo se encontro clave en esa ocurrencia");




    return 0;
}
