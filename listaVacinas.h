#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina lv[100];
    int numeroVacinas;

} ListaVacinas;

void inserirVacina(ListaVacinas *lv);
int listarVacinas(ListaVacinas lv);
void procurarVacina(ListaVacinas *lv, int vacinaId);
void inativarVacina(ListaVacinas *lv, int idAInativar);
void editarVacina(ListaVacinas *lv, int idAInativar);
void listarVacinasAlfabeticamente(ListaVacinas *lv);

void gravarDadosListaVacinas(ListaVacinas lv);
void carregarDadosListaVacinas(ListaVacinas *lv);
