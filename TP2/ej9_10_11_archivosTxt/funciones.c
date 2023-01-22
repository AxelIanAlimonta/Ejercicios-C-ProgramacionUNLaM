#include "funciones.h"
#include <string.h>
#define FIL 5
#define COL 7
#define ES_NUM(x) ((x)>='0'&&(x)<='9')

int crearLoteDePruebas(const char*nomArch)
{
    int i;
    short int vec1[]= {123,4234,6456,231};
    short int vec2[]= {4234,6456,231};
    short int vec3[]= {332};
    short int vec4[]= {123,4234,231};
    short int vec5[]= {654,4234,12355,6456,231,6453,8654};



    FILE*pf;
    if(!(pf=fopen(nomArch,"wt")))
        return 0;
    for(i=0; i<sizeof(vec1)/sizeof(*vec1); i++)
        fprintf(pf,"%i ",vec1[i]);
    fprintf(pf,"\n");

    for(i=0; i<sizeof(vec2)/sizeof(*vec1); i++)
        fprintf(pf,"%i ",vec2[i]);
    fprintf(pf,"\n");

    for(i=0; i<sizeof(vec3)/sizeof(*vec1); i++)
        fprintf(pf,"%i ",vec3[i]);
    fprintf(pf,"\n");

    for(i=0; i<sizeof(vec4)/sizeof(*vec1); i++)
        fprintf(pf,"%i ",vec4[i]);
    fprintf(pf,"\n");

    for(i=0; i<sizeof(vec5)/sizeof(*vec1); i++)
        fprintf(pf,"%i ",vec5[i]);
    fprintf(pf,"\n");

    fclose(pf);
    return 1;
}

int esCapicua(char*cad)
{
    if(!cad)
        return 0;
    char*finCad=cad;
    while(*finCad)
        finCad++;
    finCad--;
    while(cad<finCad&&*cad==*finCad)
    {
        cad++;
        finCad--;
    }
    return !(*cad-*finCad);
}

int esMultiploDe5(char*cad)
{
    if(!cad)
        return 0;
    while(*cad)
        cad++;
    return!((*(cad-1)-'0')%5);
}

int esMultiploDe6(char*cad)
{
    if(!cad)
        return 0;
    while(*cad)
        cad++;
    return!((*(cad-1)-'0')%6);
}

int esMultiploDe11(char*cad)
{
    if(!cad)
        return 0;
    while(*cad)
        cad++;
    return!((*(cad-1)-'0')%11);
}

int esMayorQue100(char*cad)
{
    int nro;
    sscanf(cad,"%i",&nro);
    return nro>100;
}

int esShortInt(char*cad)
{
    long nro;
    sscanf(cad,"%li",&nro);
    return (nro>=-32768&&nro<=32767);
}

int ejercicio11(const char*nomArch)
{
    char linea[100],nro[100];
    char*p_linea;
    int multDe5=0,multDe6=0,multDe11=0;

    FILE*pf,*mayoresQue100;
    if(!(pf=fopen(nomArch,"rt")))
        return 102;
    if(!(mayoresQue100=fopen("mayoresQue100.txt","wt")))
    {
        fclose(pf);
        return 103;
    }

    p_linea=fgets(linea,100,pf);
    while(p_linea)
    {
        while(proximoNumero(p_linea,nro))
        {
            if(esMultiploDe5(nro))
                multDe5++;
            if(esMultiploDe6(nro))
                multDe6++;
            if(esMultiploDe11(nro))
                multDe11++;
            if(esMayorQue100(nro))
                fprintf(mayoresQue100,"%s\n",nro);
            p_linea+=6;
        }
        p_linea=fgets(linea,100,pf);
    }
    printf("\nMultiplos de 5: %i",multDe5);
    printf("\nMultiplos de 6: %i",multDe6);
    printf("\nMultiplos de 11: %i",multDe11);
    fclose(pf);
    fclose(mayoresQue100);

    return 1;
}

int proximoNumero(const char*cad,char*nro)
{
    if(!cad||!*cad)
        return 0;
    while(!ES_NUM(*cad))
        cad++;
    while(ES_NUM(*cad))
    {
        *nro=*cad;
        nro++;
        cad++;

    }
    *nro='\0';
    return 1;
}
