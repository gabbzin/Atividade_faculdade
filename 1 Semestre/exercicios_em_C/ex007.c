#include <stdio.h>

#define TAMANHO 5

// Função para calcular a soma dos elementos do vetor
int calcularSoma(int vetor[], int tamanho) {
    int soma = 0, i;
    for (i = 0; i < tamanho; i++) { // Bug corrigido
        soma += vetor[i];
    }
    return soma;
}

// Função para encontrar o maior elemento do vetor
int encontrarMaior(int vetor[], int tamanho) {
    int maior = vetor[0], i;
    for (i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    int numeros[TAMANHO], i;
    
    // Entrada de dados
    printf("Digite %d numeros inteiros:\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++) {
        scanf("%d", &numeros[i]);
    }

    // Chamando as funções e exibindo os resultados
    int soma = calcularSoma(numeros, TAMANHO);
    int maior = encontrarMaior(numeros, TAMANHO);

    printf("A soma dos elementos do vetor é: %d\n", soma);
    printf("O maior elemento do vetor é: %d\n", maior);

    return 0;
}