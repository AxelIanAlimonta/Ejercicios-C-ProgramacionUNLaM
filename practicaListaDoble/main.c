#include "funciones.h"
#include "listaDoble.h"

int main()
{
    int i;
    t_listaDoble lista;
    t_prod vec[]=
    {
        {400,"Queso",45,600},
        {700,"Pure de Tomate",70,40},
        {100,"Arroz",50,70},
        {300,"Pan",55,90},
        {500,"Lentejas",40,110},
        {200,"Fideos",60,40},
        {600,"Arvejas",65,110},
    };

    crearLista(&lista);

    printf("\nInsertar en Lista: \n");
    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        insertarEnListaDoble(&lista,vec+i,sizeof(*vec));
    recorrerListaDoble(&lista,mostrarProd);
    vaciarLista(&lista);


    printf("\nInsertar en Lista Ordenada: \n");
    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
        insertarOrdenadoEnLista(&lista,vec+i,sizeof(*vec),compararProd,1);
    recorrerListaDoble(&lista,mostrarProd);
//    vaciarLista(&lista);

    t_prod clave={20};

    printf("\nClave Buscada: %i",clave.codProd);
    printf("\nClave Encontrada: \n\t");
    if(!buscarPorClaveEnListaOrdenada(&lista,&clave,sizeof(clave),compararProd))
        printf("No se encontro clave!");
    else
        mostrarProd(&clave);



    return 0;
}
