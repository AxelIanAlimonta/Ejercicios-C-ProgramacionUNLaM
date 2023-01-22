#include "funciones.h"
#define NOM_ARCH_LOTE "lote.bin"

int main()
{
    ///Ejercicio a
    t_lista lista;
    FILE*pf_err;
    pf_err=fopen("errores","wb");
    if(!pf_err)
        return 200;

    crearLista(&lista);
    if(!crearLoteDePrueba(NOM_ARCH_LOTE))
        return 101;
    cargarListaDesdeArchivo(&lista,NOM_ARCH_LOTE);
    printf("Lista con errores: \n");
    recorrerLista(&lista,mostrarProd);

    printf("\nErrores: \n");
    eliminarDuplicadosDeListaYGrabarEnArch(&lista,compararCodProd,pf_err,informarYGrabarErrores);
    printf("\nLista sin errores: \n");
    recorrerLista(&lista,mostrarProd);

    printf("\nLista Ordenada: \n");
    ordenarLista(&lista,compararCodProd);
    recorrerLista(&lista,mostrarProd);


    fclose(pf_err);
    return 0;
}
