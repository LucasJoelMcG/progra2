#include <stdio.h>
#include <stdlib.h>

int main () {
    int * vec, n;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d",&n);
    vec=(int * ) malloc (n*sizeof(int));
    for (int i=0;i<n;i++) {
        printf("Ingrese el valor para el elemento %d: ",i);
        scanf("%d",(vec+i));
    }
    for (int i=0;i<n;i++)
        if (*(vec+i)>=0)
            printf("El valor en la posicion %d es %d.\n",i,*(vec+i));
    return 0;
}
