#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoD {
    char car;
    struct nodoD *ant, * sig;
} nodoD;
typedef nodoD * PnodoD;

typedef struct {
    PnodoD pri, ult;
} TListaD;

typedef struct nodoC {
    char car;
    struct nodoC * sig;
} nodoC;
typedef nodoC * TListaC;

void cargaListaD(TListaD * Ld);
void cargaListaC(TListaC * Lc);
void muestaListaD(TListaD Ld);
void muestaListaC(TListaC Lc);
int vocalesC(TListaC Lc);
int vocalesD(TListaD Ld);
void eliminaC(TListaC * Lc, int x);
void eliminaD(TListaD * Ld, int x);

int main () {
    TListaC Lc=NULL;
    TListaD Ld;
    int x;
    cargaListaD(&Ld);
    cargaListaC(&Lc);
    muestaListaD(Ld);
    printf("\n");
    muestaListaC(Lc);
    printf("\n vocales desde Ld: %d",vocalesD(Ld));
    printf("\n vocales desde Lc: %d",vocalesC(Lc));
    printf("\nIngrese valor a eliminar: ");
    scanf("%d",&x);
    eliminaC(&Lc,x);
    eliminaD(&Ld,x);
    printf("\n");
    muestaListaD(Ld);
    printf("\n");
    muestaListaC(Lc);
    return 0;
}

void cargaListaD(TListaD * Ld){
    FILE * arch;
    PnodoD nuevo,act;
    arch=fopen("Programacion 2/g6ej8.txt","rt");
    (*Ld).pri = NULL;
    (*Ld).ult = NULL;
    while (!feof(arch) && arch!=NULL) {
        nuevo=(PnodoD)malloc(sizeof(nodoD));
        fscanf(arch,"%c\n",&nuevo->car);
        if((*Ld).pri == NULL || nuevo->car<(*Ld).pri->car){ // Inserto al principio
            nuevo->sig = (*Ld).pri;
            nuevo->ant = NULL;
            if((*Ld).pri == NULL){
                (*Ld).ult = nuevo;
            }
            else{
                (*Ld).pri->ant=nuevo;
            }
            (*Ld).pri = nuevo;
        }
        else{
            if(nuevo->car>(*Ld).ult->car){ // Inserto al final
                nuevo->ant=(*Ld).ult;
                nuevo->sig=NULL;
                (*Ld).ult->sig=nuevo;
                (*Ld).ult=nuevo;
            }
            else{                           // Recorro
                act = (*Ld).pri;
                while(nuevo->car>=act->car){
                    act = act->sig;
                }
                nuevo->sig = act;
                nuevo->ant = act->ant;
                act->ant->sig = nuevo;
                act->ant = nuevo;
            }
        }
    }
    fclose(arch);
}

void cargaListaC(TListaC * Lc){
    TListaC nuevo,aux,ant;
    char car;
    FILE * arch;
    arch=fopen("Programacion 2/g6ej8.txt","rt");
    while (!feof(arch) && arch!=NULL) {
        fscanf(arch,"%c\n",&car);
        nuevo=(TListaC)malloc(sizeof(nodoC));
        if((*Lc)==NULL) {            // Si esta vacia
            (*Lc)=nuevo;
            nuevo->sig = nuevo;
        }
        else {
            if (car>(*Lc)->car) {   // Si va al final   
                nuevo->sig =(*Lc)->sig;
                (*Lc)->sig = nuevo;
                (*Lc) = nuevo;
            }
            else {
                ant = *Lc;                  // Recorro
                aux = (*Lc)->sig;
                while(car>aux->car) {
                    ant = aux;
                    aux = aux->sig;
                }
                //if(strcmp(cad,aux->car)==0){    // Si son iguales sumo una variable de de la lista
                //    free(nuevo);
                //    aux->cantidad++;
                //}
                //else{
                    ant->sig = nuevo;          // engancho
                    nuevo->sig = aux;
                //}
            }
        }
        nuevo->car=car;
    }
}

void muestaListaD(TListaD Ld){
    PnodoD aux=Ld.pri;
    while (aux!=NULL) {
        printf("%c ",aux->car);
        aux=aux->sig;
    }
}

void muestaListaC(TListaC Lc){
    TListaC aux=Lc->sig;
    while (aux!=NULL && aux!=Lc) {
        printf("%c ",aux->car);
        aux=aux->sig;
    }
    printf("%c ",aux->car);
}

int vocalesC(TListaC Lc){
    TListaC aux=Lc->sig;
    int cont=0;
    while (aux!=NULL && aux!=Lc) {
        if (aux->car=='a' || aux->car=='e' || aux->car=='i' || aux->car=='o' || aux->car=='u')
            cont++;
        aux=aux->sig;
    }
    return cont;
}

int vocalesD(TListaD Ld){
    PnodoD aux=Ld.pri;
    int cont=0;
    while (aux!=NULL) {
        if (aux->car=='a' || aux->car=='e' || aux->car=='i' || aux->car=='o' || aux->car=='u')
            cont++;
        aux=aux->sig;
    }
    return cont;
}

void eliminaC(TListaC *Lc, int x){
    TListaC aux=(*Lc)->sig,ant=(*Lc);
    int pos=0;
    while (aux!=NULL && aux!=*Lc && pos!=x) {
        pos++;
        ant=aux;
        aux=aux->sig;
    }
    if (aux==NULL) 
        printf("\n La lista esta vacia.");  //Lista vacia
    else 
        if (pos!=x) 
            printf("\n El valor esta fuera de rango.");  //caso x>valores
        else {
            if (aux==aux->sig) //caso valor unico en la lista
                *Lc=NULL;
            else {
                if (aux==*Lc)   //caso que se elimine el ultimo de la lista
                    *Lc=ant;
                ant->sig=aux->sig;  //caso general

            }
            free(aux);
        }
}

void eliminaD(TListaD * Ld,int x){
    PnodoD aux=(*Ld).pri;
    int pos=0;
    while (aux!=NULL && pos!=x) {
        aux=aux->sig;
        pos++;
    }
    if ((*Ld).pri==NULL)
        printf("\n La lista esta vacia.");  //Lista vacia
    else
        if (pos!=x)
            printf("\n El valor esta fuera de rango.");  //caso x>valores
        else  {
            if ((*Ld).ult==(*Ld).pri) {    //caso lista de 1 valor
                (*Ld).pri=NULL;
                (*Ld).ult=NULL;
            }
            else   
                if (aux==(*Ld).pri) {      //caso principio de lista
                    (*Ld).pri=aux->sig;
                    aux->sig->ant=NULL;
                }
                else {
                    if (aux==(*Ld).ult) { //caso ultimo de lista
                        (*Ld).ult=aux->ant;
                        aux->ant->sig=NULL;
                    }
                    else {
                        aux->sig->ant=aux->ant;
                        aux->ant->sig=aux->sig;
                    }
                }
            free(aux);
        }
}
