#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **separa(char *texto, char *separador, int qtd) {
    char s[255]; // (int)strlen(texto)+1
    strcpy(s, texto);

    char **result = (char**)malloc(sizeof(char*) * qtd);
    int i = 0;
    char *token = strtok(s, separador);
    for (i = 0; i < qtd && token != NULL; i++) {
        result[i] = token;
        token = strtok(NULL, separador);
    }
    return result;
}