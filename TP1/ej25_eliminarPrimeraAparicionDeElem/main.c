#include <stdio.h>
#include <stdlib.h>

void eliminarPrimAparicionDeELem(int*vec,int*cantElem,int elem);

int main()
{
    int i;
    int vec[]={1,2,3,4,5,6,7,8};
    int cantElem=sizeof(vec)/sizeof(*vec);
    eliminarPrimAparicionDeELem(vec,&cantElem,2);

    for(i=0;i<cantElem;i++)
        printf("%i ",vec[i]);

    return 0;
}

void eliminarPrimAparicionDeELem(int*vec,int*cantElem,int elem)
{
    int* controlOverflow=vec+(*cantElem);
    int*auxLect;
    while(vec<controlOverflow&&*vec!=elem)
        vec++;
    if(vec>=controlOverflow)
        return;
    auxLect=vec+1;
    while(auxLect<controlOverflow)
    {
        *vec=*auxLect;
        vec++;
        auxLect++;
    }
    (*cantElem)--;
}
