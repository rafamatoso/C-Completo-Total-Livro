#include <stdio.h>

int main() {

    int x;
    int *p1, *p2;

    p1 = &x; // O oponteiro p1 receber o local de variável de x
    p2 = p1; // p2 passa a apontar para o mesmo local de variável de p1 e x

    printf("%p\n",p2); // imprime o local de variável de p2 = p1 = x

    return 0;
}