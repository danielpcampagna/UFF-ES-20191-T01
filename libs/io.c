#include <stdio.h>

char *ler_linha(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL) return NULL;
    if ((read = getline(&line, &len, fp)) != -1) return line;

    return NULL;
}