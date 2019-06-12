#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "avl.h"

void libera_avl(TAVL* t){
    if( t != NULL ){
        libera_avl( t->esq );
        libera_avl( t->dir );
        free( t );
    }
}


TAVL* busca_avl(int e, TAVL* t ){
    if( t == NULL ) return NULL;
    if( e < t->info ) return busca_avl( e, t->esq );
    if( e > t->info ) return busca_avl( e, t->dir );
    return t;
}


static int calc_alt( TAVL* n ){
    if( n == NULL ) return -1;
    return n->alt;
}


static int max( int l, int r){
    return l > r ? l: r;
}


static TAVL* rot_dir( TAVL* k2 ){
    TAVL* k1 = NULL;
    k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    k2->alt = max( calc_alt( k2->esq ), calc_alt( k2->dir ) ) + 1;
    k1->alt = max( calc_alt( k1->esq ), k2->alt ) + 1;
    return k1; /* nova raiz */
}


static TAVL* rot_esq( TAVL* k1 ){
    TAVL* k2;
    k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
    k1->alt = max( calc_alt( k1->esq ), calc_alt( k1->dir ) ) + 1;
    k2->alt = max( calc_alt( k2->dir ), k1->alt ) + 1;
    return k2;  /* nova raiz */
}


static TAVL* rot_esq_dir( TAVL* k3 ){
    k3->esq = rot_esq( k3->esq );
    return rot_dir( k3 );
}


static TAVL* rot_dir_esq( TAVL* k1 ){
    k1->dir = rot_dir( k1->dir );
    return rot_esq( k1 );
}


TAVL* insere_avl(int e, TAVL* t ){
    if( t == NULL ){
        t = (TAVL*)malloc(sizeof(TAVL));
        if( t == NULL ){
            fprintf (stderr, "Out of memory!!! (insere)\n");
            exit(1);
        }
        else{
            t->info = e;
            t->alt = 0;
            t->esq = t->dir = NULL;
        }
    }
    else if( e < t->info ){
        t->esq = insere_avl( e, t->esq );
        if( calc_alt( t->esq ) - calc_alt( t->dir ) == 2 )
            if( e < t->esq->info )
                t = rot_dir( t );
            else
                t = rot_esq_dir( t );
    }
    else if( e > t->info ){
        t->dir = insere_avl( e, t->dir );
        if( calc_alt( t->dir ) - calc_alt( t->esq ) == 2 )
            if( e > t->dir->info )
                t = rot_esq( t );
            else
                t = rot_dir_esq( t );
    }
    t->alt = max( calc_alt( t->esq ), calc_alt( t->dir ) ) + 1;
    return t;
}


int calc_alt_retira_avl(TAVL *T){
    int lh,rh;
    if(T==NULL) return(0);
    if(T->esq==NULL) lh=0;
    else lh=1+T->esq->alt;
    if(T->dir==NULL) rh=0;
    else rh=1+T->dir->alt;
    if(lh>rh) return(lh);
    return(rh);
}


int FB_avl(TAVL *T){
    int lh,rh;
    if(T==NULL) return(0);
    if(T->esq==NULL) lh=0;
    else lh=1+T->esq->alt;
    if(T->dir==NULL) rh=0;
    else rh=1+T->dir->alt;
    return(lh-rh);
}


static void imprime_aux(TAVL *a, int andar){
  if(a){
      int j;
      imprime_aux(a->esq,andar+1);
      for(j=0; j<=andar; j++) printf("   ");
      printf("%d\n", a->info);
      imprime_aux(a->dir,andar+1);
  }
}


void imprime_avl(TAVL *a){
  imprime_aux(a, 1);
}


TAVL * retira_avl(int x, TAVL *T){       
    TAVL *p;
    if(T==NULL)
        return NULL;
    else
        if(x > T->info){
            T->dir=retira_avl(x,T->dir);
            if(FB_avl(T)==2)
                if(FB_avl(T->esq)>=0)
                    T=rot_dir(T);
                else
                    T=rot_esq_dir(T);
        }
        else
            if(x<T->info){
                    T->esq=retira_avl(x,T->esq);
                    if(FB_avl(T)==-2)//Rebalance during windup
                        if(FB_avl(T->dir)<=0)
                            T=rot_esq(T);
                        else
                            T=rot_dir_esq(T);
            }
            else{
                //info to be deleted is found
                  if(T->esq != NULL){
                      p=T->esq;
                      while(p->dir != NULL) p=p->dir;
                      T->info=p->info;
                      T->esq=retira_avl(p->info, T->esq);
                      if(FB_avl(T)== -2)//Rebalance during windup
                        if(FB_avl(T->dir)<=0)
                            T=rot_esq(T);
                        else
                            T=rot_dir_esq(T);
                  }
                  else{
                      TAVL *x = T;
                      T = T->dir;
                      free(x);
                      return(T);
                  }
            }
    T->alt=calc_alt_retira_avl(T);
    return(T);
}


static int min( int l, int r){
    return l < r ? l: r;
}


// int main(int argc, char *argv[]){
//   TAVL * arvore = NULL;
//   int num = 0, from, to;
//   while(num != -1){
//     printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
//     scanf("%i", &num);
//     if(num == -9){
//       scanf("%d", &from);
//       arvore = retira_avl(from, arvore);
//       imprime_avl(arvore);
//     }
//     else if(num == -1){
//       printf("\n");
//       imprime_avl(arvore);
//       libera_avl(arvore);
//       return 0;
//     }
//     else if(!num){
//       printf("\n");
//       imprime_avl(arvore);
//     }
//     else arvore = insere_avl(num, arvore);
//     printf("\n\n");
//   }
// }