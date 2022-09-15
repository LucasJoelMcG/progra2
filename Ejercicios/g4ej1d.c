#include <stdlib.h>
#include <stdio.h>
#define N 4
#define M 5
void maximos(int m[][M], int i, int j,int max);

int main () {
    int m[N][M]= {{2,5,8,7,10},
                  {10,26,4,7,20},
                  {90,80,70,50,30},
                  {40,20,10,6,70}};
    maximos(m,N-1,M-1,-9999);
    return 0;
}

void maximos(int m[][M], int i, int j,int max){
    if (i>=0)
        if (j==-1) {
            maximos(m,i-1,M-1,-9999);
            printf("El maximo de la fila %d es %d. \n",i,max);
        }
        else 
            if (max<m[i][j])
                maximos(m,i,j-1,m[i][j]);
            else
                maximos(m,i,j-1,max);
}           