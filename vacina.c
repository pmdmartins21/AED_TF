#include "vacina.h"
#include <stdio.h>
#include <string.h>

Vacina criarVacina(){
    Vacina c;
    printf("Nome da vacina:");
    while (getchar() != '\n');
    fgets(c.designacao, 100, stdin);
    c.designacao[strlen(c.designacao) -1 ] = '\0';
    printf("Numero de doses:");
    scanf("%d", &c.nDoses);
    printf("Tempo de espera:");
    scanf("%d", &c.tempoEntreVacinas);
    return c;
}