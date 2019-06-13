#include <stdio.h>
#include <ctype.h>
#include "../estruturas/arvore_generica.h"
#include "../estruturas/no_figura.h"

void form_carrega_arquivo();
void form_inicio(TAG *a);
void form_altera_circ(TAG* t);
void form_acessa_figura(TAG *a);
void form_imprimir(TAG *a);
TAG *form_inserir(TAG *a);
TAG *form_retirar(TAG *a, int id);
TAG *form_destruir(TAG *a);
TAGNO *form_alterar_dim_fig(TAGNO *no);
void form_imprime_figura(TNOFIG *no);

void form_transf_avl(TAG *a);
void form_transf_arvb(TAG *a);

/////////

// static TCirc *form_altera_cir(TCirc *f);
// static TQuad *form_altera_qua(TQuad *f);
// static TRetg *form_altera_ret(TRetg *f);
// static TTrap *form_altera_tra(TTrap *f);
// static TTria *form_altera_tri(TTria *f);
// static TCirc *form_cria_cir();
// static TQuad *form_cria_qua();
// static TRetg *form_cria_ret();
// static TTrap *form_cria_tra();
// static TTria *form_cria_tri();