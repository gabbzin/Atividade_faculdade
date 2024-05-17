#include <stdio.h>

const int TOTAL = 8;

int main() {
    int i, j, k, array[TOTAL], novoTamanho = TOTAL;

    // Leitura dos elementos do array
    for (i = 0; i < TOTAL; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Impressão do array digitado
    printf("O array digitado: ");
    for (i = 0; i < TOTAL; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Removendo os elementos repetidos
    for (i = 0; i < novoTamanho; i++) {
        for (j = i + 1; j < novoTamanho; j++) {
            if (array[i] == array[j]) {
                // Desloca os elementos para a esquerda
                for (k = j; k < novoTamanho - 1; k++) {
                    array[k] = array[k + 1];
                }
                novoTamanho--; // Reduz o tamanho do array
                j--; // Garante que o novo elemento na posição j seja verificado
            }
        }
    }

    // Impressão do novo array sem repetições
    printf("Novo array sem repeticoes: ");
    for (i = 0; i < novoTamanho; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
