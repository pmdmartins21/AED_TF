#include "vacina.h"
#include <stdio.h>
#include <string.h>

Vacina criarVacina(){
    Vacina v;
    printf("Nome da vacina:\n");
    while (getchar() != '\n');
    fgets(v.designacao, 100, stdin);
    v.designacao[strlen(v.designacao) -1 ] = '\0';
    printf("Numero de doses:\n");
    scanf("%d", &v.nDoses);
    printf("Tempo de espera:\n");
    scanf("%d", &v.tempoEntreVacinas);
    return v;
}


           