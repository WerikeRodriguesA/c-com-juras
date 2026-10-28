#include "ponto.h"

typedef struct  circulo Circulo;

Circulo* cir_cria (float x, float y, float z);

void cir_libera (Circulo* z);

float cir_area (Circulo* c);

int cir_interior (Circulo* c, Ponto* p);
