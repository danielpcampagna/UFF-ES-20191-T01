#ifndef RETANGULO_H
#define RETANGULO_H

typedef struct retangulo {
    float base, altura;
} TRetg;

TRetg* criar_retg(float base, float altura);
TRetg* alterar_retg(TRetg* f, float base, float altura);
float area_retg(TRetg* f);
void imprime_retg(TRetg* f);

#endif // RETANGULO_H