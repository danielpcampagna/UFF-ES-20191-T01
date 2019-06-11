#include<stdio.h>
#include<stdlib.h>

typedef struct arvg {
    int id;
    char *tipo;
    struct arvg *filho, *irmao;
    void *figura;
} TAG;



TAG* cria();
static TAG* busca(TAG* a, int x);
void insere(TAG* a, TAG* p, int pai);
//void remove(int id);
//void imprime (TAG* a);
//void destroi (TAG* a);


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

int main(){
return 0;
}







