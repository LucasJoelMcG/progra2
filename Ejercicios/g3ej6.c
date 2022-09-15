#include <stdio.h>
#define N 5
#define M 5

int det (int mat[N][M], int i, int j, int cond);
int main () {
    int mat[N][M]={{1,2,3,4,4},
                   {1,2,3,4,5},
                   {1,2,3,4,6},
                   {1,2,3,4,7},
                   {1,2,3,4,8}};
    if (det(mat,0,0,0))
        printf("La matriz cumple las condiciones.");
    else
        printf("La matriz no cumple las condiciones.");
    return 0;
}

int det (int mat[N][M], int i, int j, int cond) {
    int aux=0;
    if (i==0){
        if (j==M-1){
            if ((cond+mat[i][j])%2==0) {
                return det(mat,i+1,0,cond+mat[i][j]);
            }
            else{
                return 0;
            }
        }
        else {  
            return det(mat,i,j+1,cond+mat[i][j]);
        }
    }
    else {
        if (i<N-1){
            if (j==0) {
                aux=mat[i][j]+det(mat,i,j+1,cond);
                if (aux>cond) {
                    return det(mat,i+1,0,aux);
                }
                else{
                    return 0;
                }
            }
            else {
                if (j<M-1) {
                    return mat[i][j]+det(mat,i,j+1,cond);
                }
                else {
                    return mat[i][j];
                }
            }
        }
        else {
            if (j==0) {
                aux=mat[i][j]+det(mat,i,j+1,cond);
                if (aux>cond) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if (j<M-1){
                    return mat[i][j]+det(mat,i,j+1,cond);
                }
                else {
                    return mat[i][j];
                }
            }
        }
    }
}