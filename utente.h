
typedef struct sUtente{
    char nome[101];
    int numeroDeUtente;
    int idade;
    char contatoTelefonico[21];
    int vacinaID;
    int centroID;
    int quantidadeDosesAdmn;
    char dataUltimaDosagem[41];

} Utente;

Utente criarUtente();

