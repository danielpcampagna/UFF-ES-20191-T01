#include<stdarg.h>

#ifndef ARVORE_GENERICA_H
#define ARVORE_GENERICA_H

typedef struct no_figura {
    int id;
    char tipo[3];
    void *figura;
} TNOFIG;

typedef struct arvore_generica {
    TNOFIG *info;
    struct arvore_generica *filho, *irmao; 
} TAG;



TAG* cria(void);
TAG* busca(TAG *t, int id);
void imprime(TAG *t);
TAG* insere(TAG *a, void *info, int pai);
TAG* retira(TAG *t, int id);
void destroi(TAG *t);
// TAG* altera(TAG *t, int id, void *altera_fig(), ...);

#endif //ARVORE_GENERICA_H