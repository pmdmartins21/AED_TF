#include "utente.h"

typedef struct sListaUtentes
{
    Utente lu[1000];
    int numeroUtentes;
    
} ListaUtentes;

void inserirUtente(ListaUtentes *lu);
int procurarIDNaLista(ListaUtentes *lu, int idAProcurar);
void eliminarUtente(ListaUtentes *lu);
void editarUtente(ListaUtentes *lu, int idAEditar);
void alterarNomeUtente(ListaUtentes *lu, int idAEditar);
void alterarContacto(ListaUtentes *lu, int idAEditar);
void alterarIdadeUtente(ListaUtentes *lu, int idAEditar);
void alterarNumeroUtente(ListaUtentes *lu, int idAEditar);

void listarUtentesPorVacinas(ListaUtentes *lu);
void listarUtentesPorCentro(ListaUtentes *lu);
