#include "arvore_generica.h"

TAG *cria()
{
    TAG *p = malloc(sizeof(TAG));
    return NULL;
}

TAG *busca(TAG *t, int id)
{
    if (!t) return t;
    if (t->id == id) return t;
    
    TAG *p = busca(t->irmao, id);
    
    if (p) return p;
    return busca(t->filho, id);
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

