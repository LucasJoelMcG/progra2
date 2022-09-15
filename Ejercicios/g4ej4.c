#include <stdlib.h>
#include <stdio.h>
#define N 4
#define M 5

int cont(float m[][M], int i, int j,float x);

int main () {
    float x;
    float m[N][M]= {{2,5,8,7,10},
                  {10,26,4,7,20},
                  {90,80,70,50,30},
                  {40,20,10,6,70}};
    printf("Ingrese el valor a buscar: ");
    scanf("%f",&x);
    printf("El valor aparece %d veces.",cont(m,N-1,M-1,x));
    return 0;
}

int cont(float m[][M], int i, int j,float x) {
    int aux;
    if (i>=0) 
        if (j==0) {
            aux=(m[i][j]==x)?1:0;
            return aux+cont(m,i-1,M-1,x);
        }
        else {
            aux=(m[i][j]==x)?1:0;
            return aux+cont(m,i,j-1,x);
        }
    else
        return 0;
}