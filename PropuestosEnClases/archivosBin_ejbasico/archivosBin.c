#include "archivosBin.h"

int grabarArchivo(const char*nomArch)
{
    char finDeIngreso='n';
    FILE*pf;
    t_alumno datosIngresados;

    if(!(pf=fopen(nomArch,"wb")))
    {
        printf("\nNo se pudo abrir el archivo!!");
        return 0;
    };

    do
    {
        ingresarDatos(&datosIngresados);
        fwrite(&datosIngresados,sizeof(datosIngresados),1,pf);
        printf("\nDesea ingresar otro alumno?(S/N): ");
        fflush(stdin);
        scanf("%c",&finDeIngreso);
    }
    while(finDeIngreso!='n'&&finDeIngreso!='N');



    fclose(pf);
    return 1;
}

void ingresarDatos(t_alumno*datosIngresados)
{
    printf("\nIngrese DNI: ");
    scanf("%u",&datosIngresados->dni);

    printf("\nIngrese nombre y apellido de alumno: ");
    fflush(stdin);
    fgets(datosIngresados->NyA,50,stdin);
    eliminarSaltoDeLinea(datosIngresados->NyA);

    printf("\nIngrese nota final: ");
    scanf("%f",&datosIngresados->notaFinal);
}

void eliminarSaltoDeLinea(char*linea)
{
    while(*linea)
    {
        if(*linea=='\n')
            *linea='\0';
        linea++;
    }
}


int leerArchivo(const char*nomArch)
{
    FILE*pf;
    t_alumno estrLect;
    if(!(pf=fopen(nomArch,"rb")))
    {
        printf("\nNo se pudo abrir archivo para lectura");
        return 0;
    }

    fread(&estrLect,sizeof(estrLect),1,pf);
    while(!feof(pf))
    {
        printf("DNI: %u\t NyA: %15s\t Nota: %.2f\t\n",estrLect.dni,estrLect.NyA,estrLect.notaFinal);
        fread(&estrLect,sizeof(estrLect),1,pf);

    }
    return 1;

}
seek
fseek()
