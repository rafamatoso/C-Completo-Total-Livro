#include <stdio.h>
#include <string.h>

void check(char *a, char *b, int (*cmp) (const char *, const char *));

void main(void) {

    char s1[80], s2[80];
    int (*p)();

    p = strcmp;

    printf(\n"1) Digite um nome: ");
    gets(s1);
    printf("2) Digite um nome: ");
    gets(s2);

    check(s1, s2, p);
}

void check(char *a, char *b, int (*cmp) (const char *, const char *)) {

    printf("Testando igualdade\n");
    if(!(*cmp) (a, b)) printf("Igual");
    else printf("Diferente");
}

