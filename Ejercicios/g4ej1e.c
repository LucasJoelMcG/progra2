#include <stdlib.h>
#include <stdio.h>
#define N 5
#define M 8

void mezcla(int a[],int b[],int c[],int i,int j,int * k);

int main () {
    int a[N]={2,4,6,9,10};
    int b[M]={1,3,5,7,11,15,20,21};
    int c[N+M];
    int k=N+M-1;
    mezcla(a,b,c,N-1,M-1,&k);
    for (int i=k+1;i<=N+M-2;i++) {
        printf ("%d ",c[i]);
    }
    return 0;
}

void mezcla(int a[],int b[],int c[],int i,int j,int * k) {
    if (i!=-1 && j!=-1){
        if (a[i]>b[j]){
            c[*k]=a[i];
            *k=*k-1;
            mezcla(a,b,c,i-1,j,k);
        }
        else
            if (b[j]>a[i]) {
                c[*k]=b[j];
                *k=*k-1;
                mezcla(a,b,c,i,j-1,k);
            }
            else {
                c[*k]=a[i];
                *k=*k-1;
                mezcla(a,b,c,i-1,j-1,k);
            }
    }
    else {
        if (j>-1) {
            c[*k]=b[j];
            *k=*k-1;
            mezcla(a,b,c,i,j-1,k);
        }
        else
            if (i>-1){
                c[*k]=a[i];
                *k=*k-1;
                mezcla(a,b,c,i-1,j,k);
            }
    }
}