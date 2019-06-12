#ifndef TAB_H
#define TAB_H

typedef struct ArvB
{
  int nchaves, folha, *chave;
  struct ArvB **filho;
} TAB;

TAB *cria_arvb(int t);
TAB *libera_arvb(TAB *a);
void imprime_arvb(TAB *a, int andar);
TAB *busca_arvb(TAB *x, int ch);
TAB *inicializa_arvb();
TAB *divisao_arvb(TAB *x, int i, TAB *y, int t);
TAB *insere_nao_completo_arvb(TAB *x, int k, int t);
TAB *insere_arvb(TAB *T, int k, int t);
TAB *remover_arvb(TAB *arv, int ch, int t);
TAB *retira_arvb(TAB *arv, int k, int t);

#endif //TAB_H