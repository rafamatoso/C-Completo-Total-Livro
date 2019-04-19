#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int *tos, *p1, stack[SIZE];

void main()
{
    int value;

    tos = stack; // variavel tos contera o topo da pilha
    p1 = stack; // inicializa p1

    do {
        printf("Digite o valor: ");
        scanf("%d",&value);
        if(value != 0) push(value);
        else printf("Valor do topo é %d\n", pop());
    } while(value!=-1);
    printf("\n");
}

push(int i) 
{
    p1++;
    if(p1 == (tos + SIZE)) {
        printf("Estouro da Pilha");
        exit(1);
    }
    *p1 = i;
}

pop(void)
{
    if(p1==tos) {
        printf("Estouro da Pilha");
        exit(1);
    }
    p1--;
    return *(p1+1);
}