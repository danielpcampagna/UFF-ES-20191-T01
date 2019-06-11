/******************************************************************************

                            Online C Debugger.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Debug" button to debug program.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct arvore_generica
{
  int id;
  char *tipo;
  struct arvore_generica *filho, *irmao;
  void *figura;
} TAG;



TAG *cria ();
static TAG *busca (TAG * a, int x);
void insere (TAG * a, TAG * p, int pai);
TAG *retira (TAG * a, int x);
static void imprime (TAG* a);
//void remove(int id);
//void destroi (TAG* a);arvg


TAG *
cria ()
{
  TAG *p = malloc (sizeof (TAG));
  return NULL;
}

static TAG *
busca (TAG * a, int x)
{
  if (a == NULL)
    return NULL;

  else if (a->id == x)
    return a;

  else
    {
      TAG *p = busca (a->irmao, x);
      if (p != NULL)
	return p;
      else
	return busca (a->filho, x);
    }

}


void
insere (TAG * a, TAG * no, int pai)
{

  if (a != NULL)
    {
      TAG *no = malloc (sizeof (TAG));
      TAG *p = busca (a, pai);
      if (p->filho == NULL)
	{
	  no->filho = NULL;
	  no->irmao = NULL;
	  p->filho = no;
	}
      else
	{
	  p = p->filho;
	  while (p)
	    {
	      p = p->irmao;
	    }
	  no->filho = NULL;
	  no->irmao = NULL;
	  p->irmao = no;
	}

    }

}

/*
TAG* retira(TAG *a, int x) {


    // caso 1 nao tem  arvore

    if (!a) return NULL;

    //caso 2 remover a raiz e so existe ela

      if ((a->id=x ) && (a->filho = NULL)
             return NULL;


    //caso 3 remover a raiz que tem filho(s)


    if ((a->id=x ) && (a->filho ^= NULL)) {
        a=a->filho;
        if (a->filho->id < a->irmao->id) {
            a->filho->irmao=a->irmao;

        }
    }
TAG* pai= malloc(sizeof(TAG));
TAG* irmant= malloc(sizeof(TAG));
a

    TAG* result = NULL;
    return result;
}
*/

    static void imprime(Arv* a){
        printf("<");
        if (a!=NULL){
            printf("%d", a1->id);
        imprime(a->filho);
        imprime(a->irmao);
        }
        printf(">");
    }

int
main ()
{


  return 0;
}
