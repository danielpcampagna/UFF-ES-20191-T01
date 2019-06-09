typedef struct quadrado {
    float lado;
} TQuad;

TQuad* criar_quad(float lado);
TQuad* alterar_quad(TQuad* f, float lado);
float area_quad(TQuad* f);