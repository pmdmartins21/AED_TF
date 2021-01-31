#include "vacina.h"
#include <stdio.h>
#include <string.h>

Vacina criarVacina(){
    Vacina v;
    printf("Nome da vacina:");
    while (getchar() != '\n');
    fgets(v.designacao, 100, stdin);
    v.designacao[strlen(v.designacao) -1 ] = '\0';
    printf("Numero de doses:");
    scanf("%d", &v.nDoses);
    printf("Tempo de espera:");
    scanf("%d", &v.tempoEntreVacinas);
    return v;
}


           