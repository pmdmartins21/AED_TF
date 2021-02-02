typedef struct sData {
    int dias;
    int meses;
    int ano;
} Data;


typedef struct sUtente{
    char nome[101];
    int numeroDeUtente;
    int idade;
    char contatoTelefonico[21];
    int vacinaID; // vacina que recebeu
    int centroID; // centro onde foi vacinado pela ultima vez
    int quantidadeDosesAdmn;
    Data dataUltimaDosagem;

} Utente;

Utente criarUtente();

