#include "funciones.h"
//
//void mostrarEnteroEnArbol(const void*dato,int despl)
//{
//    printf("%*i\n",despl*6,*(int*)dato);
//}
//
//int compararEnteros(const void*nro1,const void*nro2)
//{
//    return *(int*)nro1-*(int*)nro2;
//}
//
//void mostrarEnteros(const void*nro)
//{
//    printf("%i ",*(int*)nro);
//}

void mostrarProdEnArbol(const void*dato,int despl)
{
    printf("%*i|%i\n",despl*6,((t_prod*)dato)->cod,((t_prod*)dato)->stock);
}

void mostrarProd(const void*prod)
{
    t_prod*p=(t_prod*)prod;
    printf("%i|%i ",p->cod,p->stock);
}

int compararCodProd(const void*prod1,const void*prod2)
{
    t_prod* p1=(t_prod*)prod1;
    t_prod* p2=(t_prod*)prod2;

    return p1->cod-p2->cod;
}

int  crearLoteDePruebas(const char*nombArch)
{
    FILE*pf;
    t_prod vec[]=
    {
        {100,66},
        {10,66},
        {40,65},
        {110,79},
        {50,76},
        {120,64},
        {60,57},
        {70,46},
        {160,66},
        {90,66},
        {170,66},
        {130,53},
        {200,66},
        {30,23},
        {20,12},
        {80,68},
        {180,35},
        {140,54},
        {150,42},
        {190,75},
    };
    if(!(pf=fopen(nombArch,"wb")))
        return 0;
    fwrite(vec,sizeof(vec),1,pf);
    fclose(pf);
    return 1;
}

int generarArbolDesdeArchivo(t_arbol*arbol,FILE*pf)
{
    int cont=0;
    t_prod prod;
    t_idx idx;
    fread(&prod,sizeof(t_prod),1,pf);
    while(!feof(pf))
    {
        idx.idx=cont;
        cont ++;
        idx.cod=prod.cod;
        insertarEnArbol(arbol,&idx,sizeof(idx),compararIdx);
        fread(&prod,sizeof(t_prod),1,pf);
    }

    return 1;
}

int compararIdx(const void*i1,const void*i2)
{
    return ((t_idx*)i1)->cod-((t_idx*)i2)->cod;
}

void mostrarIdxEnArbol(const void*dato,int despl)
{
    printf("%*i|%i\n",despl*4,((t_idx*)dato)->cod,((t_idx*)dato)->idx);
}


void grabar(FILE*orig,FILE*orden,const void*dato)
{
    t_prod prod;
    fseek(orig,((t_idx*)dato)->idx*sizeof(t_prod),SEEK_SET);
    fread(&prod,sizeof(t_prod),1,orig);
    fseek(orden,0L,SEEK_END);
    fwrite(&prod,sizeof(t_prod),1,orden);
}
