#include "mi_atoi.h"

int main()
{
    char cad1[]="123";
    char cad2[]="+123";
    char cad3[]="-123";
    char cad4[]="+-123";
    char cad5[]="  123";
    char cad6[]="a123";
    char cad7[]="12-3";
    char cad8[]="12a3";

    printf("atoi: \n");
    printf("cad1: %s    atoi: %i \n",cad1,atoi(cad1));
    printf("cad2: %s    atoi: %i \n",cad2,atoi(cad2));
    printf("cad3: %s    atoi: %i \n",cad3,atoi(cad3));
    printf("cad4: %s    atoi: %i \n",cad4,atoi(cad4));
    printf("cad5: %s    atoi: %i \n",cad5,atoi(cad5));
    printf("cad6: %s    atoi: %i \n",cad6,atoi(cad6));
    printf("cad7: %s    atoi: %i \n",cad7,atoi(cad7));
    printf("cad8: %s    atoi: %i \n",cad8,atoi(cad8));

    printf("mi_atoi: \n");
    printf("cad1: %s    mi_atoi: %i \n",cad1,mi_atoi(cad1));
    printf("cad2: %s    mi_atoi: %i \n",cad2,mi_atoi(cad2));
    printf("cad3: %s    mi_atoi: %i \n",cad3,mi_atoi(cad3));
    printf("cad4: %s    mi_atoi: %i \n",cad4,mi_atoi(cad4));
    printf("cad5: %s    mi_atoi: %i \n",cad5,mi_atoi(cad5));
    printf("cad6: %s    mi_atoi: %i \n",cad6,mi_atoi(cad6));
    printf("cad7: %s    mi_atoi: %i \n",cad7,mi_atoi(cad7));
    printf("cad8: %s    mi_atoi: %i \n",cad8,mi_atoi(cad8));


    return 0;
}
