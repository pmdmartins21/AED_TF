#include "centroVacinacao.h"

typedef struct sListaCentrosDeVacinacao
{
    CentroVacinacao centros[1000];
    int numeroCentros;
    
} ListaCentros;

void inserirCentro(ListaCentros *lc);

void inactivarCentro(ListaCentros *lc, int IdAInativar);

void editarCentro(ListaCentros *lc, int IdAInativar);

void alterarNomeCentro(cv);

int procurarIDNaListaCentros(ListaCentros *lc, int idAProcurar);

void listarCentros(ListaCentros *lc);