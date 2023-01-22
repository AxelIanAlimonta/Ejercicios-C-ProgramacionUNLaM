#include <stdio.h>
#include <stdlib.h>

int partEntDeNumReal(float nro);

int main()
{
    float nro=10.265;
    printf("%i",partEntDeNumReal(nro));
    return 0;
}

int partEntDeNumReal(float nro)
{
    return (int)nro;
}
