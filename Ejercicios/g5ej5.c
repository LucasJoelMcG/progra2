#include <stdlib.h>
#include <stdio.h>
#include "colasC.h"
#include "pilasD.h"
#define cant 5

typedef struct nodo {
    TCola c;
    struct nodo * sig;
}nodo;
typedef struct nodo * TLista;

void carga(TLista * L);
void maximos(TLista L,TPila * p);
void mostrar(TPila p);

int main () {
    TLista L=NULL;
    TPila p;
    iniciaP(&p);
    carga(&L);
    maximos(L,&p);
    mostrar(p);
    return 0;
}

void carga(TLista * L) {
    TLista aux;
    TElementoC dato;
    for (int i=0;i<cant;i++) {
        aux=(TLista) malloc (sizeof(nodo));
        iniciaC(&aux->c);
        if (*L==NULL) {
            *L=aux;
            aux->sig=NULL;
        }
        else {
            aux->sig=*L;
            *L=aux;
        }
        printf("Ingresa datos de la cola %d.\n",i);
        scanf("%d",&dato);
        while (dato!=0) {
            poneC(&aux->c,dato);
            scanf("%d",&dato);
        }
    }
}

void maximos(TLista L, TPila * p) {
    TLista aux=L;
    TCola auxCola;
    int max;
    TElementoC valor;
    TElementoP valor2;
    iniciaC(&auxCola);
    while (aux!=NULL) {
        max=-9999;
        while (!vaciaC(aux->c)) {
            sacaC(&aux->c,&valor);
            if (valor>max)
                max=valor;
            poneC(&auxCola,valor);
        }
        while (!vaciaC(auxCola)){
            sacaC(&auxCola,&valor);
            poneC(&aux->c,valor);
        }
        valor2=max;
        poneP(p,valor2);
        aux=aux->sig;        
    }
}

void mostrar(TPila p) {
    TPila aux;
    TElementoP valor;
    iniciaP(&aux);
    while (!vaciaP(p)) {
        sacaP(&p,&valor);
        printf("%d ",valor);
        poneP(&aux,valor);
    }
    while (!vaciaP(aux)){
        sacaP(&aux,&valor);
        poneP(&p,valor);
    }
}