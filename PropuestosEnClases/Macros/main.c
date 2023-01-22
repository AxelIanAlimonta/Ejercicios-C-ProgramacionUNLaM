#include <stdio.h>
#include <stdlib.h>

#define MI_ABS(x) (x)>(0)?(x):(-x)
#define ES_PAR(x) ((x)%2==0?1:0)
#define ES_NUMERO(x) (((x)>='0')&&((x)<='9'))
#define ES_MAYUSCULA(x) (((x)>='A'&&(x)<='Z'))
#define ES_MINUSCULA(x) (((x)>='a'&&(x)<='z'))
#define ES_LETRA(x) (ES_MINUSCULA(x)||ES_MAYUSCULA(x))
#define ES_BLANCO(x) (((x)==' '||(x)=='\n'||(x)==9))

int main()
{
////    float nro;
//    int nro;
//    printf("Ingrese un numero: ");
////    scanf("%f",&nro);
//    scanf("%i",&nro);
////    printf("\nValor absoluto: %f",MI_ABS(nro));
//    printf("\nEl numero %s par",ES_PAR(nro)?"es":"no es");

    char caracter;
    printf("Ingrese un caracter: ");
    scanf("%c",&caracter);
    printf("\nEl caracter '%c' %s letra",caracter,(ES_LETRA(caracter)?"es":"no es"));
    printf("\nEl caracter '%c' %s numero",caracter,(ES_NUMERO(caracter)?"es":"no es"));
    printf("\nEl caracter '%c' %s mayuscula",caracter,(ES_MAYUSCULA(caracter)?"es":"no es"));
    printf("\nEl caracter '%c' %s minuscula",caracter,(ES_MINUSCULA(caracter)?"es":"no es"));
    printf("\nEl caracter '%c' %s blanco",caracter,(ES_BLANCO(caracter)?"es":"no es"));




    return 0;
}
