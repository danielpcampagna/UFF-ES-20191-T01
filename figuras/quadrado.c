#include <stdlib.h>
#include <math.h>

#include "quadrado.h"

TQuad* criar_quad(float lado){
    TQuad* result = (TQuad*) malloc(sizeof(TQuad));
    result->lado = lado;
    return result;
}

TQuad* alterar_quad(TQuad* f, float lado){
    f->lado = lado;
    return f;
}

float area_quad(TQuad* f){
    return pow(f->lado, 2);
}