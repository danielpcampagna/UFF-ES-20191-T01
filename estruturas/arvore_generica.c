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
    if(!t) return t;

    TAG *p = busca(t, id);
    TAG *ant = busca_ant(t, id);
    
    if(!p) return t;
    if(!ant) {
        // já garante pela inserção de que não tem irmão.
        if(e_folha(p)) {
            libera_no(p);
            return NULL;
        }
        TAG *nova_raiz = p->filho;
        TAG *ultimo_filho_nova_raiz = ultimo_filho(nova_raiz);
        ultimo_filho_nova_raiz->irmao = nova_raiz->irmao
        nova_raiz->irmao = NULL;
        libera_no(p);
        return nova_raiz;
    }
    TAG *primeiro_filho_p = p->filho;
    TAG *ultimo_filho_p = ultimo_filho(p);
    
    if(ant->filho == p){
        if(!e_folha(p)) ant->filho = primeiro_filho_p;
        else ant->filho = p->irmao;
    } else if(ant->irmao == p){
        if(!e_folha(p)) ant->irmao = primeiro_filho_p;
        else ant->irmao = p->irmao;
    }
    
    if(!e_folha(p)) ultimo_filho_p->irmao = p->irmao;
    libera_no(p);
    return t;
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

