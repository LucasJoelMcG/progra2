#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo {
    int cant;
    char pal[20];
    struct nodo * sig;
} nodo;
typedef nodo * TLista;

void muestra(TLista L);
void carga(TLista * L);

int main () {
    TLista L=NULL;
    carga(&L);
    muestra(L);
    return 0;
}

void muestra(TLista L) {
    TLista aux=L;
    while (aux!=NULL) {
        printf("La palabra '%s' aparece %d veces. \n",aux->pal,aux->cant);
        aux=aux->sig;
    }
}

void carga(TLista * L) {
    FILE * arch;
    char p[20];
    TLista aux,act,ant;
    arch=fopen("E:/Usuarios/ColdFusion/Escritorio/Facultad u.u/VSCode/Programacion 2/g6ej3.txt","rt");
    while (!feof(arch) && arch!=NULL) {
        aux=(TLista) malloc (sizeof(nodo));
        fscanf(arch,"%s",&p);
        strcpy(aux->pal,p);
        aux->cant=1;
        act=*L;
        if (*L == NULL || strcmp((*L)->pal,aux->pal)>0) {
            aux->sig = *L;
            *L = aux;
        }
        else{
            ant=NULL;
            act=*L;
            while (act!=NULL && strcmp(aux->pal,act->pal)>0) {
                ant=act;
                act=act->sig;
            }
            if (act!=NULL && strcmp(aux->pal,act->pal)==0) {
                act->cant+=1;
                free(aux);
            }
            else {
                aux->sig=act;
                ant->sig=aux;
            }
        }
    }
}