#include <stdio.h>
#include <stdlib.h>

void crea(int * a);

int main () {
    int *a,*b,*c;
    crea(a);
    crea(b);
    crea(c);
    printf("La suma es %d ",*a);
    return 0;
}

void crea (int *a) {
        printf("Ingrese el valor de la variable: ");
        a=malloc(sizeof(int));
        scanf("%d",a);
        printf("%d \n",*a);
}
