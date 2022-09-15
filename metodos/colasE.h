typedef int TElementoC;

typedef struct {
TElementoC datos[50];
    int pri, ult; } TCola;

void iniciaC (TCola *C);
int vaciaC (TCola C);
void poneC (TCola *C, TElementoC X);
void sacaC (TCola *C, TElementoC *X);
TElementoC consultaC (TCola C);
