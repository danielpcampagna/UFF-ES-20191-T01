#include "arvore_generica.h"

TAG *cria()
{
    TAG *p = malloc(sizeof(TAG));
    return NULL;
}

TAG *busca(TAG *t, int id)
{
    if (!t) return t;
    if (t->info->id == id) return t;
    
    TAG *p = busca(t->irmao, id);
    
    if (p) return p;
    return busca(t->filho, id);
}

static TAG *busca_ant(TAG *t, int id)
{
    if (!t) return t;
    if (t->irmao && t->irmao->info->id == id) return t;
    if (t->filho && t->filho->info->id == id) return t;
    
    TAG *p = busca_ant(t->irmao, id);
    
    if (p) return p;
    return busca_ant(t->filho, id);
}

static TAG* ultimo_filho(TAG *p){
    if(!p) return p;
    p = p->filho;
    while(p->irmao) p = p->irmao;
    return p;
}

static e_folha(TAG* p){
    return !p->filho;
}

static void libera_no(TAG* p){
    if(p) {
        if(p->info) {
            if(p->info->figura)
                free(p->info->figura);
            free(p->info);
        }
        free(p);
    }
}

TAG* insere(TAG *a, TNOFIG *info, int pai)
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

