#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina lv[100];
    int numeroVacinas;

} ListaVacinas;

void inserirVacina(ListaVacinas *lv);
void listarVacinas(ListaVacinas *lv);
//int procurarVacina(ListaVacinas *lv, int vacinaId);
void inativarVacina(ListaVacinas *lv, int idAInativar);
void editarVacinas(ListaVacinas *lv, int idAInativar);
void listarVacinasAlfabeticamente(ListaVacinas *lv);
void editarNomeVacina(ListaVacinas *lv, int idAEditar);

void gravarDadosListaVacinas(ListaVacinas lv);
void carregarDadosListaVacinas(ListaVacinas *lv);
