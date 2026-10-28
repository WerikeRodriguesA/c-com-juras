#include <stdio.h>

int main() {
    int valor = 42;
    int *novovalor = &valor;       

    printf("a) Valor da variável: %d\n", valor);
    scanf("Please, digite o novo valor %d", novovalor);

    printf("c) Valor armazenado no ponteiro: %d\n", *novovalor);

    return 0;
}