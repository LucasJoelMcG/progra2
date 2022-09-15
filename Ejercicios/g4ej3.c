#include <stdlib.h>
#include <stdio.h>
#define n 10

float prom(float vec[],int i);

int main () {
    float vec[n]={20,10,5,6,7,4,3,7,5,8};
    printf("El promedio es: %10.5f",prom(vec,n-1));
    return 0;
}

float prom(float vec[],int i) {
    float aux=vec[i]/n;
    if (i==0)
        return aux;
    else
        return aux + prom(vec,i-1);
}