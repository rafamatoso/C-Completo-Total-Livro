#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "string.h"

void check(char *a, char *b, int (*cmp) (const char *, const char*));

int numcmp(const char *a, const char *b);

void main(void) {

    char s1[80], s2[80];

    printf(\n"1) Digite um nome: ");
    gets(s1);
    printf(\n"2) Digite um nome: ");
    gets(s2);

    if(isalpha(*s1)) check(s1, s2, strcmp);
    else check(s1, s2, numcmp);
}

void check(char *a, char *b, int (*cmp) (const char *, const char*)) {

    printf("Testando Igualdade: ");
    if(!(*cmp) (a, b)) printf("Igual\n");
    else printf("Diferente\n");
}

numcmp(const char *a, const char *b) {
    
    if(atoi(a) == atoi(b)) return 0; // funcao atoi converte uma string num inteiro
    else return 1;
}