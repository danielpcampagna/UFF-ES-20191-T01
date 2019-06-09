#include<stdarg.h>

typedef struct arvore_n_aria {
    char **tipo; // lista com os tipos das figuras de cada chave (e.g. ['QUA', 'TRI', 'RET'])
    int nchaves, folha, *chave;
    /* 
        - nchaves: número de chaves no nó atual;
        - folha: informação 'booleana' que diz se é o nó atual é folha da árvore ou não;
        - chave: ponteiro para a lista de chaves;
    */
    struct arvore_n_aria **filho; // 
    void *figura;
} TAG;

TAG* criar_arv_n_aria(void);
TAG* buscar_arv_n_aria(TAG *t, int id);
void imprimir_arv_n_aria(TAG *t);
TAG* inserir_arv_n_aria(TAG *t, char* tipo, TAG *pai, void *figura);
TAG* retirar_arv_n_aria(TAG *t, int id);
void destruir_arv_n_aria(TAG *t);
TAG* alterar_figura_arv_n_aria(TAG *t, int id, void *func_alterar_figura_arv_n_aria(), ...);
//TAG* inserir_arv_n_aria(TAG *t, int id, char* tipo, TAG *pai);
