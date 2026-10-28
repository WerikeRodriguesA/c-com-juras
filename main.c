#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "cincurferencia.h"

int main(void) {
    float x, y, r;
    int opcao;

    printf("Centro (x y) e raio: ");
    if (scanf("%f %f %f", &x, &y, &r) != 3 || r <= 0) return 1;

    Circulo* c = cir_cria(x, y, r);
    if (!c) return 1;

    do {
        printf("\n1-Area | 2-Circunferencia | 3-Ponto interior | 0-Sair: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Area: %.2f\n", cir_area(c));
        } 
        else if (opcao == 2) {
            // Se possuir a funcao cir_circunferencia na struct use-a, senao:
            printf("Circunferencia: %.2f\n", 2 * 3.14159265f * r); 
        } 
        else if (opcao == 3) {
            float px, py;
            printf("Ponto (x y): ");
            scanf("%f %f", &px, &py);

            Ponto* p = pto_cria(px, py);
            if (p) {
                printf(cir_interior(c, p) ? "Dentro\n" : "Fora\n");
                pto_libera(p);
            }
        }
    } while (opcao != 0);

    cir_libera(c);
    return 0;
}