#include "centroVacinacao.h"
#include<stdio.h>
#include<string.h>

CentroVacinacao criarCentro() {
    CentroVacinacao cv;
    printf("O nome do Centro:");
    while (getchar() != '\n');
    fgets(cv.nomeCentro,101, stdin);
    cv.nomeCentro[strlen(cv.nomeCentro) -1 ] = '\0';
    printf("A morada do Centro:");
    while (getchar() != '\n');
    fgets(cv.morada,101, stdin);
    cv.morada[strlen(cv.morada) -1 ] = '\0';
    printf("O ID do Centro de Vacinacao :");
    scanf("%d", &cv.centroID);
    return cv;
}