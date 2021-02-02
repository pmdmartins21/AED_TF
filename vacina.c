#include "vacina.h"
#include <stdio.h>
#include <string.h>


Vacina criarVacina(){
    Vacina v;
    printf("Nome da vacina:\n");
    fgets(v.designacao, 100, stdin);
    v.designacao[strlen(v.designacao) -1 ] = '\0';
    printf("Numero de doses no total:\n");
    scanf("%d", &v.nDoses);
    printf("Tempo de espera entre vacinas (meses):\n");
    scanf("%d", &v.tempoEntreVacinas);
    v.ativo = 1; //ativa a vacina qd a cria
    return v;
}


           