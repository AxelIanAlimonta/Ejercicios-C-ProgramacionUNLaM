#include "funciones.h"

int crearLoteDePrueba(const char*lote)
{
    FILE*pf;
    t_prod productos[]=
    {
        {101,"Lavandina",10,70,{10,9,2022}},
        {101,"Lavandina",13,70,{10,9,2021}},
        {101,"Lavanda",10,70,{13,3,2022}},
        {104,"Limpia Vidrios",42,150,{3,3,2023}},
        {102,"Detergente",3,80,{11,11,2022}},
        {102,"Detergente",4,85,{10,11,2022}},
        {102,"Detergente",8,90,{9,11,2022}},
        {102,"Deter",8,80,{9,11,2022}},
        {103,"Shampoo",15,150,{12,12,2023}},
        {101,"Jabon Liquido",13,205,{25,9,2023}},
        {102,"Jabon en Polvo",12,75,{20,12,2023}},
        {101,"Lavandina",10,70,{10,9,2022}},
    };

    if(!(pf=fopen(lote,"wb")))
        return 0;
    fwrite(productos,sizeof(productos),1,pf);
    fclose(pf);
    return 1;
}

int cargarListaDesdeArchivo(t_lista*lista,const char*nomArch)
{
    FILE*pf;
    t_prod prod;

    if(!(pf=fopen(nomArch,"rb")))
        return 0;

    fread(&prod,sizeof(prod),1,pf);
    while(!feof(pf))
    {
        insertarAlFinalDeListaYAgrupar(lista,&prod,sizeof(prod),compararProductos,agruparProductos);
        fread(&prod,sizeof(prod),1,pf);
    }
    return 1;
}

int compararProductos(const void*prod1,const void*prod2)
{
    t_prod *p1,*p2;
    int cmp;
    p1=(t_prod*)prod1;
    p2=(t_prod*)prod2;

    cmp=p1->cod-p2->cod;
    if(!cmp)
        cmp=strcmp(p1->descripcion,p2->descripcion);
    return cmp;
}

void agruparProductos(void*inf,const void*dat)
{
    t_prod*info,*dato;
    info=(t_prod*)inf;
    dato=(t_prod*)dat;

    info->cantidad+=dato->cantidad;
    if((compararFechas(&dato->fechaVenc,&info->fechaVenc))<0)
    {
        info->fechaVenc=dato->fechaVenc;
    }
    if((info->precio-dato->precio)<0)
        info->precio=dato->precio;

}

int compararFechas(t_fecha*f1,t_fecha*f2)
{
    int cmp;
    cmp=f1->anio-f2->anio;
    if(!cmp)
    {
        cmp=f1->mes-f2->mes;
        if(!cmp)
            cmp=f1->dia-f2->dia;
    }
    return cmp;
}

int compararCodProd(const void*prod1,const void*prod2)
{
    t_prod*p1,*p2;
    p1=(t_prod*)prod1;
    p2=(t_prod*)prod2;

    return p1->cod-p2->cod;
}

void mostrarProd(void*prod)
{
    t_prod*p1=(t_prod*)prod;
    printf("%5i%15s%5i%7.2f%4i/%2i/%2i\n",p1->cod,p1->descripcion,p1->cantidad,p1->precio,p1->fechaVenc.dia,p1->fechaVenc.mes,p1->fechaVenc.anio);
}

void informarYGrabarErrores(void*dato,FILE*pf)
{
    mostrarProd(dato);
    fwrite(dato,sizeof(t_prod),1,pf);
}
