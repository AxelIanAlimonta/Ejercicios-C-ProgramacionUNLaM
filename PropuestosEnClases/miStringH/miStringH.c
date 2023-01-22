#include <stdio.h>
#include <stdlib.h>
#include "miStringH.h"

char* miStrCat(char*cad1,char*cad2)
{
    char*cadIni=cad1;
    while(*cad1)
        cad1++;
    while(*cad2)
    {
        *cad1=*cad2;
        cad1++;
        cad2++;
    }
    *cad1='\0';
    return cadIni;
}

int miStrLen(char*cad1)
{
    int cont;
    while(*cad1)
    {
        cont++;
        cad1++;
    }
    return cont;
}

char* miStrChr(char*cad,int c)
{
    while(*cad&&*cad!=c)
        cad++;
    if(*cad==c)
        return cad;
    return NULL;
}

char* miStrrchr(char*cad,int c)
{
    char*cadIni=cad;
    while(*cad)
        cad++;
    cad--;
    while(cad>=cadIni)
    {
        if(*cad==c)
            return cad;
        cad--;
    }
    return NULL;
}

int miStrcmp(char*cad1,char*cad2)
{
    while(*cad1&&*cad1==*cad2)
    {
        cad1++;
        cad2++;
    }
    return *cad1-*cad2;

}

int miStrcmpi(char*cad1,char*cad2)
{
    while(*cad1&&miTolower(*cad1)==miTolower(*cad2))
    {
        cad1++;
        cad2++;
    }
    return miTolower(*cad1)-miTolower(*cad2);
}

int miToupper(int c)
{
    if(c>='a'&&c<='z')
        return c-('a'-'A');
    else return c;
}

int miTolower(int c)
{
    if(c>='A'&&c<='Z')
        return c+('a'-'A');
    else return c;
}

char* miStrstr(char*subcad,char*cad)
{
    char*posSubcad;
    char*iniSubcad=subcad;
    while(*cad)
    {
        if(*cad==*subcad)
        {
            posSubcad=cad;
            while(*subcad&&*cad==*subcad)
            {
                cad++;
                subcad++;
            }
            if(!*subcad)
                return posSubcad;
            else
                subcad=iniSubcad;
        }
        cad++;
    }
    return NULL;
}

char* miStrupr(char*cad)
{
    char*cadIni=cad;
    while(*cad)
    {
        *cad=miToupper(*cad);
        cad++;
    }
    return cadIni;
}

char* miStrlwr(char*cad)
{
    char*cadIni=cad;
    while(*cad)
    {
        *cad=miTolower(*cad);
        cad++;
    }
    return cadIni;
}

int miAtoi(char*cad)
{
    while(*cad)
    {
        nro*=10;
        nro+=*cad-'0';
        cad++;
    }
    return nro;
}
