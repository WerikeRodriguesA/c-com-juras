#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct lista { 
    int info;
    lista* prox;
    lista2* prox;
    lista2* l2; 
};


Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}


void lista_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d \n", p->info);
    }
}

int lista_vazia(Lista* l) {
    return (l == NULL);
}


Lista* lista_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p; 
        }
    }
    return NULL; 
}

// 1 cum
int comprimento(Lista* l) {
    Lista* p;
    int cont = 0;
    for (p = l; p != NULL; p = p->prox) {
        cont++;
    }
    return cont;
}

// 2 biggrs
int maiores(Lista* l, int n) {
    int contador = 0;
    Lista* atual = l;
    
    while (atual != NULL) {
        if (atual->info > n) {
            contador++;
        }
        atual = atual->prox; 
    }
    return contador;
}

// 3 separar 
Lista* separa(Lista* l, int n) {
    Lista* atual = l;
    
    while (atual != NULL) {
        if (atual->info == n) {
            Lista* nova = atual->prox;
            atual->prox = NULL;
            return nova;
        }
        atual = atual->prox;
    }
    return NULL;
}

// 4 achar o último elemento
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

// 5
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