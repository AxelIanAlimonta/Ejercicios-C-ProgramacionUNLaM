#ifndef MI_ATOI_H_INCLUDED
#define MI_ATOI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ES_BLANCO(x) ((x)==' '||(x)=='\t'||(x)=='\r'||(x)=='\n')
#define ES_NUMERO(x) ((x)>='0'&&(x)<='9')

int mi_atoi(char*cad);



#endif // MI_ATOI_H_INCLUDED
