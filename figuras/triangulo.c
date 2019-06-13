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
    return f->base * f->altura /2.0f;
}

void imprime_tria(TTria* f) {
    printf("Triângulo: \n");
    printf("base:   %f\n", f->base);
    printf("altura: %f\n", f->altura);
    printf("área:   %f\n", area_tria(f));
}