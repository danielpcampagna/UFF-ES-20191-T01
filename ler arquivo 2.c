#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas/arvore_generica.h"
#include "figuras/circulo.h"
#include "figuras/quadrado.h"
#include "figuras/retangulo.h"
#include "figuras/trapezio.h"
#include "figuras/triangulo.h"


static void ler_no(char *linha, int *id, int *pai, char *sfig) {
    int n = sscanf(linha, "%d/%d/%[^\n]", id, pai, sfig);
    if (n != 3) {
        *id = *pai = -1;
        sfig = NULL;
    }
}

static void ler_figura(char *str, char *tipo, float *val) {
    printf("%s|%s|%f|%f|%f\n", str, tipo, val[0], val[1], val[2]);
    int n = sscanf(str, "%3s %f %f %f", tipo, val, &val[1], &val[2]);
    printf("%s|%s|%f|%f|%f|%d\n", str, tipo, val[0], val[1], val[2], n);
    if (n != 4) {
        tipo = NULL;
        val = NULL;
    }
}

int main()
{
    char entrada[121];
    char linha[121];
    char tipo[3];
    float base, bmaior, bmenor, altura, lado, lado1, lado2, raio;

    //labrir arquivo

    FILE *fp;

    //  printf ("Digite o nome do arquivo de entrada. \n");
    // scanf("%120s", entrada);
    fp = fopen("data", "r");

    if (fp == NULL) {
        printf("Nao foi possivel abrir o arquivo de entrada: %s \n", entrada);
        exit(1);
    }

    TAG *arvore = cria();

    while (fgets(linha, 121, fp))
    {
        int pai, id;
        char sfig[121], tipo[3];
        float val[3];
        
        printf("%s", linha);

        ler_no(linha, &id, &pai, sfig);
        printf("A\n");
        if(sfig == NULL) {
            printf("Os dados no arquivo não estao no formato especificado.\n");
            return 1;
        }

        printf("0\n");
        ler_figura(sfig, tipo, val);      

        printf("1\n");
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
        printf("2\n");

        TNOFIG *novo_no = (TNOFIG *) malloc(sizeof(TNOFIG));
        novo_no->id = id;
        strcpy(novo_no->tipo, tipo);
        novo_no->figura = figura;

        printf("3\n");

    

        insere(arvore, novo_no, pai);
        imprime(arvore);

    }

    imprime(arvore);

    return 0;
}
