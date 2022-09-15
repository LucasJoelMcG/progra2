typedef int TElementoP;
typedef struct {
    TElementoP datos[50];
    int tope;} TPila;

void iniciaP (TPila * P);
void poneP (TPila * P, TElementoP x);
void sacaP (TPila * P, TElementoP * x);
TElementoP consultaP(TPila P);
int vaciaP (TPila P);
