#include "vacina.h"
#include "listaVacinas.h"
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

void menuVacinas(ListaVacinas *lv) {
    int idAInativar;
    int opcao = 0;
    while (opcao != 5)
    {
        printf(">>> MENU VACINAS <<<\n\n");
        printf("1 - Inserir nova vacina\n"); 
        printf("2 - Editar vacina\n");
        printf("3 - Inativar vacina\n");
        printf("4 - Listar vacinas\n");
        printf("5 - Gravar dados da vacina\n");
        printf("6 - Sair\n\n");
        printf(">>> ESCOLHA A OPCAO A ALTERAR <<<\n");

        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                criarVacina(&lv);
                break;
            case 2:
                listarVacina();
                printf("Qual o id da vacina a editar?");
                scanf("%d", &idAInativar);
                editarVacina(&lv, idAInativar);
                break;
            case 3:
                listarVacina();
                printf("Qual o id da vacina a inativar?");
                scanf("%d", &idAInativar);
                inativarVacina(&lv, idAInativar);
                break;
            case 4:
                listarVacina();
                break;
            case 5:
                gravarDadosListaVacinas(&lv);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }  
}
           