#include "vacina.h"

typedef struct sListaVacinas
{
    Vacina vacinas[10];
    int numeroVacinas;

} ListaVacinas;

void adicionarVacina(ListaVacinas *lv);