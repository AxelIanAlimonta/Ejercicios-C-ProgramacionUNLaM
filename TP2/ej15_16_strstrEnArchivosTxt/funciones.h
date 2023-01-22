#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ES_LETRA(x) (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))
#define ES_VOLCAL(x) ((x)=='a'||(x)=='A'||(x)=='e'||(x)=='E'||(x)=='i'||(x)=='I'||(x)=='o'||(x)=='O'||(x)=='u'||(x)=='U')
#define ES_NUMERO(x) ((x)>='0'&&(x)<='9')

int crearLoteDePruebas(const char*nomArch);
int escribirAlFinalDeArchivo(const char*nomArch);
int buscarPalabraEInformar(const char*nomArch,const char*palabra);
int proximaPalabra(const char*cad,char*palabra,char**palabraFin);
int informeEj16(const char* nomArch);
int f_formadoPorUnaSolaLetra(const char*cad);
int f_formadoPorCantidadParDeLetras(const char*cad);
int f_comienzaConN(const char*cad);
int f_comienzaConSubcad(const char*cad,const char*subCad);
int f_comienzaYTerminaConVocal(const char*cad);
int f_tieneMasDe3Vocales(const char*cad);
int f_esPalindromo(const char*cad);




#endif // FUNCIONES_H_INCLUDED
