#include <stdio.h>
#include <math.h>

int main() {
    printf("\n\nCalculador da distancia de um lancamento obliquo com altura inicial igual a 0\n\n");

    // Criando as variáveis e coletando as informações do usuário
    float velocidadeInicial;
    float anguloDeLancamento;
    float forcaDaGravidade = 9.81;

    printf("Digite a velocidade inicial (m/s): ");
    scanf("%f", &velocidadeInicial);

    printf("Digite o angulo de lancamento: ");
    scanf("%f", &anguloDeLancamento);

    // Fórmula para fazer o cálculo da distância]
    float alcanceHorinzontal = ((pow(velocidadeInicial, 2)) * (sin(2 * anguloDeLancamento))) / forcaDaGravidade;

    printf("\n\nO alcance horizontal sera igual a: %.2f metros\n\n", alcanceHorinzontal);

    return 0;
}