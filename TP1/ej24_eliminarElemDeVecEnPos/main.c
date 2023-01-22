#include <stdio.h>
#include <stdlib.h>

void eliminarDeVecEnPos(int*vec,int* cantElem,int pos);

int main()
{
    int i;
    int vec[]={1,2,3,4,5,6,7,8};
    int cantElem=sizeof(vec)/sizeof(*vec);
    eliminarDeVecEnPos(vec,&cantElem,2);

    for(i=0;i<cantElem;i++)
        printf("%i ",vec[i]);
    return 0;
}

void eliminarDeVecEnPos(int*vec,int* cantElem,int pos)
{
    int* controlOverflow=vec+*cantElem;
    int* auxLect;
    if(*cantElem<pos)
        return;
    vec+=pos-1;
    auxLect=vec+1;
    while(auxLect<controlOverflow)
    {
        *vec=*auxLect;
        vec++;
        auxLect++;
    }
    (*cantElem)--;
}
