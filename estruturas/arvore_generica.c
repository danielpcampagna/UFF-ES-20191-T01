#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"

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

static int e_folha(TAG* p){
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

TAG *cria()
{
    // TAG *p = malloc(sizeof(TAG));
    // p->info = NULL;
    // p->filho = p->irmao = NULL;
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

TAG* insere(TAG *a, void *info, int pai)
{
    if(!a && pai != 0) return a;
    
    if(pai == 0) {
        a = malloc(sizeof(TAG));
        a->filho = NULL;
        a->irmao = NULL;
        a->info = info;
        return a;
    }

    TAG *no = malloc(sizeof(TAG));
    no->filho = NULL;
    no->irmao = NULL;
    no->info = info;

    TAG *p = busca(a, pai);
    if(!p) return NULL;
    if(e_folha(p)) p->filho = no;
    else {
        p = ultimo_filho(p);
        p->irmao = no;
    }
    return a;
}

void imprime(TAG *t)
{
    printf("imprime 1\n");
    if(!t) return;
    printf("imprime 2\n");
    printf("<");
    printf("imprime 3\n");
    printf("%d",t->info->id);
    imprime(t->irmao);
    imprime(t->filho);
    printf(">");
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
        ultimo_filho_nova_raiz->irmao = nova_raiz->irmao;
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
    if(!t) return;
    destroi(t->irmao);
    destroi(t->filho);
    libera_no(t);
}

// TAG *altera(TAG *t, void *figura, void *altera_fig())
// {
//     TAG *result = NULL;
//     return result;
// }

