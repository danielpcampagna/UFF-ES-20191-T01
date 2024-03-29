#ifndef TRAPEZIO_H
#define TRAPEZIO_H

typedef struct trapezio {
    float base_maior, base_menor, altura;
} TTrap;

TTrap* criar_trap(float base_maior, float base_menor, float altura);
TTrap* alterar_trap(TTrap* f, float base_maior, float base_menor, float altura);
float area_trap(TTrap* f);
void imprime_trap(TTrap* f);

#endif // TRAPEZIO_H