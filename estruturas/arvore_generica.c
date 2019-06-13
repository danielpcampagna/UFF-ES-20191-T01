#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"

static TAGNO *busca_ant_no(TAGNO *no, int id)
{
    if (!no)
        return no;
    if (no->irmao && no->irmao->id == id)
        return no;
    if (no->filho && no->filho->id == id)
        return no;

    TAGNO *p = busca_ant_no(no->irmao, id);

    if (p)
        return p;
    return busca_ant_no(no->filho, id);
}

static TAGNO *busca_ant(TAG *a, int id)
{
    return busca_ant_no(a->raiz, id);
}

static TAGNO *ultimo_filho(TAGNO *no)
{
    if (!no)
        return no;
    no = no->filho;
    while (no->irmao)
        no = no->irmao;
    return no;
}

static int e_folha(TAGNO *no)
{
    return !no->filho;
}

static void libera_no(TAGNO *p) // precisa receber um ponteiro para null e a funcao de liberar esse tipo de estrutura por callback
{
    if (p)
    {
        libera_no_figura(p->info); // precisa receber a função de liberar a figura por callback
        free(p);
    }
}

static int altura_no(TAGNO *no)
{
    if (!no)
        return 0;
    int maior = -1, alt;
    TAGNO *p;
    for (p = no; p; p = p->irmao)
    {
        alt = altura_no(no->filho) + 1;
        if (alt > maior)
            maior = alt;
    }
    return maior;
}

TAG *cria()
{
    TAG *p = malloc(sizeof(TAG));
    p->raiz = NULL;
    return p;
}

static TAGNO *busca_no(TAGNO *no, int id)
{
    if (!no)
        return no;
    if (no->id == id)
        return no;

    TAGNO *p = busca_no(no->irmao, id);

    if (p)
        return p;
    return busca_no(no->filho, id);
}

TAGNO *busca(TAG *a, int id)
{
    if (vazia(a))
        return NULL;
    return busca_no(a->raiz, id);
}

int vazia(TAG *a)
{
    return !a || !(a->raiz);
}

TAG *insere(TAG *a, int pai, int id, void *info)
{
    if (id == pai)
    {
        printf("/!\\Erro: O novo id e id do pai não pode ser o mesmo.\n");
        return a;
    }
    if (vazia(a) && pai > 0)
    {
        printf("/!\\Erro: Deve ter apenas uma raíz.\n");
        return a;
    }
    if (busca(a, id) != NULL)
    {
        printf("/!\\Erro: A árvore genérica não permite que dois nśo tenham um mesmo id.\n");
        return a;
    }

    TAGNO *novo_no = malloc(sizeof(TAGNO));
    novo_no->filho = NULL;
    novo_no->irmao = NULL;
    novo_no->info = (TNOFIG *)info;
    novo_no->id = id;

    if (pai == 0)
    {
        a = cria();
        a->raiz = novo_no;
        return a;
    }

    TAGNO *p = busca(a, pai);
    if (!p)
        return a;
    if (e_folha(p))
        p->filho = novo_no;
    else
    {
        p = ultimo_filho(p);
        p->irmao = novo_no;
    }

    return a;
}

static void imprime_no(TAGNO *t, int andar)
{
    TAGNO *p;
    int i;
    for (i = 0; i < andar; i++)
        printf("      ");
    printf("%6d", t->id); // fazer o print da fig
    printf("|%s", t->info->tipo);
    printf("\n");

    for (p = t->filho; p != NULL; p = p->irmao)
        imprime_no(p, andar + 1);
}

void imprime(TAG *a)
{
    if (vazia(a))
        printf("\n/!\\ árvore vazia...\n");
    else
        imprime_no(a->raiz, 0);
}

TAG *retira(TAG *a, int id)
{
    if (!a)
        return a;

    TAGNO *p = busca(a, id);
    TAGNO *ant = busca_ant(a, id);

    if (!p)
        return a;
    if (!ant)
    { // é raíz!
        // já garante pela inserção de que não tem irmão.
        if (e_folha(p))
        {
            libera_no(p);
            return NULL;
        }
        TAGNO *nova_raiz = p->filho;
        TAGNO *ultimo_filho_nova_raiz = ultimo_filho(nova_raiz);
        ultimo_filho_nova_raiz->irmao = nova_raiz->irmao;
        nova_raiz->irmao = NULL;
        libera_no(p);
        a->raiz = nova_raiz;
        return a;
    }

    TAGNO *primeiro_filho_p = p->filho;
    TAGNO *ultimo_filho_p = ultimo_filho(p);

    if (ant->filho == p)
    {
        if (!e_folha(p))
            ant->filho = primeiro_filho_p;
        else
            ant->filho = p->irmao;
    }
    else if (ant->irmao == p)
    {
        if (!e_folha(p))
            ant->irmao = primeiro_filho_p;
        else
            ant->irmao = p->irmao;
    }

    if (!e_folha(p))
        ultimo_filho_p->irmao = p->irmao;
    libera_no(p);
    return a;
}

static void destroi_no(TAGNO *no)
{
    if (!no)
        return;
    destroi_no(no->irmao);
    destroi_no(no->filho);
    libera_no(no);
}

TAG *destroi(TAG *a)
{
    destroi_no(a->raiz);
    return NULL;
}

// TAG *altera(TAG *t, void *figura, void *altera_fig())
// {
//     TAG *result = NULL;
//     return result;
// }
