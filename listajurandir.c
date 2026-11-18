#include <stdio.h>
#include "lista.h"

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

//1
int comprimento (Lista* l){
    Lista* p;
    int cont = 0;
    for ( p = l ; p != NULL; p=p->prox ) {
        cont++;
    }
    return cont;
}

// 2

int maiores(Lista* l, int n) {
    int contador = 0;
    Lista* atual = l;
    
    while (atual != NULL) {
        if (atual->info > n) {
            contador++;
        }
        atual = atual->prox; // Avança para o próximo nó
    }
    return contador;
}

//3

Lista* separa(Lista *l, int n) {
    Lista* atual = l;
    
    while (atual != NULL) {
        if (atual->info == n) {
            Lista* nova = atual->prox;
            atual->prox = NULL;
            return nova;
        }
        atual = atual->prox; // Avança para o proximo nó
    }
    return NULL;
}

//4
Lista* ultimo(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    Lista* atual = l;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    return atual;
}

//5
Lista* concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) {
        return l2;
    }
    Lista* atual = l1;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = l2;
    
    return l1;
}

//5
Lista* concatena(Lista* l1, Lista* l2) {
    Lista* atual = l1;
    
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = l2;
    return l1;
}