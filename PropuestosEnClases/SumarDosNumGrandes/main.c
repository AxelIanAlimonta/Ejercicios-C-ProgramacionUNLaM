#include "funciones.h"

int main()
{
    FILE* num1,*num2,*archResult;
    t_pila pila1,pila2,result;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&result);

    num1=fopen("num1.txt","rt");
    num2=fopen("num2.txt","rt");
    archResult=fopen("resultado.txt","wt");

    cargarPila(num1,&pila1);
    cargarPila(num2,&pila2);

    sumarPilas(&pila1,&pila2,&result);

    grabarArchivo(&result,archResult);



    fclose(num1);
    fclose(num2);
    fclose(archResult);




    return 0;
}
