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
TAG* insere(TAG *t, char* tipo, TAG *pai, void *figura);
TAG* retira(TAG *t, int id);
void destroi(TAG *t);
TAG* altera(TAG *t, int id, void *altera_fig(), ...);
//TAG* insere(TAG *t, int id, char* tipo, TAG *pai);

#endif //ARVORE_GENERICA_H