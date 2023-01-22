#include <stdio.h>
#include <stdlib.h>

int miAtoi(char* cad);

int main()
{
    char cad[]="1234";
    printf("%i",miAtoi(cad));
    return 0;
}

int miAtoi(char* cad)
{
    int nro;
    sscanf(cad,"%i",&nro);
    return nro;
}
