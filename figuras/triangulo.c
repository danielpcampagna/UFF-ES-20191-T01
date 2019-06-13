#include <stdlib.h>
#include <stdio.h>
#include "triangulo.h"

TTria* criar_tria(float base, float altura){
    TTria* result = (TTria*) malloc(sizeof(TTria));
    result->base = base;
    result->altura = altura;
    return result;
}

TTria* alterar_tria(TTria* f, float base, float altura){
    f->base = base;
    f->altura = altura;
    return f;
}

float area_tria(TTria* f){
    return f->base * f->base /2.0f;
}

void imprime_tria(TTria* f) {
    printf("Triângulo: \n");
    printf("base: %f", f->base);
    printf("altura: %f", f->altura);
    printf("área: %f", area_tria(f));
}