#ifndef CONTAROCURRENCIAS_H_INCLUDED
#define CONTAROCURRENCIAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

unsigned contarOcurrenciasConSolapamiento(char*cad,char*subcad);
int coincidencia(char*cad,char*subcad);
unsigned contarOcurrenciasSinSolapamiento(char*cad,char*subcad);
char* coincidenciaConSolapamiento(char*cad,char*subcad,unsigned*contador);


#endif // CONTAROCURRENCIAS_H_INCLUDED
