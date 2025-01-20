#include <stdio.h>

int main(){
    float n1, n2, resultado;
    char operador;
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("Escolha uma expressao (+, -, *, /): ");
    scanf("%s", &operador);

    switch (operador){
    case '+':
        resultado = n1 + n2;
        printf("%.2f + %.2f = %.2f", n1, n2, resultado);
        break;
    case '-':
        resultado = n1 - n2;
        printf("%.2f - %.2f = %.2f", n1, n2, resultado);
        break;
    case '*':
        resultado = n1 * n2;
        printf("%.2f * %.2f = %.2f", n1, n2, resultado);
        break;
    case '/':
        resultado = n1 / n2;
        printf("%.2f / %.2f = %.2f", n1, n2, resultado);
        break;
    default:
        printf("Erro!");
        break;
    }

    return 0;
}