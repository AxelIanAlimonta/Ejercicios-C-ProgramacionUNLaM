#include "funciones.h"


int crearLoteDePruebas(const char*nomArch)
{
    int i;
    char matCad[][100]=
    {
        {"Los textos es un conjunto de signos y símbolos propios de un lenguaje propio\n"},
        {"--> Existen varios tipos de textos, así que aquí solo mencionaré los más importantes.\n"},
        {"¡¡¡Textos narrativos!!!!\n"},
        {"__Textos argumentativos: Los textos argumentativos son aquellos en los que el emisor...\n"},
        {"***~~~~~~**!!!$$$$$&&.\n"},
    };
    FILE*pf;
    if(!(pf=fopen(nomArch,"wt")))
        return 101;
    for(i=0; i<sizeof(matCad)/sizeof(matCad[0]); i++)
        fprintf(pf,"%s",matCad[i]);

    fclose(pf);
    return 1;
}

int escribirAlFinalDeArchivo(const char*nomArch)
{
    FILE*pf;
    char linea[100];
    char continuarCarga;
    if(!(pf=fopen(nomArch,"r+t")))
        return 101;
    while(fgets(linea,100,pf));

    printf("\nDesea agregar otra linea de texto? s/n: ");
    fflush(stdin);
    scanf("%c",&continuarCarga);
    while(continuarCarga=='s'||continuarCarga=='S')
    {
        printf("\nIngrese la linea aue desea agregar: ");
        fflush(stdin);
        fgets(linea,100,stdin);
        fprintf(pf,"%s",linea);
        printf("\nDesea agregar otra linea de texto? s/n: ");
        fflush(stdin);
        scanf("%c",&continuarCarga);
    }

    fclose(pf);
    return 1;
}

int buscarPalabraEInformar(const char*nomArch,const char*palabra)
{
    FILE*pf;
    char proxPalab[100];
    char linea[100];
    char*proxPalabIni;
    int contLinea=0,contPalab,posPalab;

    if(!(pf=fopen(nomArch,"rt")))
        return 102;
    while(fgets(linea,100,pf))
    {
        proxPalabIni=linea;
        contLinea++;
        contPalab=0;
        posPalab=1;
        printf("Linea %i: ",contLinea);
        while(proximaPalabra(proxPalabIni,proxPalab,&proxPalabIni))
        {
            if(!strcmp(palabra,proxPalab))
            {
                contPalab++;
                printf("pos:%i ",posPalab);
            }
            posPalab++;
        }
        printf(" Cantidad de apariciones: %i\n",contPalab);
    }
    fclose(pf);
    return 1;
}

int proximaPalabra(const char*cad,char*palabra,char**palabraFin)
{
    if(!cad)
        return 0;
    while(*cad&&!ES_LETRA(*cad))
        cad++;
    if(!*cad)
        return 0;
    while(ES_LETRA(*cad))
    {
        *palabra=*cad;
        palabra++;
        cad++;
    }
    *palabra='\0';
    *palabraFin=(char*)cad;
    return 1;
}

int informeEj16(const char* nomArch)
{
    FILE*pf;
    char palabra[100],linea[100];
    char*proxPalabIni;
    int contUnaLetra=0,contParLetras=0,contComienzaConN=0,contMasDe3Vocales=0,
        contComienzaConSubcad=0,contComienzaYTerminaConVocal=0,contEsPalindromo=0;
    if(!(pf=fopen(nomArch,"rt")))
        return 105;

    while(fgets(linea,100,pf))
    {
        proxPalabIni=linea;
        while(proximaPalabra(proxPalabIni,palabra,&proxPalabIni))
        {
            if(f_formadoPorUnaSolaLetra(palabra))
                contUnaLetra++;
            if(f_formadoPorCantidadParDeLetras(palabra))
                contParLetras++;
            if(f_comienzaConN(palabra))
                contComienzaConN++;
            if(f_comienzaConSubcad(palabra,"numP"))
                contComienzaConSubcad++;
            if(f_comienzaYTerminaConVocal(palabra))
                contComienzaYTerminaConVocal++;
            if(f_tieneMasDe3Vocales(palabra))
                contMasDe3Vocales++;
            if(f_esPalindromo(palabra))
                contEsPalindromo++;


        }
    }
    printf("\nUna sola letra: %i",contUnaLetra);
    printf("\nNumero par de letras: %i",contParLetras);
    printf("\nComienza con N: %i",contComienzaConN);
    printf("\nComienza con subcad: %i",contComienzaConSubcad);
    printf("\nComienza y termina con vocal: %i",contComienzaYTerminaConVocal);
    printf("\nTiene mas de 3 vocales: %i",contMasDe3Vocales);
    printf("\nEs palindromo: %i",contEsPalindromo);

return 1;
}
int f_formadoPorUnaSolaLetra(const char*cad)
{
    if(!cad)
        return 0;
    if(ES_LETRA(*cad)&&!*(cad+1))
        return 1;
    else return 0;
}
int f_formadoPorCantidadParDeLetras(const char*cad)
{
    int contLetras=0;
    while(cad&&ES_LETRA(*cad))
    {
        contLetras++;
        cad++;
    }
    return !(contLetras%2);
}

int f_comienzaConN(const char*cad)
{
    if(!cad)
        return 0;
    return (*cad=='n'||*cad=='N');
}

int f_comienzaConSubcad(const char*cad,const char*subCad)
{
    while(*cad&&*cad==*subCad)
    {
        cad++;
        subCad++;
    }
    if(!*subCad)
        return 1;
    else return 0;
}

int f_comienzaYTerminaConVocal(const char*cad)
{
    if(!cad)
        return 0;
    if(!ES_VOLCAL(*cad))
        return 0;
    while(*cad)
        cad++;
    if(!ES_VOLCAL(*(cad-1)))
        return 0;
    else return 1;
}

int f_tieneMasDe3Vocales(const char*cad)
{
    int contVocal=0;
    if(!cad)
        return 0;
    while(*cad)
    {
        if(ES_VOLCAL(*cad))
            contVocal++;
        cad++;
    }
    return contVocal>3;
}

int f_esPalindromo(const char*cad)
{
    char*iniCad=(char*)cad;
    while(*cad)
        cad++;
    cad--;
    while(iniCad<cad)
    {
        if(*cad!=*iniCad)
            return 0;
        cad--;
        iniCad++;
    }
    return 1;
}
