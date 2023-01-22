#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nros[100],subInd=0,i;
    char cad[]="1|321|6542|12|0|458|689|12|345|32000";
    char*p_cad=cad;


    do
    {
        sscanf(p_cad,"%i",&nros[subInd]);
        p_cad=strchr(p_cad,'|');
        subInd++;

    }while(p_cad++);

    printf("Cadena desglosada: ");
    for(i=0;i<subInd;i++)
    {
        printf("%i ",nros[i]);
    }


    return 0;
}
