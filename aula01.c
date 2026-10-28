#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
    
    printf("Digite a operacao (+, -, *, /): ");
    scanf(" %c", &operacao);
    
    if (operacao == '+') {
        resultado = num1 + num2;
    }
    else if (operacao == '-') {
        resultado = num1 - num2;
    }
    else if (operacao == '*') {
        resultado = num1 * num2;
    }
    else if (operacao == '/') {
        if (num2 != 0) {
            resultado = num1 / num2;
        }
        else {
            printf("Erro: divisao por zero!\n");
            return 1;
        }
    }
    else {
        printf("Operacao invalida!\n");
        return 1;
    }
    
    printf("\nResultado: %.2f %c %.2f = %.2f\n", num1, operacao, num2, resultado);
    
    return 0;
}
