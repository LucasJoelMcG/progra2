#include <stdlib.h>
#include "colasE.h"

void iniciaC (TCola *C) {
    (*C).pri=-1;
    (*C).ult=-1;
}

int vaciaC(TCola C){
 return C.pri==-1;
}

void poneC (TCola *C, TElementoC X) {
    if ((*C).ult != 49) {
        if ((*C).pri==-1)
            (*C).pri = 0;
        (*C).datos[++((*C).ult)]=X;
    }
}
void sacaC (TCola *C, TElementoC *X) {
    if ((*C).pri != -1) { // !vaciaC(*C)
        *X = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult)
            IniciaC(C);
        else
            (*C).pri +=1;
    }
}

TElementoC consultaC (TCola C){
    if (C.pri !=-1)
        return C.datos[C.pri];
}
