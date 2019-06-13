#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../estruturas/arvore_generica.h"
#include "../estruturas/avl.h"
#include "../estruturas/no_figura.h"
#include "../figuras/circulo.h"
#include "../figuras/quadrado.h"
#include "../figuras/retangulo.h"
#include "../figuras/trapezio.h"
#include "../figuras/triangulo.h"
#include "../libs/io.h"
#include "formularios_arv_gen.h"

// static int e_numero(char *val, int tam)
// {
//     int i;
//     for (i = 0; i < tam; i++)
//     {
//         if (!isdigit(val[i]))
//             return 0;
//         return 1;
//     }
// }
// static int form_recebe_id()
// {
//     // char sid[255];
//     // int id;

//     // while (!e_numero(sid, 255)){
//     //     printf("Informe o id da figura que se deseja buscar:\n");
//     //     scanf("%d", &sid);

//     // }
//     // sscanf(sid, "%d", &id);
//     // return id;
// }

// void form_altera_circ(TAG *t)
// {
//     // float novo_raio;
//     // int id = form_recebe_id();

//     // TAGNO *no = busca(t, id);
//     // TCirc *fig = (TCirc *)no->figura;
//     // printf("Informe o valor do novo raio (%d)", fig->raio);
//     // scanf(":", &novo_raio);
// }

/////////////
// static e_tipo_valido(char *tipo)
// {
//     char tipos_validos[5][3] = {
//         "CIR",
//         "QUA",
//         "RET",
//         "TRA",
//         "TRI"};
//     int i;
//     for (i=0;i<5,i++)
//         if()
//     return strcmp(tipo, "QUA")==0 || strcmp(tipo, "")==0 ||
// }

static int alert_se_vazia(TAG *a)
{
    if (vazia(a))
    {
        printf("\n/!\\ Árvore vazia.\n\n");
        return 1;
    }
    return 0;
}

static TCirc *form_altera_cir(TCirc *f)
{
    float novo_raio;
    printf("Informe o valor do novo raio (%f): \n", f->raio);
    scanf("%f", &novo_raio);
    f->raio = novo_raio;
    return f;
}

static TQuad *form_altera_qua(TQuad *f)
{
    float novo_lado;
    printf("Informe o valor do novo lado (%f): \n", f->lado);
    scanf("%f", &novo_lado);
    f->lado = novo_lado;
    return f;
}

static TRetg *form_altera_ret(TRetg *f)
{
    float base, alt;
    printf("Informe o valor da base (%f): \n", f->base);
    scanf("%f", &base);
    f->base = base;
    printf("Informe o valor da altura (%f): \n", f->altura);
    scanf("%f", &alt);
    f->altura = alt;
    return f;
}

static TTrap *form_altera_tra(TTrap *f)
{
    float base1, base2, alt;
    printf("Informe o valor da base 1 (%f): \n", f->base_maior);
    scanf("%f", &base1);
    printf("Informe o valor da base 2 (%f): \n", f->base_menor);
    scanf("%f", &base2);
    if (base1 > base2)
    {
        f->base_maior = base1;
        f->base_menor = base2;
    }
    else
    {
        f->base_maior = base2;
        f->base_menor = base1;
    }
    printf("Informe o valor da altura (%f): \n", f->altura);
    scanf("%f", &alt);
    f->altura = alt;
    return f;
}

static TTria *form_altera_tri(TTria *f)
{
    float base, alt;
    printf("Informe o valor da base (%f): \n", f->base);
    scanf("%f", &base);
    f->base = base;
    printf("Informe o valor da altura (%f): \n", f->altura);
    scanf("%f", &alt);
    f->altura = alt;
    return f;
}

////////////// FORMULARIO DE CRIACOES

static TCirc *form_cria_cir()
{
    float raio;
    printf("Informe o valor do raio: \n");
    scanf("%f", &raio);
    TCirc *result = criar_circ(raio);
    return result;
}
static TQuad *form_cria_qua()
{
    float lado;
    printf("Informe o valor do lado: \n");
    scanf("%f", &lado);
    return criar_quad(lado);
}
static TRetg *form_cria_ret()
{
    float base, alt;
    printf("Informe o valor da base: \n");
    scanf("%f", &base);
    printf("Informe o valor da altura: \n");
    scanf("%f", &alt);
    return criar_retg(base, alt);
}
static TTrap *form_cria_tra()
{
    float base1, base2, alt;
    printf("Informe o valor da base 1: \n");
    scanf("%f", &base1);
    printf("Informe o valor da base 2: \n");
    scanf("%f", &base2);
    printf("Informe o valor da altura: \n");
    scanf("%f", &alt);
    if (base1 > base2)
        return criar_trap(base1, base2, alt);
    else
        return criar_trap(base2, base1, alt);
}
static TTria *form_cria_tri()
{
    float base, alt;
    printf("Informe o valor da base: \n");
    scanf("%f", &base);
    printf("Informe o valor da altura: \n");
    scanf("%f", &alt);
    return criar_tria(base, alt);
}

