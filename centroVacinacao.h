typedef struct sCentroVacinacao{
    char nomeCentro[101];
    char morada[101];
    int centroID;
    int activo; // 1 Ativo, 0 Inativo
} CentroVacinacao;

CentroVacinacao criarCentro();


