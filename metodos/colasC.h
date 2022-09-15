typedef int TElementoC;

typedef struct nodoc {
    TElementoC dato;
    struct nodoc * sig;} nodoc;

typedef struct {
nodoc *pri, *ult;} TCola;

void iniciaC (TCola *C);
int vaciaC(TCola C);
void poneC (TCola *C, TElementoC X);
void sacaC (TCola *C, TElementoC *X);
TElementoC consultaC (TCola C);
