#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#ifndef TAVL_H
#define TAVL_H

typedef struct arvore_balanceada
{
    int info;
    struct arvore_balanceada *esq;
    struct arvore_balanceada *dir;
    int alt;
} TAVL;

void libera_avl(TAVL *t);
TAVL *busca_avl(int e, TAVL *t);
TAVL *insere_avl(int e, TAVL *t);
int calc_alt_retira_avl(TAVL *T);
int FB_avl(TAVL *T);
void imprime_avl(TAVL *a);
TAVL *retira_avl(int x, TAVL *T);

#endif //TAVL_H