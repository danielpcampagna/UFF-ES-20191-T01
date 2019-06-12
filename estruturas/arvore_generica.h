#include<stdarg.h>

#ifndef ARVORE_GENERICA_H
#define ARVORE_GENERICA_H

#include "no_figura.h"

typedef struct arvore_generica_no {
    int id;
    TNOFIG *info; // Precisa ser genérico. Toda referência a este nó se dá por callback
    struct arvore_generica_no *filho, *irmao; 
} TAGNO;

typedef struct arvore_generica {
    TAGNO *raiz;
} TAG;

TAG* cria(void);
TAGNO* busca(TAG *t, int id);
void imprime(TAG *t);
TAG* insere(TAG *a, int pai, int id, void *info);
TAG* retira(TAG *t, int id);
void destroi(TAG *t);
// TAG* altera(TAG *t, int id, void *altera_fig(), ...);

#endif //ARVORE_GENERICA_H