void form_carrega_arquivo()
{
    TAG *a;
    char nome_arquivo[255];
    printf("Informe o caminho/nome do arquivo:\n");
    scanf(" %254[^\n]", nome_arquivo);

    printf("Buscando o arquivo %s...\n", nome_arquivo);

    a = carregar_do_arquivo(nome_arquivo);

    if (a)
        form_inicio(a);
    else
        printf("Nao foi possivel abrir o arquivo %s.\n", nome_arquivo);
}

// FUNCAO PRINCIPAL
void form_inicio(TAG *a)
{
    int op;
    while (1)
    {
        printf("Escolha uma das opções:\n");
        if (vazia(a))
            printf("*");
        printf("1. Acessar uma figura.\n");
        if (vazia(a))
            printf("*");
        printf("2. Imprimir a árvore.\n");
        printf("3. Inserir nova figura.\n");
        //printf("4. Retirar figuras, passando seus descendentes para outro pai.\n");
        if (vazia(a))
            printf("*");
        printf("4. Destruir a árvore.\n");
        //printf("6. Alterar as dimensões da figura.\n");
        if (vazia(a))
            printf("*");
        printf("5. Transformar a árvore numa árvore binária de busca balanceada.\n");
        if (vazia(a))
            printf("*");
        printf("6. Transformar a árvore numa árvore B.\n");
        printf("0. Voltar.\n");
        printf("------\n");
        if (vazia(a))
            printf("* com a árvore vazia essas opções não podem ser executadas.\n");
        printf("\n");
        scanf("%d", &op);

        if (op == 1)
            form_acessa_figura(a);
        else if (op == 2)
            form_imprimir(a);
        else if (op == 3)
            a = form_inserir(a);
        // else if (op == 4)
        //     a = form_retirar(a);
        else if (op == 4)
        {
            a = form_destruir(a);
            a = cria();
        }
        // else if (op == 6)
        //     form_alterar_dim_fig(a);
        else if (op == 5)
            form_transf_avl(a);
        else if (op == 6)
            form_transf_arvb(a);
        else if (op == 0)
            return;
        else
            printf("Opção inválida.\n");
    }
}
void form_acessa_figura(TAG *a)
{
    if (alert_se_vazia(a))
        return;

    int id, op;
    printf("Informe o id da figura:\n");
    scanf("%d", &id);

    TAGNO *no = busca(a, id);

    if (!no)
    {
        printf("/!\\Erro: Elemento não encontrado.\n");
        return;
    }
    do
    {
        printf("\n#%-3d ", no->id);
        form_imprime_figura(no->info);

        printf("\n");
        printf("Escolha uma das opções:\n");
        printf("1. Alterar dimensões.\n");
        printf("2. Remover figura\n");
        // printf("3. Desenhar.\n");
        printf("0. Voltar\n");
        scanf("%d", &op);

        if (op == 1)
        {
            no = form_alterar_dim_fig(no);
            // pode ser que nao funcione
        }
        else if (op == 2)
        {
            a = form_retirar(a, id);
            return;
        }
        else if (op == 0)
            return;
        else
            printf("Opção inválida.\n");
    } while (op > 0 && op <= 2);
}

void form_imprimir(TAG *a)
{
    if (alert_se_vazia(a))
        return;
    imprime(a);
    printf("\n");
}

