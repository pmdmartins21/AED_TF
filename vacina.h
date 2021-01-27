typedef struct sVacina{
    char designacao[101];
    int nDoses;
    int tempoEntreVacinas;
    int idVacina; //codigo
    int activo;
} Vacina;

Vacina criarVacina();