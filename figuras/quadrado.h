#ifndef QUADRADO_H
#define QUADRADO_H

typedef struct quadrado {
    float lado;
} TQuad;

TQuad* criar_quad(float lado);
TQuad* alterar_quad(TQuad* f, float lado);
float area_quad(TQuad* f);
void imprime_quad(TQuad* f);

#endif //QUADRADO_H