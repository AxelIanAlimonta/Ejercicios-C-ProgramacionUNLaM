#include <stdio.h>
#include <stdlib.h>
#include "mi_atof.h"

int main()
{
    char cad1[]="123.45";
    char cad2[]="  123.45";
    char cad3[]="+123.45";
    char cad4[]="-123.45";
    char cad5[]="+-123.45";
    char cad6[]="a123.45";
    char cad7[]=" a123.45";
    char cad8[]=" 123..45";
    char cad9[]=" a123";
    char cad10[]=" .123";

    printf("\natof: ");
    printf("\ncad1: %s  atof: %f",cad1,atof(cad1));
    printf("\ncad2: %s  atof: %f",cad2,atof(cad2));
    printf("\ncad3: %s  atof: %f",cad3,atof(cad3));
    printf("\ncad4: %s  atof: %f",cad4,atof(cad4));
    printf("\ncad5: %s  atof: %f",cad5,atof(cad5));
    printf("\ncad6: %s  atof: %f",cad6,atof(cad6));
    printf("\ncad7: %s  atof: %f",cad7,atof(cad7));
    printf("\ncad8: %s  atof: %f",cad8,atof(cad8));
    printf("\ncad9: %s  atof: %f",cad9,atof(cad9));
    printf("\ncad10: %s  atof: %f",cad10,atof(cad10));

    printf("\n\nmi_atof: ");
    printf("\ncad1: %s  mi_atof: %f",cad1,mi_atof(cad1));
    printf("\ncad2: %s  mi_atof: %f",cad2,mi_atof(cad2));
    printf("\ncad3: %s  mi_atof: %f",cad3,mi_atof(cad3));
    printf("\ncad4: %s  mi_atof: %f",cad4,mi_atof(cad4));
    printf("\ncad5: %s  mi_atof: %f",cad5,mi_atof(cad5));
    printf("\ncad6: %s  mi_atof: %f",cad6,mi_atof(cad6));
    printf("\ncad7: %s  mi_atof: %f",cad7,mi_atof(cad7));
    printf("\ncad8: %s  mi_atof: %f",cad8,mi_atof(cad8));
    printf("\ncad9: %s  mi_atof: %f",cad9,mi_atof(cad9));
    printf("\ncad10: %s  mi_atof: %f",cad10,mi_atof(cad10));




    return 0;
}
