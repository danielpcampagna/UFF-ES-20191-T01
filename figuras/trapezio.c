#include <stdlib.h>
#include <stdio.h>
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

void imprime_trap(TTrap* f) {
    printf("Trapézio: \n");
    printf("base maior: %f\n", f->base_maior);
    printf("base menor: %f\n", f->base_menor);
    printf("altura:     %f\n", f->altura);
    printf("área:       %f\n", area_trap(f));
}