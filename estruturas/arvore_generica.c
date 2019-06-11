#include "arvore_generica.h"


TAG* cria(){
	TAG* p= malloc(sizeof(TAG));
	return NULL;
}




static TAG* busca(TAG* a, int x){
if (a==NULL) return NULL;

else if (a->id==x) return a;

else {
TAG* p= busca(a->irmao, x);
if (p != NULL)
return p;
else return busca(a->filho, x);
}

}




void insere(TAG* a, TAG* no, int pai ){

if (a!=NULL) {
	TAG* no= malloc(sizeof(TAG));
	TAG* p=busca(a, pai);
	if (p->filho==NULL) {
		no->filho=NULL;
		no->irmao=NULL;
		p->filho=no;
	}
	else {
		p=p->filho;
		while (p) {
			p=p->irmao;
		}
		no->filho=NULL;
		no->irmao=NULL;
		p->irmao=no;
	}

}

}



void imprime(TAG *t){
     TAG* result = NULL;
    return result;
}



TAG* retira(TAG *t, int id) {
    TAG* result = NULL;
    return result;
}

void destroi(TAG *t) {
    return;
}

TAG* altera(TAG *t, int id, void *altera_fig(), ...){
    TAG* result = NULL;
    return result;
}
