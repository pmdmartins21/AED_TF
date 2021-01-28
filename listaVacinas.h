#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina vacinas[100];
    int numeroVacinas;

} ListaVacinas;

void inserirVacina(ListaVacinas *lv);
void editarVacina(ListaVacinas *lv);
void inativarVacina(ListaVacinas *lv);
int listarVacinas(ListaVacinas lv);


void gravarDadosListaAlunos(ListaAlunos la);
void carregarDadosListaAlunos(ListaAlunos *la);