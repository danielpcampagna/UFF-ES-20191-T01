typedef struct triangulo {
    float base, altura;
} TTria;

TTria* criar_tria(float base, float altura);
TTria* alterar_tria(float base, float altura);
float area_tria(TTria* fig);