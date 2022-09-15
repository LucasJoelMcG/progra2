#include <stdlib.h>
#include <stdio.h>
#define N 10

int suma(int vec[], int i);
void mostrar (int vec[],int i);
void mostrarI (int vec[], int i);

int main () {
    int vec[N]={23,12,10,2,3,4,5,6,7,8};
    int i=N-1;
    printf("La suma es: %d",suma(vec,i));
    printf("\n");
    mostrar(vec,i);
    printf("\n");
    mostrarI(vec,i);
    return 0;
}

int suma(int vec[],int i) {
    if (i==0) 
        return vec[i];
    else
        return vec[i]+suma(vec,i-1);    
}

void mostrar (int vec[],int i){
    if (i>0) {
        mostrar(vec,i-1);
        printf("%d ",vec[i]);
    }
    else
        printf("%d ",vec[i]);
}

void mostrarI (int vec[], int i){
    if (i==0)
        printf("%d ",vec[i]);
    else {
        printf("%d ",vec[i]);
        mostrarI(vec,i-1);
    }
}