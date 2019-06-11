#include "arvore_generica.h"

TAG *cria()
{
    TAG *p = malloc(sizeof(TAG));
    return NULL;
}

TAG *busca(TAG *a, int x)
{
    if (a == NULL) return NULL;
    if (a->id == x) return a;
    
    TAG *p = busca(a->irmao, x);
    
    if (p != NULL) return p;
    return busca(a->filho, x);
}

void insere(TAG *a, TAG *no, int pai)
{

    if(!a) return a;
    
    TAG *no = malloc(sizeof(TAG));
    no->filho = NULL;
    no->irmao = NULL;

    TAG *p = busca(a, pai);
    if(!p) return NULL;
    if(!p->filho) p->filho = no;
    p = p->filho;
    while(p->irmao) p = p->irmao;
    p->irmao = no;
}

void imprime(TAG *t)
{
    TAG *result = NULL;
    return result;
}

TAG *retira(TAG *t, int id)
{
    TAG *result = NULL;
    return result;
}

void destroi(TAG *t)
{
    return;
}

TAG *altera(TAG *t, int id, void *altera_fig(), ...)
{
    TAG *result = NULL;
    return result;
}

