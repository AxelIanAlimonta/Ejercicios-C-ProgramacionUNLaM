#include "funciones.h"
#include <string.h>

int crearLoteDePrueba(const char*nomArch)
{
    int i;
    FILE*pf;
    t_estudiante estudiantes[]=
    {
        {1000001,"Alonso","Juan",10},
        {1000002,"Bemnitez","Juan Carlos",9.5},
        {1000003,"Dominguez","Alberto",8.3},
        {1000004,"Fernandez","Laura",7.1},
        {1000005,"Gutierrez","Maria Alicia",10},
        {1000006,"Herrera","Lucas",2.3},
    };

    if(!(pf=fopen(nomArch,"wt")))
    {
        printf("No se pudo abrir archivo %s para la escritura...",nomArch);
        return 0;
    }

    for(i=0; i<(sizeof(estudiantes)/sizeof(t_estudiante)); i++)
        fprintf(pf,"%i|%s|%s|%f\n",estudiantes[i].dni,estudiantes[i].apellido,estudiantes[i].nombre,estudiantes[i].promedio);

    fclose(pf);
    return 1;

}

int pasarDeTxtABin(const char*nomTxt,const char*nomBin)
{
    FILE*pf_bin,*pf_txt;
    t_estudiante datoEst;
    char linea[100];
    if(!(pf_txt=fopen(nomTxt,"rt")))
    {
        printf("No se pudo abrir el archivo %s para lectura...",nomTxt);
        return 0;
    }
    if(!(pf_bin=fopen(nomBin,"wb")))
    {
        fclose(pf_txt);
        printf("No se pudo abrir %s para escritura...",nomBin);
        return 0;
    }

    while(fgets(linea,100,pf_txt))
    {
        desglosarLinea(linea,&datoEst);
        fwrite(&datoEst,sizeof(t_estudiante),1,pf_bin);
    }
    fclose(pf_bin);
    fclose(pf_txt);


    return 1;

}

void desglosarLinea(char*cad,t_estudiante*datoEst)
{
    char*pipe;

    pipe=strrchr(cad,'|');
    sscanf(pipe+1,"%f",&datoEst->promedio);
    *pipe='\0';

    pipe=strrchr(cad,'|');
    strcpy(datoEst->nombre,pipe+1);
    *pipe='\0';

    pipe=strrchr(cad,'|');
    strcpy(datoEst->apellido,pipe+1);
    *pipe='\0';

    sscanf(cad,"%i",&datoEst->dni);

}

int mostrarBin(const char*nomBin)
{
    FILE*pf;
    t_estudiante datosEst;

    if(!(pf=fopen(nomBin,"rb")))
        return 0;

    fread(&datosEst,sizeof(t_estudiante),1,pf);
    while(!feof(pf))
    {
        printf("%-9i%s, %s %5.2f\n",datosEst.dni,datosEst.apellido,datosEst.nombre,datosEst.promedio);
        fread(&datosEst,sizeof(t_estudiante),1,pf);
    }
    fclose(pf);
    return 1;
}
