#include <stdlib.h>
#include "circulo.h"

TCirc* criar_circ(float raio){
    TCirc* result = (TCirc*) malloc(sizeof(TCirc));
    result->raio = raio;
    return result;
}

TCirc* alterar_circ(float raio){
    TCirc* result = NULL;
    return result;
}

float area_circ(TCirc* fig){
    float result = 0.0;
    return result;
}