#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    float x;
    float y;
};

Ponto* pto_cria (float x, float y){
    Ponto* p= (Ponto*) malloc (sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

void pto_libera (Ponto* p){
    free (p);
}

float pto_distancia(Ponto* p1, Ponto* p2){
    float cx = p2->x - p1->x;
    float cy = p2->y - p1->y;

    return sqrt((cx * cx) + (cy * cy));

}

void pto_atribui (Ponto* p, float x, float y){
    p->x =x;
    p->y =y;

}
