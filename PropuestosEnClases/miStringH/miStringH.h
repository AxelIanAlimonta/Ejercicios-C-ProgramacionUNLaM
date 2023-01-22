#ifndef MISTRINGH_H_INCLUDED
#define MISTRINGH_H_INCLUDED

char* miStrCat(char*cad1,char*cad2);
int miStrLen(char*cad1);
char* miStrChr(char*cad,int c);
char* miStrrchr(char*cad,int c);
int miStrcmp(char*cad1,char*cad2);
int miStrcmpi(char*cad1,char*cad2);
int miToupper(int c);
int miTolower(int c);
char* miStrstr(char*subcad,char*cad);
char* miStrupr(char*cad);
char* miStrlwr(char*cad);
int miAtoi(char*cad);


#endif // MISTRINGH_H_INCLUDED
