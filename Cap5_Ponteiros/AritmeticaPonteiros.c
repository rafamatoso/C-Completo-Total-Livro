#include <stdio.h>
#include <stdlib.h>

int main() {

    int a[] = {1,2,3,4,5,6,7,8,9};
    
    int *p;

    p = a;

    for (int i = 0; i < 9; i++) {
        printf("%d ",(*(p+i)*2));
    }
    printf("\n");
    return 0;
}