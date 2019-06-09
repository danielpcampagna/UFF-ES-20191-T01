#include <stdlib.h>
#include "trapezio.h"

TTrap* criar_trap(float base_maior, float base_menor, float altura){
    TTrap* result = (TTrap*) malloc(sizeof(TTrap));
    result->base_maior = base_maior;
    result->base_menor = base_menor;
    result->altura = altura;
    return result;
}

TTrap* alterar_trap(TTrap* f, float base_maior, float base_menor, float altura){
    f->base_maior = base_maior;
    f->base_menor = base_menor;
    f->altura = altura;
    return f;
}

float area_trap(TTrap* f){
    return ((f->base_maior + f->base_menor) * f->altura) / 2.0f;
}