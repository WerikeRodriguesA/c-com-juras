#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"
typedef struct circulo Circulo;

struct circulo {
    Ponto* pCentral;
    float raio;
};

Circulo* cir_cria(float x, float y, float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    if (c == NULL) return NULL; // Verificação de memória
    
    c->pCentral = pto_cria(x, y);
    c->raio = r;
    return c;
}

void cir_libera(Circulo* c) {
    if (c != NULL) {
        pto_libera(c->pCentral); // Libera primeiro o ponto alocado internamente
        free(c);                 // Libera a estrutura do círculo
    }
}


float cir_area(Circulo* c) {
    if (c == NULL) return 0.0f;
    return M_PI * (c->raio * c->raio);
}

// 4. Verificar se Ponto está no Interior do Círculo
// Retorna 1 se estiver dentro ou na borda, e 0 se estiver fora.
int cir_interior(Circulo* c, Ponto* p) {
    if (c == NULL || p == NULL) return 0;

    float x_centro, y_centro, x_p, y_p;
    
    // Obtém as coordenadas do ponto central e do ponto testado
    pto_acessa(c->pCentral, &x_centro, &y_centro);
    pto_acessa(p, &x_p, &y_p);

    // Distância euclidiana entre o centro e o ponto
    float dx = x_p - x_centro;
    float dy = y_p - y_centro;
    float distancia = sqrtf(dx * dx + dy * dy);

    return (distancia <= c->raio);
}

int main(void) {
    // Exemplo de uso: Círculo no centro (0,0) com raio 5
    Circulo* c = cir_cria(0.0f, 0.0f, 5.0f);
    
    if (c == NULL) {
        printf("Erro ao alocar memória para o círculo.\n");
        return 1;
    }

    printf("Área do círculo: %.2f\n", cir_area(c));

    // Testando pontos no interior
    Ponto* p1 = pto_cria(2.0f, 2.0f);  // Dentro
    Ponto* p2 = pto_cria(10.0f, 10.0f); // Fora

    if (cir_interior(c, p1)) {
        printf("P1 está no interior do círculo.\n");
    } else {
        printf("P1 está fora do círculo.\n");
    }

    if (cir_interior(c, p2)) {
        printf("P2 está no interior do círculo.\n");
    } else {
        printf("P2 está fora do círculo.\n");
    }

    // Liberação de memória
    pto_libera(p1);
    pto_libera(p2);
    cir_libera(c);

    return 0;
}