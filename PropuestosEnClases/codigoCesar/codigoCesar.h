#ifndef CODIGOCESAR_H_INCLUDED
#define CODIGOCESAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ES_MAYUSCULA(x) ((x)>='A'&&(x)<='Z')
#define ES_MINUSCULA(x) ((x)>='a'&&(x)<='z')
#define ES_LETRA(x) (ES_MAYUSCULA(x)||ES_MINUSCULA(x))
#define DESPLAZAMIENTO 1

char* codificarCesar(char*cad);
char* decodificarCesar(char*cad);



#endif // CODIGOCESAR_H_INCLUDED
