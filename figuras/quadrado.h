typedef struct quadrado {
    float lado;
} TQuad;

TQuad* criar_quad(float lado);
TQuad* alterar_quad(float lado);
float area_quad(TQuad* fig);