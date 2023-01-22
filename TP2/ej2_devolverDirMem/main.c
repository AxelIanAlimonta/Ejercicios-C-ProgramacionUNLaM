#include <stdio.h>
#include <stdlib.h>

int* dirMemDeElem(int*vec,int cantElem,int elem);

int main()
{
    int vec[]={1,2,3,4,5,6};
    int nro=1;
    printf("%p %p",vec,dirMemDeElem(vec,sizeof(vec)/sizeof(*vec),nro));
    return 0;
}

int* dirMemDeElem(int*vec,int cantElem,int elem)
{
    int i;
    for(i=0;i<cantElem;i++)
    {
        if(*vec==elem)
            return vec;
        vec++;
    }
    return NULL;
}
