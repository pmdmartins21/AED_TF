#include "utente.h"
#include "listaCentros.h"
#include "listaVacinas.h"

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

void listarUtentesPorVacinas(ListaUtentes *lu, ListaVacinas *lv);
void listarUtentesPorCentro(ListaUtentes *lu, ListaCentros *lc);

void carregarDadosListaUtentes(ListaUtentes *lu);
void gravarDadosListaUtentes(ListaUtentes lu);
