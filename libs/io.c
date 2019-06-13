#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../estruturas/arvore_generica.h"
#include "../estruturas/avl.h"
#include "../estruturas/arvb.h"
#include "../figuras/circulo.h"
#include "../figuras/quadrado.h"
#include "../figuras/retangulo.h"
#include "../figuras/trapezio.h"
#include "../figuras/triangulo.h"

// char *ler_linha(FILE *fp) {
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     if (fp == NULL) return NULL;
//     if ((read = getline(&line, &len, fp)) != -1) return line;

//     return NULL;
// }

static void ler_no(char *linha, int *id, int *pai, char *sfig) {
    int n = sscanf(linha, "%d/%d/%[^\n]", id, pai, sfig);
    if (n != 3) {
        *id = *pai = -1;
        sfig = NULL;
    }
}

static void ler_figura(char *str, char *tipo, float *val) {
    int n = sscanf(str, "%3s %f %f %f", tipo, val, &val[1], &val[2]);
    if (n != 4) {
        tipo = NULL;
        val = NULL;
    }
}

TAG* carregar_do_arquivo(char *entrada)
{
    char linha[255];
    FILE *fp;
    fp = fopen(entrada, "r");

    if (fp == NULL) return NULL;

    TAG *arvore = cria();
    // TAVL *arvore = NULL;
    // TAB *arvore = inicializa_arvb();

    while (fgets(linha, 121, fp))
    {
        int pai, id;
        char sfig[121], tipo[3];
        float val[3];

        ler_no(linha, &id, &pai, sfig);
        if(sfig == NULL) {
            printf("Os dados no arquivo não estao no formato especificado.\n");
            return NULL;
        }

        ler_figura(sfig, tipo, val);      

        void *figura;
        if (strcmp(tipo,"CIR")) {
            figura = criar_circ(val[0]);
        } else if (strcmp(tipo,"QUA")) {
            figura = criar_quad(val[0]);
        } else if (strcmp(tipo,"RET")) {
            figura = criar_retg(val[0], val[1]);
        } else if (strcmp(tipo,"TRI")) {
            figura = criar_tria(val[0], val[1]);
        } else if (strcmp(tipo,"TRA")) {
            figura = criar_trap(val[0], val[1], val[2]);
        }

        TNOFIG *novo_no = (TNOFIG *) malloc(sizeof(TNOFIG));
        strcpy(novo_no->tipo, tipo);
        novo_no->figura = figura;

        arvore = insere(arvore, pai, id, novo_no);
    }
    if(arvore) printf("Árvore carregada do arquivo com sucesso!\n");
    return arvore;
}
