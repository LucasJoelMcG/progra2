#include <stdlib.h>
#include <stdio.h>
#define N 10

typedef struct nodo {
    int dato;
    struct nodo * sig;
}nodo;
typedef nodo * TLista;

void muestra(TLista L);
void inver(TLista * L, int vec[]);
void direc(TLista * L, int vec[]);
void orden(TLista * L, int vec[]);
void libera(TLista L);

int main () {
    int vec[N]={4,6,3,1,0,9,8,5,7,2};
    TLista L=NULL;
    inver(&L,vec);
    muestra(L);
    libera(L);
    L=NULL;
    direc(&L,vec);
    muestra(L);
    libera(L);
    L=NULL;
    orden(&L,vec);
    muestra(L);
    libera(L);
    L=NULL;
}

void muestra(TLista L) {
    TLista aux=L;
    printf("\n");
    while (aux!=NULL) {
        printf("%d ",aux->dato);
        aux=aux->sig;
    }
}

void inver(TLista * L, int vec[]) {
    TLista aux;
    for (int i=0;i<N;i++) {
        aux=(TLista) malloc (sizeof(nodo));
        aux->dato=vec[i];
        aux->sig=*L;
        *L=aux;
    }    
}

void direc(TLista * L, int vec[]) {
    TLista aux,aux2;
    aux=(TLista) malloc (sizeof(nodo));
    aux->sig=NULL;
    aux->dato=vec[0];
    *L=aux;
    for (int i=1;i<N;i++) {
        aux=*L;
        while (aux->sig!=NULL) 
            aux=aux->sig;
        aux2=(TLista) malloc (sizeof(nodo));
        aux2->sig=NULL;
        aux2->dato=vec[i];
        aux->sig=aux2;
    }  
}

void orden(TLista * L, int vec[]) {
    TLista aux,act,ant;
    for (int i=0;i<N;i++) {
        aux=(TLista) malloc (sizeof(nodo));
        aux->dato= vec[i];
        if (*L == NULL || vec[i] < (*L)->dato) {
            aux->sig = *L;
            *L = aux;
        }
        else{
            ant=NULL;
            act=*L;
            while (act != NULL && vec[i]>act->dato){
                ant=act;
                act=act->sig;
            }
            aux->sig=act;
            ant->sig=aux;
        }
    }
}

void libera(TLista L) {
   TLista tmp;
   while (L!=NULL) {
       tmp=L;
       L=L->sig;
       free(tmp);
    }
}