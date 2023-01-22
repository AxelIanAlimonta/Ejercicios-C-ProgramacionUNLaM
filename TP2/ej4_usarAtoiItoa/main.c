#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[]="123546";
    char cad2[50];
    int nro;
    nro=atoi(cad);
    printf("nro: %i\n",nro);
    itoa(nro,cad2,10);
    printf("cad: %s",cad2);

    return 0;
}
