#include <stdio.h>
#include <stdlib.h>

void insertarEnPos(int*vec,int tamVec,int elem,int pos);

int main()
{
    int i;
    int vec[]= {1,2,4,5,6,7};

    insertarEnPos(vec,sizeof(vec)/sizeof(vec[0]),3,3);
    for(i=0;i<sizeof(vec)/sizeof(vec[0]);i++)
        printf("%i ",vec[i]);

    return 0;
}

void insertarEnPos(int*vec,int tamVec,int elem,int pos)
{
    int controlOverflow=pos;
    int aux;
    if(pos>tamVec)
        return;
    vec+=pos-1;
    while(controlOverflow<=tamVec)
    {
        aux=*vec;
        *vec=elem;
        elem=aux;
        vec++;
        controlOverflow++;
    }
}
