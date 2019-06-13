#include <stdio.h>
#include <stdlib.h>
#include "forms/formularios_arv_gen.h"

int main(){
    int op=-1;
    while (op)
    {
        printf("Escolha uma opçao:\n");
        printf("1. Carregar do arquivo.\n");
        printf("2. Inicializar árvore vazia.\n");
        printf("0. Sair.\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            form_carrega_arquivo();
            break;
        case 2:
            form_inicio(NULL);
            break;
        case 0:
            printf("Fim do programa.\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    }

    return 0;
}