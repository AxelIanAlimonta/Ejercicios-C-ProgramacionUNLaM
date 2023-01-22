#include "funciones.h"

int compararProd(const void*prod1,const void*prod2)
{
    t_prod*p1,*p2;
    int cmp;
    p1=(t_prod*)prod1;
    p2=(t_prod*)prod2;
    cmp=p1->cod-p2->cod;
    if(!cmp)
        cmp=p1->precio-p2->precio;
    return cmp;
}

void mostrarProd(void*prod)
{
    t_prod*p1=(t_prod*)prod;
    printf("cod:%i   precio:%.2f\n",p1->cod,p1->precio);
}

void recuperarProd(void*clave,const void*dato)
{
    ((t_prod*)clave)->precio=((t_prod*)dato)->precio;
}

int compararCodigos(const void*prod1,const void*prod2)
{
    return ((t_prod*)prod1)->cod-((t_prod*)prod2)->cod;
}

int mostrarCodClave(t_prod*clave)
{
    return clave->cod;
}
