#include "funciones.h"
#define TAM_VEC 100

int main()
{
    float vec[]={2,3,10,4,5,6,7};
    int cantElem=sizeof(vec)/sizeof(*vec);
    while(desplegarMenu(vec,cantElem));
    return 0;
}