TAG *form_inserir(TAG *a)
{
    int op;
    int id, pai;
    void *figura;
    char tipo[3];
    do
    {
        printf("Digite o número referente ao tipo de figura:\n");
        printf("1. Círculo.\n");
        printf("2. Quadrado.\n");
        printf("3. Retângulo.\n");
        printf("4. Trapézio.\n");
        printf("5. Triângulo.\n");
        printf("0. Voltar.\n");
        scanf("%d", &op);

        if (op == 1)
        {
            figura = (void *)form_cria_cir();
            strcpy(tipo, "CIR");
        }
        else if (op == 2)
        {
            figura = (void *)form_cria_qua();
            strcpy(tipo, "QUA");
        }
        else if (op == 3)
        {
            figura = (void *)form_cria_ret();
            strcpy(tipo, "RET");
        }
        else if (op == 4)
        {
            figura = (void *)form_cria_tra();
            strcpy(tipo, "TRA");
        }
        else if (op == 5)
        {
            figura = (void *)form_cria_tri();
            strcpy(tipo, "TRI");
        }
        else if (op == 0)
            return a;
        else
            printf("Opção inválida.\n");
    } while (op < 0 || op > 5);

    imprime(a);
    printf("\n");

    printf("Informe o id do novo nó:\n");
    scanf("%d", &id);
    if (vazia(a))
        pai = 0;
    else
    {
        printf("Informe o id do seu pai:\n");
        scanf("%d", &pai);
    }
    TNOFIG *info = (TNOFIG *)malloc(sizeof(TNOFIG));
    info->figura = figura;
    strcpy(info->tipo, tipo);

    printf("\n\n inserindo pai(%d), id(%d), tipo(%s) \n\n", pai, id, tipo);
    TAG *nova_arv = insere(a, pai, id, info);
    if (!nova_arv)
        printf("Erro ao inserir a figura.\n");
    else
        a = nova_arv;
    return a;
}

TAG *form_retirar(TAG *a, int id)
{
    TAG *nova_arv = retira(a, id);
    if (!nova_arv)
        printf("\n/!\\Erro: Algum erro ocorreu durante a remoção deste nó.\n");
    else
        a = nova_arv;

    return a;
}
TAG *form_destruir(TAG *a)
{
    if (alert_se_vazia(a))
        return a;

    char op;
    printf("Você realmente deseja destruir a árvore inteira? (y/n):\n");
    scanf(" %c", &op);

    if (op == 'y')
        a = destroi(a);
    return a;
}

TAGNO *form_alterar_dim_fig(TAGNO *no)
{
    if (no->info)
    {
        if (strcmp(no->info->tipo, "CIR") == 0)
            no->info->figura = form_altera_cir((TCirc *)no->info->figura);
        else if (strcmp(no->info->tipo, "QUA") == 0)
            no->info->figura = form_altera_qua((TQuad *)no->info->figura);
        else if (strcmp(no->info->tipo, "RET") == 0)
            no->info->figura = form_altera_ret((TRetg *)no->info->figura);
        else if (strcmp(no->info->tipo, "TRA") == 0)
            no->info->figura = form_altera_tra((TTrap *)no->info->figura);
        else if (strcmp(no->info->tipo, "TRI") == 0)
            no->info->figura = form_altera_tri((TTria *)no->info->figura);
        else
            printf("\n/!\\Erro, figura não definida.\n");
    }
    else
    {
        printf("\n/!\\Erro, este nó (%d) não possui a info (informação).\n", no->id);
    }

    return no;
}

static TAVL *form_transf_avl_aux(TAVL *avl, TAGNO *no)
{
    TAGNO *p;
    for (p = no; p; p=p->irmao)
    {
        avl = insere_avl(avl, p->id, p->info);
        avl = form_transf_avl_aux(avl, p->filho);
    }
    return avl;
}

void form_transf_avl(TAG *a)
{

    if (alert_se_vazia(a))
        return;
    TAVL *avl = NULL;
    avl = form_transf_avl_aux(avl, a->raiz);
    imprime_avl(avl);

    // fazer menu de controle
}
void form_transf_arvb(TAG *a)
{
    if (alert_se_vazia(a))
        return;
}

void form_imprime_figura(TNOFIG *no)
{

    if (no)
    {
        if (strcmp(no->tipo, "CIR") == 0)
            imprime_circ((TCirc *)no->figura);
        else if (strcmp(no->tipo, "QUA") == 0)
            imprime_quad((TQuad *)no->figura);
        else if (strcmp(no->tipo, "RET") == 0)
            imprime_retg((TRetg *)no->figura);
        else if (strcmp(no->tipo, "TRA") == 0)
            imprime_trap((TTrap *)no->figura);
        else if (strcmp(no->tipo, "TRI") == 0)
            imprime_tria((TTria *)no->figura);
        else
        {
            printf("\n/!\\Erro: figura não encontrada.\n");
            return;
        }
    }
}