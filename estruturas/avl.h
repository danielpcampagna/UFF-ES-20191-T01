#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef TAVL_H
#define TAVL_H

#include "no_figura.h"

typedef struct arvore_balanceada
{
    int id;
    TNOFIG *info; // Precisa ser genérico. Toda referência a este nó se dá por callback
    struct arvore_balanceada *esq;
    struct arvore_balanceada *dir;
    int alt;
} TAVL;

void libera_avl(TAVL *t);
TAVL *busca_avl(TAVL *t, int id);
TAVL *insere_avl(TAVL *t, int id, TNOFIG *info);
int calc_alt_retira_avl(TAVL *T);
int FB_avl(TAVL *T);
void imprime_avl(TAVL *a);
TAVL *retira_avl(TAVL *T, int id);

#endif //TAVL_H