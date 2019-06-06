#include<stdarg.h>

typedef struct arvore_generica {
    int id;
    char *tipo;
    struct arvore_generica *filho, *irmao;
    void *figura;
} TAG;

TAG* criar_arv_gen(void);
TAG* buscar_arv_gen(TAG *t, int id);
void imprimir_arv_gen(TAG *t);
TAG* inserir_arv_gen(TAG *t, char* tipo, TAG *pai, void *figura);
TAG* retirar_arv_gen(TAG *t, int id);
void destruir_arv_gen(TAG *t);
TAG* alterar_figura_arv_gen(TAG *t, int id, void *func_alterar_figura_arv_gen(), ...);
//TAG* inserir_arv_gen(TAG *t, int id, char* tipo, TAG *pai);
