#include <stdio.h>
#include <stdlib.h>

void eliminarTodasLasApariciDeUnElem(int*vec,int*cantElem,int elem);

int main()
{
    int vec[]={1,2,2,2,3,4,5,6},i;
    int cantElem=sizeof(vec)/sizeof(*vec);
    eliminarTodasLasApariciDeUnElem(vec,&cantElem,2);

    for(i=0;i<cantElem;i++)
    {
        printf("%i ",vec[i]);
    }

    return 0;
}

void eliminarTodasLasApariciDeUnElem(int*vec,int*cantElem,int elem)
{
    int* controlOverflow=vec+*cantElem;
    int*puntRempl;
    while(vec<controlOverflow&&*vec!=elem)
        vec++;
    if(vec>=controlOverflow)
        return;

    puntRempl=vec+1;
    (*cantElem)--;

    while(puntRempl<controlOverflow)
    {
        if(*puntRempl!=elem)
        {
            *vec=*puntRempl;
            vec++;
            puntRempl++;
        }
        else
        {
            puntRempl++;
            (*cantElem)--;
        }

    }

}
