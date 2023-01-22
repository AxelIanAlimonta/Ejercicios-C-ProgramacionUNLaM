#include "funciones.h"
#include <string.h>

int crearLoteDePruebas(const char*nomArch)
{
    int i;
    FILE*pf;
    t_est estudiante[]=
    {
        {10000001,"Alvarez","Juan",10.0},
        {10000002,"Ceballos","Lucas",2.2},
        {10000003,"Dominmgues","Carlos",3.4},
        {10000004,"Echeverria","Maria",9.4},
        {10000005,"Fernandez","Juana",2.1},
        {10000006,"Gomez","Juan",1.2},
    };

    if(!(pf=fopen(nomArch,"wt")))
    {
        printf("No se pudo crear archivo %s",nomArch);
        return 0;
    }

    for(i=0; i<(sizeof(estudiante)/sizeof(t_est)); i++)
        fprintf(pf,"%8i%15s%15s%5.2f\n",estudiante[i].dni,estudiante[i].apellido,estudiante[i].nombre,estudiante[i].prom);

    fclose(pf);
    return 1;
}


int pasarTxtABin(const char*archTxt,const char*archBin)
{
    FILE*pf_txt,*pf_bin;
    char linea[100];
    t_est datosEst;
    if(!(pf_txt=fopen(archTxt,"rt")))
    {
        printf("No se pudo abrir %s en modo lectura",archTxt);
        return 0;
    }
    if(!(pf_bin=fopen(archBin,"wb")))
    {
        printf("No se pudo abrir %s en modo lectura",archBin);
        fclose(pf_txt);
        return 0;
    }

    while(fgets(linea,100,pf_txt))
    {
        desglosarLinea(linea,&datosEst);
        fwrite(&datosEst,sizeof(t_est),1,pf_bin);
    }
    fclose(pf_bin);
    fclose(pf_txt);

    return 1;
}


void desglosarLinea(char*linea,t_est*datosEst)
{
    sscanf(linea,"%i",&datosEst->dni);

    while(*linea)
        linea++;

    linea-=6;
    sscanf(linea,"%f",&(datosEst->prom));
    *linea='\0';

    linea-=15;
    strcpy(datosEst->nombre,linea);
    eliminarEspaciosIniciales(datosEst->nombre);
    *linea='\0';

    linea-=15;
    strcpy(datosEst->apellido,linea);
    eliminarEspaciosIniciales(datosEst->apellido);

}

void eliminarEspaciosIniciales(char*cad)
{
    char*iniCad=cad;
    while(*cad&&*cad==' ')
        cad++;
    if(*cad&&iniCad!=cad)
    {
        while(*cad)
        {
            *iniCad=*cad;
            cad++;
            iniCad++;
        }
        *iniCad='\0';
    }
}

int mostrarBin(const char*nomArch)
{
    FILE*pf;
    t_est datosEst;

    if(!(pf=fopen(nomArch,"rb")))
    {
        printf("No se pudo leer %s para lectura",nomArch);
        return 0;
    }

    fread(&datosEst,sizeof(t_est),1,pf);
    while(!feof(pf))
    {
        printf("%-9i%s, %s%6.2f\n",datosEst.dni,datosEst.apellido,datosEst.nombre,datosEst.prom);
        fread(&datosEst,sizeof(t_est),1,pf);
    }
    return 1;
}
