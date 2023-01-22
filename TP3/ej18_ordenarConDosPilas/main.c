#include "funciones.h"
#include "Pila.h"
#define NOM_ARCH "archivo.bin"

int main()
{
    t_pila pila1,pila2;
    int num;
    FILE*pf;
    crearPila(&pila1);
    crearPila(&pila2);

    if(!crearLoteDePruebas(NOM_ARCH))
    {
        printf("Fallo creacion de lote de pruebas");
        return 101;
    }

    pf=fopen(NOM_ARCH,"rb");

    fread(&num,sizeof(num),1,pf);
    while(!feof(pf))
    {
        apilarDato(num,&pila1,&pila2);
        fread(&num,sizeof(num),1,pf);
    }

    juntarPilasMenorAMayor(&pila1,&pila2);

    printf("pila menor a mayor: ");
    while(!pilaVacia(&pila1))
    {
        desapilar(&pila1,&num,sizeof(num));
        printf("%i ",num);
    }

    return 0;
}
