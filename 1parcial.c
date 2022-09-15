#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colasE.h"

typedef struct nodoD {
    float pFinal;
    char codGim[9];
    unsigned int Intentos;
    TCola puntajes;
    struct nodoD *ant, * sig;
} nodoD;
typedef nodoD * PnodoD;

typedef struct {
    PnodoD pri, ult;
} TListaD;

typedef struct nodito {
    int puntaje;
    struct nodito * sig;
} nodito;
typedef struct nodito * TSubL;

typedef struct nodol {
    char codGim[9];
    char nac[5];
    char codDisc[4];
    TSubL SubL;
    struct nodol * sig;
} nodol;
typedef struct nodol * TLista;

//cargaLista(TLista * L);
void incisoA (TLista L);
void incisoB (TLista L, TListaD * D);

int main () {
    TLista L=NULL;
    TListaD D;
    D.pri=NULL;
    D.ult=NULL;
    //cargaLista(&L);
    incisoA(L);
    incisoB(L,&D);
    return 0;
}

void incisoA (TLista L) {
    TLista aux=L;
    TSubL auxSL,antSL,elim;
    TCola c;
    char cNac[5],cDisc[4];
    int mejor,peor,suma=0,cont=0;
    float prom=0;
    TElementoC x;
    FILE * arch;
    printf("Ingrese codigo de nacionalidad: ");
    scanf("%s",cNac);
    printf("Ingrese codigo de disciplina: ");
    scanf("%s", cDisc);
    iniciaC(&c);
    arch=fopen("DEPURAND.TXT","wt"); 
    while (aux!=NULL && strcmp(aux->nac,cNac)<0)
        aux=aux->sig;
    while (aux!=NULL && strcmp(aux->codDisc,cDisc)==0) {
        auxSL=aux->SubL;
        mejor=0;
        peor=11;
        while (auxSL!=NULL) {
            if (auxSL->puntaje>mejor)
                mejor=auxSL->puntaje;
            if (auxSL->puntaje>peor)
                peor=auxSL->puntaje;
            poneC(&c,auxSL->puntaje);
            auxSL=auxSL->sig;
        }
        fprintf(arch,"%s %d %d \n",aux->codGim,mejor,peor);
        auxSL=aux->SubL;
        while (auxSL!=NULL) {
            if (auxSL->puntaje==mejor){
                if (auxSL==aux->SubL) 
                    aux->SubL=auxSL->sig;
                else 
                    antSL->sig=auxSL->sig;
                elim=auxSL;
                auxSL=auxSL->sig;
                free(elim);
            }
            else {
                if (auxSL->puntaje==peor) {
                    if (auxSL==aux->SubL) 
                        aux->SubL=auxSL->sig;
                    else 
                        antSL->sig=auxSL->sig;
                    elim=auxSL;
                    auxSL=auxSL->sig;
                    free(elim);
                }
                else {
                    antSL=auxSL;
                    auxSL=auxSL->sig;
                }
            }
        }
    }
    while (!vaciaC(c)){
        sacaC(&c,&x);
        cont++;
        suma+=x;
    }
    if (cont!=0)
        printf("El promedio de todas las puntuaciones depuradas es: %f",suma/cont);
    else
        printf("No se depuro nada.");
    fclose(arch);
}

void incisoB (TLista L, TListaD * D) {
    TLista auxL;
    TSubL auxSL;
    PnodoD nuevo,act;
    int contTotal=0,sumaTotal=0,contParcial,sumaParcial;
    auxL=L;
    while (auxL!=NULL) {
        auxSL=auxL->SubL;
        sumaParcial=0;
        contParcial=0;
        while (auxSL!=NULL) {
            sumaParcial+=auxSL->puntaje;
            contParcial++;
        }
        if (contParcial!=0) {
            sumaTotal+=sumaParcial/contParcial;
            contTotal++;
        }
        nuevo=(PnodoD) malloc (sizeof(nodoD));
        strcpy(nuevo->codGim,auxL->codGim);
        if((*D).pri==NULL || strcmp(nuevo->codGim,(*D).pri->codGim)<0) { 
            nuevo->sig=(*D).pri;
            nuevo->ant=NULL;
            if((*D).pri==NULL){
                (*D).ult=nuevo;
            }
            else{
                (*D).pri->ant=nuevo;
            }
            (*D).pri=nuevo;
        }
        else{
            if(strcmp(nuevo->codGim,(*D).ult->codGim)>0){ 
                nuevo->ant=(*D).ult;
                nuevo->sig=NULL;
                (*D).ult->sig=nuevo;
                (*D).ult=nuevo;
            }
            else{                           
                act=(*D).pri;
                while(strcmp(nuevo->codGim,act->codGim)>=0){
                    act=act->sig;
                }
                if (strcmp(nuevo->codGim,act->codGim)!=0) {
                    nuevo->sig=act;
                    nuevo->ant=act->ant;
                    act->ant->sig=nuevo;
                    act->ant=nuevo;
                    if (contParcial!=0) {
                        nuevo->Intentos=contParcial;
                        nuevo->pFinal=sumaParcial/contParcial;
                        iniciaC(&nuevo->puntajes);
                        poneC(&nuevo->puntajes,sumaParcial/contParcial);
                    }
                }
                else {
                    if (contParcial!=0)
                        poneC(&act->puntajes,sumaParcial/contParcial);
                    free(nuevo);
                }
            }
        }
    }
    if (contTotal!=0)
        printf("El promedio global de puntajes es: %f",sumaTotal/contTotal);
}