#include <stdlib.h>
#include <stdio.h>
#define N 50

int main () {
    FILE * arch;
    int * vec[N];
    int i=0,aux=-999;
    arch=fopen("numeros.txt","rt");
    while (!feof(arch)) {
        fscanf(arch,"%d",&aux);
        vec[i]=(int *) malloc (sizeof(int));
        *vec[i]=aux;
        i++;
    }
    for (int j=0;j<i;j++)
        printf("%d \n",*vec[j]);
    fclose(arch);
    for (int j=0;j<i;j++)
        free(vec[j]);
    return 0;
}
