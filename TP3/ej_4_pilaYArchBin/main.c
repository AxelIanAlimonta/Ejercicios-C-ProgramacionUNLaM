#include "funciones.h"

int main()
{
    t_pila pila;
    t_alum alum;
    int opc;
    FILE*pf;

    if(!crearLoteDePrueba())
        return 101;

    crearPila(&pila);

    if(!cargarLoteEnPila(&pila))
        return 102;

    opc=desplegarMenu();
    while(opc)
    {
        ejecutarOpcion(opc,&pila);
        opc=desplegarMenu();
    }


    if(!(pf=fopen(NOM_ARCH_FINAL,"wb")))
        return 103;

    while(desapilar(&pila,&alum,sizeof(t_alum)))
    {
        fwrite(&alum,sizeof(t_alum),1,pf);
    }
    fclose(pf);

    pf=fopen(NOM_ARCH_FINAL,"rb");
    if(!pf)
        return 104;

    fread(&alum,sizeof(t_alum),1,pf);
    if(feof(pf))
    {
        fclose(pf);
        unlink(NOM_ARCH_FINAL);
    }
    else while(!feof(pf))
        {
            mostrarAlum(&alum);
            fread(&alum,sizeof(t_alum),1,pf);
        }


    return 0;
}
