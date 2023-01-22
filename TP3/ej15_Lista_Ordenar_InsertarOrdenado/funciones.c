#include "funciones.h"


int crearLoteDePrueba(const void*archLote)
{
    FILE*pf;
    t_producto productos[]=
    {
        {101,10},
        {104,25},
        {103,50},
        {106,30},
        {105,5},
        {102,15},
    };

    pf=fopen(archLote,"wb");
    if(!pf)
        return 0;

    fwrite(productos,sizeof(productos),1,pf);

    fclose(pf);
    return 1;
}

int crearDatos1(const void*lote,const void *nomArch1)
{
    FILE*pf_lote,*pf_arch;
    t_lista lista;
    t_producto prod;

    crearLista(&lista);

    if(!(pf_lote=fopen(lote,"rb")))
        return 0;
    if(!(pf_arch=fopen(nomArch1,"wb")))
        return 0;

    fread(&prod,sizeof(t_producto),1,pf_lote);
    while(!feof(pf_lote))
    {
        insertarEnOrden(&lista,&prod,sizeof(prod),compararProductos,0);
        fread(&prod,sizeof(t_producto),1,pf_lote);
    }

    while(!listaVacia(&lista))
    {
        sacarPrimerElemento(&lista,&prod,sizeof(prod));
        fwrite(&prod,sizeof(prod),1,pf_arch);
    }
    fclose(pf_arch);
    fclose(pf_lote);

    return 1;

}

int crearDatos2(const void*lote,const void *nomArch2)
{
    FILE*pf_lote,*pf_arch;
    t_producto prod;
    t_lista lista;

    crearLista(&lista);

    if(!(pf_lote=fopen(lote,"rb")))
        return 0;
    if(!(pf_arch=fopen(nomArch2,"wb")))
        return 0;

    fread(&prod,sizeof(prod),1,pf_lote);
    while(!feof(pf_lote))
    {
        insertarPrimeroEnLista(&lista,&prod,sizeof(prod));
        fread(&prod,sizeof(prod),1,pf_lote);
    }

    ordenarLista(&lista,compararProductos);

    while(!listaVacia(&lista))
    {
        sacarPrimerElemento(&lista,&prod,sizeof(prod));
        fwrite(&prod,sizeof(prod),1,pf_arch);
    }


    fclose(pf_arch);
    fclose(pf_lote);

    return 1;
}


int compararProductos(const void*prod1,const void*prod2)
{
    t_producto*p1,*p2;
    int cmp;
    p1=(t_producto*)prod1;
    p2=(t_producto*)prod2;

    cmp=p1->codProd-p2->codProd;
    if(!cmp)
        cmp=p1->cantProd-p2->cantProd;

    return cmp;
}

int mostrarArchProd(const void*nomArch)
{
    FILE*pf;
    t_producto prod;
    if(!(pf=fopen(nomArch,"rb")))
        return 0;
    fread(&prod,sizeof(prod),1,pf);
    while(!feof(pf))
    {
        printf("\tcod: %i\tcant: %i\n",prod.codProd,prod.cantProd);
        fread(&prod,sizeof(prod),1,pf);
    }
    fclose(pf);
    return 1;
}
