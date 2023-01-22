#include "funciones.h"

int crearLoteDePrueba()
{
    FILE*pf;
    t_alum alumnos[]=
    {
        {37864001,"Pia, Maria",10},
        {37864002,"Lopez, Lucas",7},
        {37864003,"Perez, Juan",4},
        {37864004,"Gutierrez, Carla",2},
        {37864005,"Aguirre, Laura",1},
        {37864006,"Alvarez, Pedro",9},
    };

    pf=fopen(NOM_ARCH,"wb");
    if(!pf)
    {
        printf("\nNo se pudo crear lote de prueba");
        return 0;
    }
    fwrite(alumnos,sizeof(alumnos),1,pf);
    fclose(pf);
    return 1;
}

int cargarLoteEnPila(t_pila*pila)
{
    t_alum alumno;
    FILE*pf=fopen(NOM_ARCH,"rb");
    if(!pf)
    {
        printf("No se pudo abrir archivo para cargar pila");
        return 0;
    }


    fread(&alumno,sizeof(t_alum),1,pf);
    while(!feof(pf))
    {
        apilar(pila,&alumno,sizeof(t_alum));
        fread(&alumno,sizeof(t_alum),1,pf);
    }
    fclose(pf);
    return 1;
}

int desplegarMenu()
{
    int opc;
    system("cls");
    printf("\n~~~~~  MENU  ~~~~~\n");
    printf("\n1- Cargar otro alumno");
    printf("\n2- Ver Ultimo alumno cargado");
    printf("\n3- Sacar ultimo alumno cargado");
    printf("\n0- Salir");
    printf("\nIngrese opcion: ");

    scanf("%i",&opc);
    return opc;
}

void ejecutarOpcion(int opc,t_pila*pila)
{
    switch(opc)
    {
    case 1:
        cargarAlumnoNuevo(pila);
        break;
    case 2:
        verUltimoAlumno(pila);
        break;
    case 3:
        sacarUltimoAlumno(pila);
        break;
    default:
        return;
    }
}

void cargarAlumnoNuevo(t_pila*pila)
{
    t_alum alum;
    system("cls");
    printf("\nIngrese nombre y apellido del alumno: ");
    fflush(stdin);
    fgets(alum.NyA,50,stdin);
    eliminarSaltoDeLinea(alum.NyA);
    printf("\nIngrese DNI de alumno: ");
    scanf("%u",&alum.dni);
    printf("\nIngrese nota final de alumno: ");
    scanf("%f",&alum.notaFinal);
    apilar(pila,&alum,sizeof(t_alum));
    printf("\nDatos ingresados exitosamente\n");
    system("pause");

}

void eliminarSaltoDeLinea(char*cad)
{
    while(*cad)
    {
        if(*cad=='\n')

            *cad='\0';
        cad++;
    }
}

void verUltimoAlumno(t_pila*pila)
{
    t_alum alum;
    if(verTopeDePila(pila,&alum,sizeof(t_alum)))
        mostrarAlum(&alum);
    else
        printf("\nNo hay alumnos cargados en la pila\n");
    system("pause");
}

void sacarUltimoAlumno(t_pila*pila)
{
    t_alum alum;
    if(desapilar(pila,&alum,sizeof(t_alum)))
        printf("\nUltimo alumno elimminado exitosamente\n");
    else printf("\n No hay alumnos para eliminar de la pila\n");
    system("pause");
}

void mostrarAlum(t_alum* alum)
{
    printf("\nDni: %i\tNyA: %-16s\t Nota: %.2f\t\n",alum->dni,alum->NyA,alum->notaFinal);
}
