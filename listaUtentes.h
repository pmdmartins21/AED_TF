#include "utente.h"

typedef struct sListaUtentes
{
    Utente lu[1000];
    int numeroUtentes;
    
} ListaUtentes;

void inserirUtente(ListaUtentes *lu);

int procurarIDNaLista(ListaUtentes *lu, int idAProcurar);

