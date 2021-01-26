#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "centroVacinacao.h"
#include "utente.h"



int main(int argc, char const *argv[])
{
    CentroVacinacao cv = criarCentro();
    Utente u = criarUtente();
    printf("idade utente: %d",u.idade);
    printf("id centro: %d",cv.centroID);

    return 0;
}
