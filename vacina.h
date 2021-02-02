typedef struct sVacina{
    
    int idVacina; //codigo
    char designacao[101];
    int nDoses;
    int tempoEntreVacinas; // meses
    int ativo;

} Vacina;

Vacina criarVacina();
