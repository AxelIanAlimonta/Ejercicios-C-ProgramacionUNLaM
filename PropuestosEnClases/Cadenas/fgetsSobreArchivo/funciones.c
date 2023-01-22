#include "funciones.h"

int crearLoteDePrueba()
{
    int i;
    FILE*pf;
    t_persona personas[]=
    {
        {"Pepe a",10},
        {"Lucas s",11},
        {"Matias d",12},
        {"Carlos f",13},
    };
    if(!(pf=fopen("archivo.txt","wt")))
    {
        printf("No se pudo crear archivo Lote de prueba");
        return 0;
    }

    for(i=0; i<4; i++)
        fprintf(pf,"%15s%5i\n",personas[i].nombre,personas[i].edad);
    fclose(pf);
    return 1;

}

int pasarABin()
{
    t_persona datoPers;
    FILE*pf_txt,*pf_bin;
    pf_txt=fopen("archivo.txt","rt");
    pf_bin=fopen("archivo.bin","wb");

    while(fscanf(pf_txt,"%*s%i",(int)sizeof(char)*15,datoPers.nombre,&datoPers.edad)!=EOF)
    {
        fwrite(&datoPers,sizeof(t_persona),1,pf_bin);
    }
    fclose(pf_bin);
    return 1;
}


void mostrarBin()
{
    t_persona persona;
    FILE*pf;
    pf=fopen("archivo.bin","rb");
    fread(&persona,sizeof(t_persona),1,pf);
    while(!feof(pf))
    {
        printf("%12s%4i\n",persona.nombre,persona.edad);
        fread(&persona,sizeof(t_persona),1,pf);
    }

}
