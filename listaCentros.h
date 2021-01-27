#include "centroVacinacao.h"

typedef struct sListaCentrosDeVacinacao
{
    CentroVacinacao centros[1000];
    int numeroCentros;
    
} ListaCentros;

void inserirCentro(ListaCentros *lc);

void inactivarCentro(ListaCentros *lc, CentroVacinacao cv);

void editarCentro(ListaCentros *lc, CentroVacinacao cv);

alterarNomeCentro(cv);
