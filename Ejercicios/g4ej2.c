#include <stdlib.h>
#include <stdio.h>
#define n 10

int prod(int x,int y);
void coc(int dividendo, int divisor, int cociente);
int max(int vec[],int i);

int main () {
    int vec[n]={10,20,5,15,25,60,30,35,90,9};
    int producto1,producto2,dividendo,divisor;
    printf("Ingrese dividendo, divisor, producto 1 y 2: ");
    scanf("%d %d %d %d",&dividendo,&divisor,&producto1,&producto2);
    printf("El producto de %d y %d es %d: \n",producto1,producto2,prod(producto1,producto2));
    coc(dividendo,divisor,0);
    printf("El maximo del vector es %d: ",max(vec,n-1));
    return 0;
}

int prod(int x,int y) {
    if (y==1)
        return x;
    else
        return x+prod(x,y-1);
}

void coc(int dividendo, int divisor, int cociente) {
    if (dividendo-divisor<divisor) 
        printf("El cociente es %d y el resto es %d.\n",cociente+1,dividendo-divisor);
    else
        coc(dividendo-divisor,divisor,cociente+1);
}

int max(int vec[],int i){
    int aux;
    if (i==0)
        return vec[i];
    else {
        aux=max(vec,i-1);
        if (aux>vec[i])
            return aux;
        else
            return vec[i];
    }
}