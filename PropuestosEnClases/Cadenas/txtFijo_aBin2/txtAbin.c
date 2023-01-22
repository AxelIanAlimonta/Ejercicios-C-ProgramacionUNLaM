#include "txtAbin.h"

int crearLoteDePrueba(const char*nom_arch)
{
    int i;
    FILE*pf;
    t_alum alumnos[]=
    {
        {10000001,"Alvarez","Juan Carlos",9.7},
        {10000002,"Domingues","Lucas Mario",3.7},
        {10000003,"Echeberria","Marcos",2},
        {10000004,"Fernandez","Esteban Quito",5.3},
        {10000005,"Gonzales","Cristian",9.7},
        {10000006,"Herrera","Pablo",7.1},
        {10000007,"Lopez","Matias Alberto",6}
    };
    if(!(pf=fopen(nom_arch,"wt")))
    {
        printf("\nNo se pudo crear lote de prueba");
        return 0;
    }

    for(i=0; i<(sizeof(alumnos)/sizeof(t_alum)); i++)
    {
        fprintf(pf,"%8u%30s%30s%5.2f\n",alumnos[i].dni,alumnos[i].apellido,alumnos[i].nombre,alumnos[i].nota);

    }
    fclose(pf);
    return 1;
}

int pasarDeTxtABin(const char*archTxt,const char*archBIn)
{
    FILE*pf_bin,*pf_txt;
    t_alum datoAlum;


    if(!(pf_bin=fopen(archBIn,"wb")))
    {
        printf("\nNo se pudo abrir archivo %s",archBIn);
        return 0;
    }
    if(!(pf_txt=fopen(archTxt,"rt")))
    {
        fclose(pf_bin);
        printf("\nNo se pudo abrir archivo %s",archTxt);
        return 0;
    }

    while(fscanf(pf_txt,"%8i%30s%30s%5f",&datoAlum.dni,datoAlum.apellido,datoAlum.nombre,&datoAlum.nota)!=EOF)
    {
        fwrite(&datoAlum,sizeof(t_alum),1,pf_bin);
    }

    fclose(pf_bin);
    fclose(pf_txt);

    return 1;
}

int mostrarAlumnosBin(const char*nomBin)
{
    FILE *pf;
    t_alum datoAlum;
    if(!(pf=fopen(nomBin,"rb")))
    {
        printf("\nNo se pudo abrir %s para lectura",nomBin);
    }

    fread(&datoAlum,sizeof(t_alum),1,pf);
    while(!feof(pf))
    {
        printf("%10i%15s%15s%5.2f\n",datoAlum.dni,datoAlum.apellido,datoAlum.nombre,datoAlum.nota);
        fread(&datoAlum,sizeof(t_alum),1,pf);

    }
    return 1;
}
