#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void sleep(int segundos){
    Sleep(segundos * 1000);
}

char espacamento(){
    return printf("-------------------------------------------------------\n");
}

int main(){
    srand(time(NULL));
    // Declaração das variavéis
    int escolhaComputador, escolhaUsuario, jogarNovamente;

    // Começando o jogo Jokenpô
    printf("\n\n------------ Bem-vindo ao jogo de Jokenpo ------------ \n\n");

    printf("Vamos comecar a jogar!\n");

    printf("."); sleep(1); printf("."); sleep(1); printf("."); sleep(1);

    printf("\n");

    espacamento();

    while (TRUE){ // Loop do jogo
        // Computador escolhendo sua jogada
        escolhaComputador = 1 + (rand() % 3);

        printf("Ja escolhi a minha jogada, agora escolha a sua\n");
        printf("1. Pedra     2. Papel     3. Tesoura\n");

        printf("Sua escolha: ");
        scanf("%d", &escolhaUsuario);

        espacamento();

        printf("Voce escolheu %d e eu escolhi %d\n", escolhaUsuario, escolhaComputador);

        if (escolhaComputador == escolhaUsuario){
            printf("Empatamos!\n");
        } else if (((escolhaComputador == 1) && (escolhaUsuario == 3)) || ((escolhaComputador == 2) && (escolhaUsuario == 1)) || ((escolhaComputador == 3) && (escolhaUsuario == 2))){
            printf("Eu venci o jogo!\n");
        } else {
            printf("Parabens! Voce venceu o jogo!\n");
        }

        espacamento();

        do {
            printf("Deseja jogar novamente?\n");
            printf("1. Sim     2. Nao\n");

            printf("Sua escolha: ");
            scanf("%d", &jogarNovamente);

            espacamento();
            if ((jogarNovamente != 1) && (jogarNovamente != 2)){
                printf("Opcao invalida, tente novamente\n");
            }
        } while ((jogarNovamente != 1) && (jogarNovamente != 2));
    }
    return 0;
}