#include "codigoCesar.h"

int main()
{
    char cad[]="Hola Mundo! Todo Bien?? :D";
//    char cad2[]="xyz";
    printf("cad original: %s\n",cad);
    printf("cad codificada: %s\n",codificarCesar(cad));
    printf("cad decodificada: %s",decodificarCesar(cad));

    return 0;
}
