#include <stdlib.h>
#include <stdio.h>
#define N 4

int min(int m[][N], int i, int j);

int main () {
    int m[N][N]= {{2,5,8,7},
                  {10,26,4,7},
                  {90,80,70,50},
                  {40,20,10,6}};
    printf("El elemento minimo de la matriz es: %d",min(m,N-1,N-1));
    return 0;
}

int min(int m[][N], int i, int j) {
    int aux;
    if (i==0 && j==0)
        return m[i][j];
    else
        if (j==0)
            aux=min(m,i-1,N-1);
        else
            aux=min(m,i,j-1);
    if (aux>m[i][j]) 
        return m[i][j];
    else
        return aux;        
}