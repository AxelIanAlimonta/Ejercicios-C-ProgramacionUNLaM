#include "funciones.h"
#include "Pila.h"
#define ARCH_NUM1 "num1.txt"
#define ARCH_NUM2 "num2.txt"
#define ARCH_SUMA "suma.txt"

int main()
{
    t_pila pila1,pila2,pilaSuma;
    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pilaSuma);


    if(!cargarPilaDesdeArchivo(&pila1,ARCH_NUM1))
        printf("no se pudo cargar pila1");
    if(!cargarPilaDesdeArchivo(&pila2,ARCH_NUM2))
        printf("no se pudo cargar pila2");

    sumarPilas(&pila1,&pila2,&pilaSuma);

    grabarArchivoDesdePila(&pilaSuma,ARCH_SUMA);

    return 0;
}
