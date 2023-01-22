#include <stdio.h>
#include <stdlib.h>

void cocienteYResto(int nro1,int nro2,int* cociente,int* resto);

int main()
{
    int n1=30,n2=4,cociente,resto;

    cocienteYResto(n1,n2,&cociente,&resto);

    printf("%i / %i -> cociente: %i\t resto: %i",n1,n2,cociente,resto);
    return 0;
}

void cocienteYResto(int nro1,int nro2,int* cociente,int* resto)
{
    *cociente=nro1/nro2;
    *resto=nro1%nro2;
}
