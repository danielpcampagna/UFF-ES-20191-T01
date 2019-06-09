#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

#include "circulo.h"

TCirc* criar_circ(float raio){
    TCirc* result = (TCirc*) malloc(sizeof(TCirc));
    result->raio = raio;
    return result;
}

TCirc* alterar_circ(TCirc* f, float raio){
    f->raio = raio;
    return f;
}

float area_circ(TCirc* f){
    return 2.0f * M_PI * f->raio;
}