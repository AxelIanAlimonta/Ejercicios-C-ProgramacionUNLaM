#include "codigoCesar.h"

char* codificarCesar(char*cad)
{
    char* cadIni=cad;
    while(*cad)
    {
        if(ES_LETRA(*cad))
        {

            *cad+=DESPLAZAMIENTO;
            if(*cad>'Z'&&*cad<=('Z'+DESPLAZAMIENTO))
                *cad=('a'+(*cad)%'Z'-1);
            if(*cad>'z'&&*cad<=('z'+DESPLAZAMIENTO))
                *cad=('A'+(*cad)%'z'-1);
        }
        cad++;
    }
    return cadIni;
}

char* decodificarCesar(char*cad)
{
    char* cadIni=cad;
    while(*cad)
    {
        if(ES_LETRA(*cad))
        {

            *cad-=DESPLAZAMIENTO;
            if(*cad<'a'&&*cad>=('a'-DESPLAZAMIENTO))
                *cad=('Z'-(*cad)%'Z'-1);
            if(*cad<'A'&&*cad>=('A'-DESPLAZAMIENTO))
                *cad=('z'-(*cad)%'z'-1);
        }
        cad++;
    }
    return cadIni;
}
