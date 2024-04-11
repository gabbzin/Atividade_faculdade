#include <stdio.h>

int main(){
    // Declaração das variáveis
    int segundos;
    int minutos = 0;
    int horas = 0;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &segundos);

    int segundoInformado = segundos;

    while (segundos > 59) { // Laço de repetição para realizar cálculos repetidos
        // Transformar os segundos em hora
        if (segundos >= 3600) {
            horas += 1;
            segundos -= 3600;
        } else if (segundos >= 60) { // Transformando os segundos em minutos
            minutos += 1;
            segundos -= 60;
        }
    }

    // Mostrando o resultado
    printf("\n\nFiz a transformacao: \n\n");
    printf("O tempo de %d segundos convertido no tempo equivalente a horas, minutos e segundos\n\n", segundoInformado);
    printf("E igual a: %d horas %d minutos %d segundos.", horas, minutos, segundos);

    printf("\n\n==== Codigo executado com sucesso ====\n\n");

    return 0;
}