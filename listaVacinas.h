#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina lv[100];
    int numeroVacinas;

} ListaVacinas;

void inserirVacina(ListaVacinas *lv);
void editarVacina(ListaVacinas *lv);
void inativarVacina(ListaVacinas *lv, int idAInativar)
int listarVacinas(ListaVacinas lv);


void gravarDadosListaVacinas(ListaVacinas lv);
void carregarDadosListaVacinas(ListaVacinas *lv);
