#include <stdio.h>
#include <stdlib.h>

#include "arvb.h"

// #define t 2

TAB *cria_arvb(int t)
{
  TAB *novo = (TAB *)malloc(sizeof(TAB));
  novo->nchaves = 0;
  novo->chave = (int *)malloc(sizeof(int *) * ((t * 2) - 1));
  novo->info = (TNOFIG **)malloc(sizeof(TNOFIG *) * ((t * 2) - 1));
  novo->folha = 1;
  novo->filho = (TAB **)malloc(sizeof(TAB *) * t * 2);
  int i;
  for (i = 0; i < (t * 2); i++)
    novo->filho[i] = NULL;
  return novo;
}

TAB *libera_arvb(TAB *a)
{
  if (a)
  {
    if (!a->folha)
    {
      int i;
      for (i = 0; i <= a->nchaves; i++)
        libera_arvb(a->filho[i]);
    }
    free(a->chave);
    int i;
    for (i = 0; i < a->nchaves; i++)
      libera_no_figura(a->info[i]);
    free(a->info);
    free(a->filho);
    free(a);
    return NULL;
  }
  return NULL;
}

void imprime_arvb(TAB *a, int andar)
{
  if (a)
  {
    int i, j;
    for (i = 0; i <= a->nchaves - 1; i++)
    {
      imprime_arvb(a->filho[i], andar + 1);
      for (j = 0; j <= andar; j++)
        printf("   ");
      printf("%3d|%3s\n", a->chave[i], a->info[i]->tipo);
    }
    imprime_arvb(a->filho[i], andar + 1);
  }
}

TAB *busca_arvb(TAB *x, int ch)
{
  TAB *resp = NULL;
  if (!x)
    return resp;
  int i = 0;
  while (i < x->nchaves && ch > x->chave[i])
    i++;
  if (i < x->nchaves && ch == x->chave[i])
    return x;
  if (x->folha)
    return resp;
  return busca_arvb(x->filho[i], ch);
}

TAB *inicializa_arvb()
{
  return NULL;
}

TAB *divisao_arvb(TAB *x, int i, TAB *y, int t)
{
  TAB *z = cria_arvb(t);
  z->nchaves = t - 1;
  z->folha = y->folha;
  int j;
  for (j = 0; j < t - 1; j++)
  {
    z->chave[j] = y->chave[j + t];
    z->info[j] = y->info[j + t];
  }
  if (!y->folha)
  {
    for (j = 0; j < t; j++)
    {
      z->filho[j] = y->filho[j + t];
      y->filho[j + t] = NULL;
    }
  }
  y->nchaves = t - 1;
  for (j = x->nchaves; j >= i; j--)
    x->filho[j + 1] = x->filho[j];
  x->filho[i] = z;
  for (j = x->nchaves; j >= i; j--){
    x->chave[j] = x->chave[j - 1];
    x->info[j] = x->info[j - 1];
  }
  x->chave[i - 1] = y->chave[t - 1];
  x->info[i - 1] = y->info[t - 1];
  x->nchaves++;
  return x;
}

TAB *insere_nao_completo_arvb(TAB *x, int k, TNOFIG *info, int t)
{
  int i = x->nchaves - 1;
  if (x->folha)
  {
    while ((i >= 0) && (k < x->chave[i]))
    {
      x->chave[i + 1] = x->chave[i];
      x->info[i + 1] = x->info[i];
      i--;
    }
    x->chave[i + 1] = k;
    x->info[i + 1] = info;
    x->nchaves++;
    return x;
  }
  while ((i >= 0) && (k < x->chave[i]))
    i--;
  i++;
  if (x->filho[i]->nchaves == ((2 * t) - 1))
  {
    x = divisao_arvb(x, (i + 1), x->filho[i], t);
    if (k > x->chave[i])
      i++;
  }
  x->filho[i] = insere_nao_completo_arvb(x->filho[i], k, info, t);
  return x;
}

TAB *insere_arvb(TAB *T, int k, TNOFIG *info, int t)
{
  if (busca_arvb(T, k))
    return T;
  if (!T)
  {
    T = cria_arvb(t);
    T->chave[0] = k;
    T->info[0] = info;
    T->nchaves = 1;
    return T;
  }
  if (T->nchaves == (2 * t) - 1)
  {
    TAB *S = cria_arvb(t);
    S->nchaves = 0;
    S->folha = 0;
    S->filho[0] = T;
    S = divisao_arvb(S, 1, T, t);
    S = insere_nao_completo_arvb(S, k, info, t);
    return S;
  }
  T = insere_nao_completo_arvb(T, k, info, t);
  return T;
}

