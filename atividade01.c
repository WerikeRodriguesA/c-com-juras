#include <stdio.h>

int main() {
    int valor = 42;
    int *ptr = &valor;       

    printf("a) Valor da variável: %d\n", valor);

    printf("b) Endereço da variável: %p\n", (void*)&valor);

    printf("c) Valor armazenado no ponteiro: %p\n", (void*)ptr);

    return 0;
}