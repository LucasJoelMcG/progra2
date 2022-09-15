#include <stdlib.h>
#include <stdio.h>
#define N 10

int buscaD(int a[],int i, int x);
int buscaO(int b[],int inf,int sup, int x);

int main () {
    int a[N]={10,15,20,50,11,55,22,8,90,29};
    int b[N]={8,10,11,15,20,22,29,50,55,90};
    int x;
    printf("Ingrese el valor a buscar: ");
    scanf("%d",&x);
    printf("El valor se encuentra en la posicion: %d \n",buscaD(a,N-1,x));
    printf("El valor se encuentra en la posicion: %d",buscaO(b,0,N-1,x));
    return 0;
}

int buscaD(int a[],int i, int x){
    if (i==0)
        if (a[i]==x)
            return i;
        else 
            return -1;
    else
        if (a[i]==x)
            return i;
        else
            return buscaD(a,i-1,x);
}

int buscaO(int b[],int inf,int sup,int x) {
    int m=(inf+sup)/2;
    if (inf<=sup) 
        if (b[m]==x)
            return m;
        else
            if (x>b[m])
                return buscaO(b,m+1,sup,x);
            else
                return buscaO(b,inf,m,x);
    else
        return -1;
}