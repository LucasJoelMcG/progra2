#include <stdlib.h>
#include <stdio.h>

int main () {
    FILE * arch;
    int * vec;
    int i=0,aux=-999;
    int * diract;
    arch=fopen("numeros.txt","rt");
    while (!feof(arch)) {
        diract=vec+i;
        fscanf(arch,"%d",&aux);
        diract=(int *) malloc (sizeof(int));
        *diract=aux;
        i++;
        printf("%p \n",diract);
    }
    fclose(arch);
    for (int j=0;j<i;j++){
        diract=vec+j;
        printf("%p \n",diract);
    }
    for (int j=0;j<i;j++)
        free(vec+j);
    return 0;
}
