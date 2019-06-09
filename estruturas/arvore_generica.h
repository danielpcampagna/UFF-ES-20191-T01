#include<stdarg.h>

typedef struct arvore_generica {
    int id; // id do nó atual.
    char *tipo; // tipo da figura (e.g. 'QUA').
    struct arvore_generica *filho, *irmao; 
    /*
        - filho: ponteiro para o primeiro filho;
        - irmao: ponteiro para o próximo irmão;
    */
    void *figura; // ponteiro para a figura.
} TAG;

TAG* criar_arv_gen(void);
TAG* buscar_arv_gen(TAG *t, int id);
void imprimir_arv_gen(TAG *t);
TAG* inserir_arv_gen(TAG *t, char* tipo, TAG *pai, void *figura);
TAG* retirar_arv_gen(TAG *t, int id);
void destruir_arv_gen(TAG *t);
TAG* alterar_figura_arv_gen(TAG *t, int id, void *func_alterar_figura_arv_gen(), ...);
//TAG* inserir_arv_gen(TAG *t, int id, char* tipo, TAG *pai);
