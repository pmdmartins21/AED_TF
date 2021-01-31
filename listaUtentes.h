#include "utente.h"

typedef struct sListaUtentes
{
    Utente utentes[1000];
    int quantidade;


} ListaUtentes;

void incerirUtente(ListaUtentes *lu);

int procurarIDNaLista(ListaUtentes *lu, int idAProcurar);

