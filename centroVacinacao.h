#include<stdio.h>
#include<string.h>

typedef struct sCentroVacinacao{
    char nomeCentro[101];
    char morada[101];
    int centroID;
    
} CentroVacinacao;

CentroVacinacao criarCentro() ;