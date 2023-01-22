#include <stdio.h>
#include <stdlib.h>

int insertarEnVecOrdenado(int*vec,int tamVec,int elem);

int main()
{
    int i;
    int vec[]= {1,3};
    insertarEnVecOrdenado(vec,sizeof(vec)/sizeof(vec[0]),2);

    for(i=0; i<sizeof(vec)/sizeof(vec[0]); i++)
        printf("%i ",vec[i]);

    return 0;
}

int insertarEnVecOrdenado(int*vec,int tamVec,int elem)
{
    int controlOverflow=1,aux;
    while(*vec<elem&&controlOverflow<=tamVec)
    {
        vec++;
        controlOverflow++;
    }
    if(controlOverflow>tamVec)
        return 0;
    else
    {
        while(controlOverflow<=tamVec)
        {
            aux=*vec;
            *vec=elem;
            elem=aux;
            controlOverflow++;
            vec++;
        }
        return 1;
    }
}
