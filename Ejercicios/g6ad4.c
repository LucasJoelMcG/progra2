#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoD { //nodo de documentos sublista
    int documento;
    struct nodoD * sig;
} nodoD;
typedef struct nodoD * TSubLDoc;

typedef struct nodoV {   //nodo de vuelos sublista
    int codV;
    char fecha[20];
    int capacidad;
    struct nodoD * subLD;
    struct nodoV * sig;
} nodoV;
typedef struct nodoV * TSubLVuelo;

typedef struct nodo {  //nodo principal lista SE
    int destino;
    struct nodoV * subLV;
    struct nodo * sig;
} nodo;
typedef struct nodo * TLista;

void nDest(TLista * L); //nuevo destino
void nVuelo(TLista L); //nuevo vuelo
void eVuelo(TLista L); //estado vuelos
void nReserva(TLista L); //nueva reserva
void cReserva(TLista L); //cancela reserva


int main () {
    unsigned int o=1;
    TLista L=NULL;
    //cargaLista(&L);
    while (o!=0) {
        printf("1 - Nuevo destino\n");
        printf("2 - Nuevo vuelo\n");
        printf("3 - Estado de vuelo\n");
        printf("4 - Nueva reserva\n");
        printf("5 - Cancelar reserva\n");
        printf("0 - Salir\n");
        printf("Ingrese opcion: ");
        scanf("%ud", &o);
        switch (o) {
            case 0: break;
            case 1: nDest(&L); break;
            case 2: nVuelo(L); break;
            case 3: eVuelo(L); break;
            case 4: nReserva(L); break;
            case 5: cReserva(L); break;
        default: {
            printf("Opcion erronea.");
            o=6;
            break;
            }
        }
    }
    return 0;
}

void nDest(TLista * L) {
    int nDestino;
    TLista aux,ant,act;
    printf("Ingrese nuevo destino (numero): ");
    scanf("%d",&nDestino);
    aux=(TLista) malloc (sizeof(nodo));
    aux->destino=nDestino;
    aux->subLV=NULL;
    act=*L;
    while (act!=NULL && act->destino!=nDestino) {
        ant=act;
        act=act->sig;
    }
    if (act!=NULL && act->destino==nDestino)
        printf("El destino ya existe.\n");
    else
        if (*L==NULL) {
            *L=aux;
            aux->sig=NULL;
        }
        else
            if (act==*L) {
               aux->sig=*L;
               *L=aux;
            }
            else {
                aux->sig=ant->sig;
                ant->sig=aux;
            }
}

void nVuelo(TLista L) {
    int dest; 
    TLista aux;
    TSubLVuelo auxV;
    printf("Ingrese el destino a agregar vuelo(numero): ");
    scanf("%d",&dest);
    aux=L;
    while (aux!=NULL && aux->destino!=dest) {
        aux=aux->sig;
    }
    if (aux==NULL)
        printf("Destino no encontrado.\n");
    else {
        auxV=(TSubLVuelo) malloc (sizeof(nodoV));
        auxV->subLD=NULL;
        printf("Ingrese Codigo de vuelo: ");
        scanf("%d",&auxV->codV);
        printf("Ingrese fecha y hora de salida: ");
        scanf("%s",auxV->fecha);
        printf("Ingrese capacidad de pasajeros: ");
        scanf("%d",&auxV->capacidad);
        if (aux->subLV==NULL) {
            aux->subLV=auxV;
            auxV->sig=NULL;
        }
        else {
            auxV->sig=aux->subLV;
            aux->subLV=auxV;
        }
    }
}

void eVuelo(TLista L) {
    TLista aux=L;
    TSubLVuelo auxSV;
    TSubLDoc auxSD;
    int destino,cont;
    printf("Ingrese el destino(numero): ");
    scanf("%d",&destino);
    while(aux!=NULL && aux->destino!=destino) 
        aux=aux->sig; 
    if (aux==NULL)
        printf("Destino no encontrado.\n");
    else {
        auxSV=aux->subLV;
        while (auxSV!=NULL) {
            printf("Codigo de vuelo: %d\n Fecha y hora: %s \n Capacidad de pasajeros: %d\n",auxSV->codV,auxSV->fecha,auxSV->capacidad);
            auxSD=auxSV->subLD;
            cont=0;
            printf("Documentos registrados en reservas: \n");
            while (auxSD!=NULL) {
                printf("\t %d \n",auxSD->documento);
                auxSD=auxSD->sig;
                cont++;
            }
            printf("Quedan disponibles %d asientos.",auxSV->capacidad-cont);
            printf("\n ------------------------------------------------------------ \n");
            auxSV=auxSV->sig;
        }
    }
}

void nReserva(TLista L) {
    TLista aux=L;
    TSubLVuelo auxSV;
    TSubLDoc auxSD;
    int destino, vuelo,cont;
    printf("Ingrese el destino(numero): ");
    scanf("%d",&destino);
    while (aux!=NULL && aux->destino!=destino) 
        aux=aux->sig;
    if (aux==NULL)
        printf("Destino no encontrado.\n");
    else {
        printf("Ingrese el Codigo de Vuelo: ");
        scanf("%d",&vuelo);
        auxSV=aux->subLV;
        while (auxSV!=NULL && auxSV->codV!=vuelo) 
            auxSV=auxSV->sig;
        if (auxSV==NULL)
            printf("El vuelo no existe.\n");
        else {
            cont=0;
            auxSD=auxSV->subLD;
            while (auxSD!=NULL) {
                cont++;
                auxSD=auxSD->sig;
            }
            if (cont>auxSV->capacidad)
                printf("El vuelo esta lleno. No se puede reservar pasajes.");
            else {
                auxSD=(TSubLDoc) malloc (sizeof(nodoD));
                auxSD->sig=auxSV->subLD;
                auxSV->subLD=auxSD;
                printf("Ingrese documento para la reserva: ");
                scanf("%d",&auxSD->documento);
            }
        }
    }
} 

void cReserva(TLista L) {
    TLista aux=L;
    TSubLVuelo auxSV;
    TSubLDoc auxSD,antSD;
    int destino, vuelo,doc;
    printf("Ingrese el destino(numero): ");
    scanf("%d",&destino);
    while (aux!=NULL && aux->destino!=destino) 
        aux=aux->sig;
    if (aux==NULL)
        printf("Destino no encontrado.\n");
    else {
        printf("Ingrese el Codigo de Vuelo: ");
        scanf("%d",&vuelo);
        auxSV=aux->subLV;
        while (auxSV!=NULL && auxSV->codV!=vuelo) 
            auxSV=auxSV->sig;
        if (auxSV==NULL)
            printf("El vuelo no existe.\n");
        else {
            printf("Ingrese el documento para cancelar la reserva: ");
            scanf("%d",&doc);
            auxSD=auxSV->subLD;
            while (auxSD!=NULL && auxSD->documento!=doc) {
                antSD=auxSD;
                auxSD=auxSD->sig;
            }
            if (auxSD==NULL) 
                printf("El documento/reserva no se encuentra.\n");
            else {
                if (auxSD==auxSV->subLD) 
                    auxSV->subLD=auxSD->sig;
                else
                    antSD->sig=auxSD->sig;
                free(auxSD);
            }
        }
    }
}