TAB *remover_arvb(TAB *arv, int ch, int t)
{
  if (!arv)
    return arv;
  int i;
  printf("Removendo %d...\n", ch);
  for (i = 0; i < arv->nchaves && arv->chave[i] < ch; i++)
    ;
  if (i < arv->nchaves && ch == arv->chave[i])
  { //CASOS 1, 2A, 2B e 2C
    if (arv->folha)
    { //CASO 1
      printf("\nCASO 1\n");
      int j;
      for (j = i; j < arv->nchaves - 1; j++){
        arv->chave[j] = arv->chave[j + 1];
        arv->info[j] = arv->info[j + 1];
      }
      arv->nchaves--;
      return arv;
    }
    if (!arv->folha && arv->filho[i]->nchaves >= t)
    { //CASO 2A
      printf("\nCASO 2A\n");
      TAB *y = arv->filho[i]; //Encontrar o predecessor k' de k na árvore com raiz em y
      while (!y->folha)
        y = y->filho[y->nchaves];
      int temp = y->chave[y->nchaves - 1];
      TNOFIG* temp_info = y->info[y->nchaves - 1];      
      arv->filho[i] = remover_arvb(arv->filho[i], temp, t);
      //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i] = temp;
      arv->info[i] = temp_info;
      return arv;
    }
    if (!arv->folha && arv->filho[i + 1]->nchaves >= t)
    { //CASO 2B
      printf("\nCASO 2B\n");
      TAB *y = arv->filho[i + 1]; //Encontrar o sucessor k' de k na árvore com raiz em y
      while (!y->folha)
        y = y->filho[0];
      int temp = y->chave[0];
      TNOFIG* temp_info = y->info[0];
      y = remover_arvb(arv->filho[i + 1], temp, t); //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i] = temp;
      arv->info[i] = temp_info;
      return arv;
    }
    if (!arv->folha && arv->filho[i + 1]->nchaves == t - 1 && arv->filho[i]->nchaves == t - 1)
    { //CASO 2C
      printf("\nCASO 2C\n");
      TAB *y = arv->filho[i];
      TAB *z = arv->filho[i + 1];
      y->chave[y->nchaves] = ch; //colocar ch ao final de filho[i]
      ///////y->info[y->nchaves] = ???; //O que coloca aqui?
      int j;
      for (j = 0; j < t - 1; j++){ //juntar chave[i+1] com chave[i]
        y->chave[t + j] = z->chave[j];
        y->info[t + j] = z->info[j];
      }
      for (j = 0; j <= t; j++) //juntar filho[i+1] com filho[i]
        y->filho[t + j] = z->filho[j];
      y->nchaves = 2 * t - 1;
      for (j = i; j < arv->nchaves - 1; j++){ //remover ch de arv
        arv->chave[j] = arv->chave[j + 1];
        arv->info[j] = arv->info[j + 1];
      }
      for (j = i + 1; j <= arv->nchaves; j++) //remover ponteiro para filho[i+1]
        arv->filho[j] = arv->filho[j + 1];
      arv->filho[j] = NULL; //Campello
      arv->nchaves--;
      arv->filho[i] = remover_arvb(arv->filho[i], ch, t);
      return arv;
    }
  }

  TAB *y = arv->filho[i], *z = NULL;
  if (y->nchaves == t - 1)
  { //CASOS 3A e 3B
    if ((i < arv->nchaves) && (arv->filho[i + 1]->nchaves >= t))
    { //CASO 3A
      printf("\nCASO 3A: i menor que nchaves\n");
      z = arv->filho[i + 1];
      y->chave[t - 1] = arv->chave[i]; //dar a y a chave i da arv
      y->info[t - 1] = arv->info[i]; //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i] = z->chave[0]; //dar a arv uma chave de z
      arv->info[i] = z->info[0]; //dar a arv uma chave de z
      int j;
      for (j = 0; j < z->nchaves - 1; j++){ //ajustar chaves de z
        z->chave[j] = z->chave[j + 1];
        z->info[j] = z->info[j + 1];
      }
      //z->chave[j] = 0; Rosseti
      y->filho[y->nchaves] = z->filho[0]; //enviar ponteiro menor de z para o novo elemento em y
      for (j = 0; j < z->nchaves; j++)    //ajustar filhos de z
        z->filho[j] = z->filho[j + 1];
      z->nchaves--;
      arv->filho[i] = remover_arvb(arv->filho[i], ch, t);
      return arv;
    }
    if ((i > 0) && (!z) && (arv->filho[i - 1]->nchaves >= t))
    { //CASO 3A
      printf("\nCASO 3A: i igual a nchaves\n");
      z = arv->filho[i - 1];
      int j;
      for (j = y->nchaves; j > 0; j--){ //encaixar lugar da nova chave
        y->chave[j] = y->chave[j - 1];
        y->info[j] = y->info[j - 1];
      }
      for (j = y->nchaves + 1; j > 0; j--) //encaixar lugar dos filhos da nova chave
        y->filho[j] = y->filho[j - 1];
      y->chave[0] = arv->chave[i - 1]; //dar a y a chave i da arv
      y->info[0] = arv->info[i - 1]; //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i - 1] = z->chave[z->nchaves - 1]; //dar a arv uma chave de z
      arv->info[i - 1] = z->info[z->nchaves - 1]; //dar a arv uma chave de z
      y->filho[0] = z->filho[z->nchaves];           //enviar ponteiro de z para o novo elemento em y
      z->nchaves--;
      arv->filho[i] = remover_arvb(y, ch, t);
      return arv;
    }
    if (!z)
    { //CASO 3B
      if (i < arv->nchaves && arv->filho[i + 1]->nchaves == t - 1)
      {
        printf("\nCASO 3B: i menor que nchaves\n");
        z = arv->filho[i + 1];
        y->chave[t - 1] = arv->chave[i]; //pegar chave [i] e coloca ao final de filho[i]
        y->info[t - 1] = arv->info[i]; //pegar chave [i] e coloca ao final de filho[i]
        y->nchaves++;
        int j;
        for (j = 0; j < t - 1; j++)
        {
          y->chave[t + j] = z->chave[j]; //passar filho[i+1] para filho[i]
          y->info[t + j] = z->info[j]; //passar filho[i+1] para filho[i]
          y->nchaves++;
        }
        if (!y->folha)
        {
          for (j = 0; j < t; j++)
          {
            y->filho[t + j] = z->filho[j];
          }
        }
        for (j = i; j < arv->nchaves - 1; j++)
        { //limpar referências de i
          arv->chave[j] = arv->chave[j + 1];
          arv->info[j] = arv->info[j + 1];
          arv->filho[j + 1] = arv->filho[j + 2];
        }
        arv->nchaves--;
        arv = remover_arvb(arv, ch, t);
        return arv;
      }
      if ((i > 0) && (arv->filho[i - 1]->nchaves == t - 1))
      {
        printf("\nCASO 3B: i igual a nchaves\n");
        z = arv->filho[i - 1];
        if (i == arv->nchaves){
          z->chave[t - 1] = arv->chave[i - 1]; //pegar chave[i] e poe ao final de filho[i-1]
          z->info[t - 1] = arv->info[i - 1]; //pegar chave[i] e poe ao final de filho[i-1]
        }
        else{
          z->chave[t - 1] = arv->chave[i]; //pegar chave [i] e poe ao final de filho[i-1]
          z->info[t - 1] = arv->info[i]; //pegar chave [i] e poe ao final de filho[i-1]
        }
        z->nchaves++;
        int j;
        for (j = 0; j < t - 1; j++)
        {
          z->chave[t + j] = y->chave[j]; //passar filho[i+1] para filho[i]
          z->info[t + j] = y->info[j]; //passar filho[i+1] para filho[i]
          z->nchaves++;
        }
        if (!z->folha)
        {
          for (j = 0; j < t; j++)
          {
            z->filho[t + j] = y->filho[j];
          }
        }
        arv->nchaves--;
        arv->filho[i - 1] = z;
        arv = remover_arvb(arv, ch, t);
        return arv;
      }
    }
  }
  arv->filho[i] = remover_arvb(arv->filho[i], ch, t);
  return arv;
}

TAB *retira_arvb(TAB *arv, int k, int t)
{
  if (!arv || !busca_arvb(arv, k))
    return arv;
  return remover_arvb(arv, k, t);
}

// int main(int argc, char *argv[]){
//   TAB * arvore = inicializa_arvb();
//   int num = 0, from, to;
//   while(num != -1){
//     printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
//     scanf("%i", &num);
//     if(num == -9){
//       scanf("%d", &from);
//       arvore = retira_arvb(arvore, from, t);
//       imprime_arvb(arvore,0);
//     }
//     else if(num == -1){
//       printf("\n");
//       imprime_arvb(arvore,0);
//       libera_arvb(arvore);
//       return 0;
//     }
//     else if(!num){
//       printf("\n");
//       imprime_arvb(arvore,0);
//     }
//     else arvore = insere_arvb(arvore, num, t);
//     printf("\n\n");
//   }
// }