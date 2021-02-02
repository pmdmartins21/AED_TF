#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina lv[100];
    int numeroVacinas;

} ListaVacinas;

void inserirVacina(ListaVacinas *lv);
void listarVacinas(ListaVacinas *lv);
//int procurarVacina(ListaVacinas *lv, int vacinaId);
void ativarInativarVacina(ListaVacinas *lv, int idAInativar);
void editarVacinas(ListaVacinas *lv, int idAInativar);
void listarVacinasAlfabeticamente(ListaVacinas lv);
void editarNomeVacina(ListaVacinas *lv, int idAEditar);
int procurarIDNaListaVacinas(ListaVacinas *lv, int idAProcurar);

void gravarDadosListaVacinas(ListaVacinas lv);
void carregarDadosListaVacinas(ListaVacinas *lv);