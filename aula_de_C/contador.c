#include <stdio.h>

int main(){
    // Declaração das variáveis
    int segundos;
    int minutos;
    int horas;

    printf("Digite o tempo em segundos: ");
    scanf("%d", segundos);

    while (segundos > 60) { // Laço de repetição para realizar cálculos repetidos
        // Transformar os segundos em hora
        if (segundos >= 3600) {
            segundos -= 3600;
            horas += 1;
        } else if (segundos >= 60) {
            segundos -= 60;
            minutos += 1;
        } else {
            break;
        }
    }

    // Mostrando o resultado

    printf("Fiz a transformacao: \n");
    printf("O tempo de %d segundos convertido no tempo equivalente a horas, minutos e segundos\n", segundos);
    printf("E igual a: %d horas %d minutos %d segundos.");

    printf("\n\n==== Codigo executado com sucesso ====\n\n");

    return 0;
}