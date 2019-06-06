typedef struct circulo {
    float raio;
} TCirc;

TCirc* criar_circ(float raio);
TCirc* alterar_circ(float raio);
float area_circ(TCirc* fig);
char* to_string(TCirc* fig);