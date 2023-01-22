#include "funciones.h"
#include <string.h>

int crearLoteDePrueba(const char*nomArchEst,const char*nomArchEmpl)
{
    FILE*pf_est,*pf_empl;


    t_estudiante estudiantes[]=
    {
        {{"Alonso","Matias",38000001},10},
        {{"Alonso","Matias",38000002},6},
        {{"Alonso","Juan carlos",38000003},3},
        {{"Lopez","Lucas",38000005},4},
        {{"Lopez","Mario",38000007},9},
        {{"Lopez","Matias",38000006},7},
        {{"Perez","Juan carlos",38000004},6},
    };

    t_empleado empleados[]=
    {
        {{"Alonso","Juan carlos",38000001},12000},
        {{"Alonso","Matias",38000001},10000},
        {{"Lopez","Mario",38000007},13000},
        {{"Lopez","Matias",38000006},13000},
        {{"Pia","Maria",38000010},10000},
    };


    if(!(pf_empl=fopen(nomArchEmpl,"wb")))
        return 101;
    if(!(pf_est=fopen(nomArchEst,"wb")))
    {
        fclose(pf_empl);
        return 102;
    }

    fwrite(estudiantes,sizeof(estudiantes),1,pf_est);
    fwrite(empleados,sizeof(empleados),1,pf_empl);

    fclose(pf_est);
    fclose(pf_empl);
    return 1;
}

int actualizarEmpleados(const char*nomArchEst,const char*nomArchEmpl)
{
    FILE*pf_empl,*pf_est;
    float aumento=1.0728;
    int cmp;
    t_empleado datosEmpl;
    t_estudiante datosEst;

    if(!(pf_empl=fopen(nomArchEmpl,"r+b")))
        return 103;
    if(!(pf_est=fopen(nomArchEst,"rb")))
    {
        fclose(pf_empl);
        return 104;
    }

    fread(&datosEst,sizeof(t_estudiante),1,pf_est);
    fread(&datosEmpl,sizeof(t_empleado),1,pf_empl);
    while(!feof(pf_est)&&!feof(pf_empl))
    {
        if(!(cmp=strcmp(datosEmpl.datos.apellido,datosEst.datos.apellido)))
        {
            if(!(cmp=strcmp(datosEmpl.datos.nombre,datosEst.datos.nombre)))
            {
                if(!(cmp=datosEst.datos.dni-datosEmpl.datos.dni))
                {
                    if(datosEst.promedio>=7)
                    {
                        datosEmpl.sueldo*=aumento;
                        fseek(pf_empl,(long int)-sizeof(t_empleado),SEEK_CUR);
                        fwrite(&datosEmpl,sizeof(t_empleado),1,pf_empl);
                        fseek(pf_empl,0L,SEEK_CUR);
                        fread(&datosEst,sizeof(t_estudiante),1,pf_est);
                        fread(&datosEmpl,sizeof(t_empleado),1,pf_empl);
                    }
                }
            }
        }
        if(cmp>0)
            fread(&datosEst,sizeof(t_estudiante),1,pf_est);
        if(cmp<0)
            fread(&datosEmpl,sizeof(t_empleado),1,pf_empl);
    }

    fclose(pf_empl);
    fclose(pf_est);
    return 1;
}

int mostrarArchivoEmpleados(const char*nomArch)
{
    FILE*pf;
    t_empleado datos;
    if(!(pf=fopen(nomArch,"rb")))
        return 106;
    fread(&datos,sizeof(t_empleado),1,pf);
    while(!feof(pf))
    {
        printf("%15s%15s%10i%10.2f\n",datos.datos.apellido,datos.datos.nombre,datos.datos.dni,datos.sueldo);
        fread(&datos,sizeof(t_empleado),1,pf);
    }
    return 1;
}
