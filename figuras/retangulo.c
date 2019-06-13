#include <stdlib.h>
#include <stdio.h>
#include "retangulo.h"

TRetg* criar_retg(float base, float altura){
    TRetg* result = (TRetg*) malloc(sizeof(TRetg));
    result->base = base;
    result->altura = altura;
    return result;
}

TRetg* alterar_retg(TRetg* f, float base, float altura){
    f->base = base;
    f->altura = altura;
    return f;
}

float area_retg(TRetg* f){
    return f->base * f->altura;
}

void imprime_retg(TRetg* f) {
    printf("Retângulo: \n");
    printf("base: %f\n", f->base);
    printf("altura: %f\n", f->altura);
    printf("área: %f\n", area_retg(f));
}