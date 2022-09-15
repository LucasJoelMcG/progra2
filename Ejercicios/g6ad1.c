#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int x;
    struct nodo * sig;
} nodo;
typedef struct nodo * TLista;

void cargaLista(TLista *L);
void cargaLista2(TLista *L);
int iguales(TLista L, TLista L2);
void agregar (TLista L1, TLista L2);
void eliminar (TLista * L1, TLista L2);
void mostrar(TLista L);

int main () {
    TLista L1=NULL,L2=NULL,L3=NULL;
    cargaLista(&L1);
    cargaLista2(&L2);
    cargaLista2(&L3);
    mostrar(L1);
    mostrar(L2);
    agregar(L1,L3);
    mostrar(L3);
    eliminar(&L1,L2);
    mostrar(L1);
    return 0;
}

void cargaLista2(TLista *L) {
    TLista aux,aux2;
    FILE * arch;
    arch=fopen("Programacion 2/g6ad1-2.txt","rt");
    aux=(TLista) malloc (sizeof(nodo));
    aux->sig=NULL;
    fscanf(arch,"%d",&aux->x);
    *L=aux;
    while (!feof(arch)) {
        aux=*L;
        while (aux->sig!=NULL) 
            aux=aux->sig;
        aux2=(TLista) malloc (sizeof(nodo));
        aux2->sig=NULL;
        fscanf(arch,"%d",&aux2->x);
        aux->sig=aux2;
    }  
}

void cargaLista(TLista *L) {
    TLista aux,aux2;
    FILE * arch;
    arch=fopen("Programacion 2/g6ad1.txt","rt");
    aux=(TLista) malloc (sizeof(nodo));
    aux->sig=NULL;
    fscanf(arch,"%d",&aux->x);
    *L=aux;
    while (!feof(arch)) {
        aux=*L;
        while (aux->sig!=NULL) 
            aux=aux->sig;
        aux2=(TLista) malloc (sizeof(nodo));
        aux2->sig=NULL;
        fscanf(arch,"%d",&aux2->x);
        aux->sig=aux2;
    }  
}

void agregar (TLista L1, TLista L2) {
    TLista aux1=L1, aux2=L2;
    while (aux1->sig!=NULL)
        aux1=aux1->sig;
    if (aux2->x>aux1->x) 
        aux1->sig=aux2;
    else {
        aux1=L1;
        while (aux2->sig!=NULL)
            aux2=aux2->sig;
        aux2->sig=aux1;
    }
}

void eliminar (TLista * L1, TLista L2) {
    TLista ant,aux1=*L1, aux2=L2;
    int cont;
    for(int i=0;aux2!=NULL && *L1!=NULL;i++) {
        cont=0;
        aux1=*L1;
        while (aux1!=NULL && cont-i!=aux2->x) {
            ant=aux1;
            aux1=aux1->sig;
            cont++;
        }
        if (aux1==NULL)
            aux2=NULL;
        else {
            if (aux1==*L1) 
                (*L1)->sig=aux1->sig;
            else 
                ant->sig=aux1->sig;
            free(aux1);
            aux2=aux2->sig;
        }
    }  
}

int iguales(TLista L, TLista L2) {
    TLista aux=L,aux2=L2;
    int bool=1;
    while (aux!=NULL && bool) {
        if (aux->x==aux2->x) {
            aux=aux->sig;
            aux2=aux2->sig;
        }
        else
            bool=0;
    }
    return (aux==NULL && aux2==NULL && bool);
}

void mostrar(TLista L) {
    TLista aux=L;
    while (aux!=NULL) {
        printf("%d ",aux->x);
        aux=aux->sig;
    }
    printf("\n");
}