#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct circulo {
    float raio;
} TCirc;

TCirc* criar_circ(float raio);
TCirc* alterar_circ(TCirc* f, float raio);
float area_circ(TCirc* f);
char* to_string(TCirc* f);

#endif //CIRCULO_H
