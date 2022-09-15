#include <stdio.h>
#define N 10

int maxi(int vec[], int pos);
void maxv (int vec[], int pos, int * max);

int main () {
    int vec[N]={20,30,40,25,60,45,67,38,9,10};
    int max=-9999;
    printf("El máximo por int es: %d \n",maxi(vec,0));
    maxv(vec,0,&max);
    printf("El maximo por void es: %d",max);
}

int maxi(int vec[], int pos) {
    int max;
    if (pos==N-1)
        return vec[pos];
    else {
        max=maxi(vec,pos+1);
        if (max>vec[pos])
            return max;
        else 
            return vec[pos];
    }
}
void maxv (int vec[],int pos, int * max) {
    if (pos==N-1)
        *max=vec[pos];
    else {
        maxv(vec,pos+1,max);
        if (vec[pos]>*max)
            *max=vec[pos];
    }
}