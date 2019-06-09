#include <stdlib.h>
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