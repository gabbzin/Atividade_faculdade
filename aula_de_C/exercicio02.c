#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Inicializando o gerador de números aleatórios

    int numeroSorteado = 1 + (rand() % 100); // Criando a variável do número aleatório
    int numeroUsuario; // Variável para armazenar o número digitado pelo usuário
    int tentativas = 1; // Variavél que armazena o número de tentativas

    printf("----------------------- Bem-vindo ao jogo de adivinhacao! -----------------------");

    while (numeroSorteado != numeroUsuario){
        printf("Digite um numero: ");
        scanf("%d", &numeroUsuario);

        if (numeroUsuario > numeroSorteado){
            printf("O numero sorteado e menor que %d\n", numeroUsuario);
            tentativas++;
        } else if (numeroSorteado > numeroUsuario){
            printf("O numero sorteado e maior que %d\n", numeroUsuario);
            tentativas++;
        } else {
            printf("Parabens, voce acertou o numero na %d tentativa\n", tentativas);
        }
    }

    return 0;
}