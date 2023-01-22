#include "funciones.h"
#define NOM_ARCH "archivo.bin"
#define NOM_ARCH_ORD "ordenado.bin"
#define NOM_ARCH_IDX "datos.idx"



int main()
{
//    int i;
//    int nivel,contNodos,altura;
//    int vec[]= {5,2,8,1,6,7,3,4};
//    int vec[]= {100,120,80,90,70,130,110};//ESCOMPLETO
//    int vec[]= {100,80,120,60,90,150,40};//AVL
//    int vec[]= {100,80,120,60,150,40};//NO ES NADA

//    int vec[]= {5};


//    crearArbol(&arbol);


//    printf("Arbol: \n");
//    mostrarArbol(&arbol,mostrarEnteroEnArbol);

//    printf("\nRecorrido inOrden: ");
//    recorrerInOrden(&arbol,mostrarEnteros);
//
//    printf("\nRecorrido preOrden: ");
//    recorrerPreOrden(&arbol,mostrarEnteros);
//
//    printf("\nRecorrido posOrder: ");
//    recorrerPosOrden(&arbol,mostrarEnteros);
//
//    printf("\nContar nodos: %i",contarNodosDeArbol(&arbol));
//    printf("\nContar Nodos hasta Nivel: %i",contarNodosHastaNivel(&arbol,0));
//    printf("\nContar hojas: %i",contarHojasDeArbol(&arbol));
//    printf("\nContar ramas: %i",contarRamasDeArbol(&arbol));
//
//    printf("\nEs AVL: %i",esAVL(&arbol));
//    printf("\nEs Completo: %i",esCompleto(&arbol));
//    printf("\nEs Completo Hasta Nivel: %i",esCompletoHastaNivel(&arbol,3));
//    printf("\nEs Balanceado: %i",esBalanceado(&arbol));

//    nivel=1;
//    altura=2;
//    printf("\nRecorrer hasta nivel %i: ",nivel);
//    contNodos=recorrerHastaNivel(&arbol,nivel,mostrarEnteros);
//    printf("  Cont Nodos: %i",contNodos);
//
//    printf("\nRecorrer Nivel %i: ",nivel);
//    contNodos=recorrerNivel(&arbol,nivel,mostrarEnteros);
//    printf("  Cont Nodos: %i",contNodos);
//
//    printf("\nRecorrer Altura %i: ",altura);
//    contNodos=recorrerAltura(&arbol,altura,mostrarEnteros);
//    printf("  Cont Nodos: %i",contNodos);
//
//    printf("\nRecorrer a partir de Nivel %i: ",nivel);
//    contNodos=recorrerAPartirDeNivel(&arbol,nivel,mostrarEnteros);
//    printf("  Cont Nodos: %i",contNodos);

//    printf("\nEliminar hojas: ");
//    contNodos=eliminarHojas(&arbol);
//    printf("\n  Cont hojas: %i\n",contNodos);
//    mostrarArbol(&arbol,mostrarEnteroEnArbol);
//
//    eliminarArbol(&arbol);
//    printf("\nEliminar arbol -> Arbol Vacio?: %s",arbolVacio(&arbol)?"si":"no");
//    mostrarArbol(&arbol,mostrarEnteroEnArbol);

/////////////////////// ESTRUCTURA T_PROD

//    int nivel;
//    t_arbol* datoRecuperado;
//    t_prod vec[]=
//    {
//        {100,68},
//        {120,40},
//        {80,68},
//        {90,50},
//        {70,83},
//        {130,96},
//        {110,44},
//        {60,33},
//    };
//    t_arbol arbol;
//    crearArbol(&arbol);
//    for(i=0; i<(sizeof(vec)/sizeof(*vec)); i++)
//        r_insertarEnArbol(&arbol,vec+i,sizeof(*vec),compararCodProd);
//    mostrarArbol(&arbol,mostrarProdEnArbol);
//
////    nivel=1;
////    podarANivel(&arbol,nivel);
////    printf("\nPodar a nivel %i: \n",nivel);
////    mostrarArbol(&arbol,mostrarProdEnArbol);
////
////    printf("\nRecorrer inOrden: ");
////    recorrerInOrden(&arbol,mostrarProd);
//
//    printf("\nClave mas grande: ");
//    datoRecuperado=buscarClaveMasGrande(&arbol);
//    mostrarRaiz(datoRecuperado,mostrarProd);
//
//    printf("\nClave mas chica: ");
//    datoRecuperado=buscarClaveMasChica(&arbol);
//    mostrarRaiz(datoRecuperado,mostrarProd);
//
//    t_prod clave= {120,0};
//    datoRecuperado=buscarClaveEnArbol(&arbol,&clave,compararCodProd);
//    printf("\nBuscar por clave en arbol: ");
//    if(datoRecuperado)
//        mostrarRaiz(datoRecuperado,mostrarProd);
//    else
//        printf("Clave no encontrada");
//
//    printf("\nArbol despues de eliminar Raiz: \n");
//    eliminarRaiz(datoRecuperado);
//    mostrarArbol(&arbol,mostrarProdEnArbol);

///////////////CLases

    t_arbol arbol,arbolBalanceado;
    FILE*pf,*pf_ordenado,*pf_idx;
    int cantElem;

    crearArbol(&arbol);
    crearArbol(&arbolBalanceado);
    crearLoteDePruebas(NOM_ARCH);

    pf=fopen(NOM_ARCH,"rb");
    if(!pf)
        return 101;

    generarArbolDesdeArchivo(&arbol,pf);

    pf_idx=fopen(NOM_ARCH_IDX,"wb");
    if(!pf_idx)
        return 104;

    guardarArbolEnArchivoPreOrden(&arbol,pf_idx,sizeof(t_idx));
    eliminarArbol(&arbol);


//    mostrarArbol(&arbol,mostrarIdxEnArbol);

    pf_ordenado=fopen(NOM_ARCH_ORD,"wb");
    if(!pf_ordenado)
        return 102;

    generarArchivoOrdenado(&arbol,pf,pf_ordenado,grabar);
    fclose(pf);
    fclose(pf_ordenado);

    pf_ordenado=fopen(NOM_ARCH_ORD,"rb");
    if(!pf_ordenado)
        return 103;


    fseek(pf_ordenado,0L,SEEK_END);

    cantElem=ftell(pf_ordenado)/sizeof(t_prod);
    cargarArbolDesdeArchivoOrdenado(&arbolBalanceado,pf_ordenado,0,cantElem,sizeof(t_prod));
    mostrarArbol(&arbolBalanceado,mostrarIdxEnArbol);


    return 0;
}

