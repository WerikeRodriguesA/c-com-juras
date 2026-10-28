#include <stdio.h>

int main(void) {
	double a, b, resultado;
	char operador;

	printf("Calculadora simples\n");
	printf("Digite uma operação (ex.: 10 + 5): ");

	if (scanf("%lf %c %lf", &a, &operador, &b) != 3) {
		printf("Entrada inválida.\n");
		return 1;
	}

	switch (operador) {
		case '+':
			resultado = a + b;
			break;
		case '-':
			resultado = a - b;
			break;
		case '*':
			resultado = a * b;
			break;
		case '/':
			if (b == 0) {
				printf("Erro: divisão por zero.\n");
				return 1;
			}
			resultado = a / b;
			break;
		default:
			printf("Operador inválido. Use +, -, * ou /.\n");
			return 1;
	}

	printf("Resultado: %.2f\n", resultado);
	return 0;
}
