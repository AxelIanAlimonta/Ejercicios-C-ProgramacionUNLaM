#include "funciones.h"

void mostrarProd(void*prod)
{
    t_prod*p=(t_prod*)prod;
    printf("Cod: %i\tDesc: %-12s\tStock: %i\tPrecio: %.2f\n",p->codProd,p->descripcion,p->stock,p->precio);
}

int compararProd(const void*p1,const void*p2)
{
    return ((t_prod*)p1)->codProd-((t_prod*)p2)->codProd;
}


