#ifndef TRIANGULO_H
#define TRIANGULO_H

typedef struct triangulo {
    float base, altura;
} TTria;

TTria* criar_tria(float base, float altura);
TTria* alterar_tria(TTria* f, float base, float altura);
float area_tria(TTria* f);

#endif // TRIANGULO_H