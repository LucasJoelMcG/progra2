#include <stdio.h>
#define N 10

float prom(float vec[N], int pos);

int main () {
    float vec[N]={10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0};
    printf("El promedio es: %2.3f",prom(vec,0));
    return 0;
}

float prom(float vec[N], int pos) {
    if (pos==N-1)
        return vec[pos]/10.0;
    else 
        return vec[pos]/10.0+prom(vec,pos+1);
}