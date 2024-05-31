#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

void adicionarPalavra(FILE *arquivo){
    char palavra[20];
    printf("Digite a palavra a ser adicionada: ");
    fflush(stdin);
    fgets(palavra, sizeof(palavra), stdin);

    fprintf(arquivo, "%s", palavra);

    fclose(arquivo);
}

void jogar(FILE *arquivo){ // Função do jogo
    while(TRUE){
        int quantidadeLinhas = 0;
        char palavra[30];
        char *linha = malloc(30);
        srand(time(NULL));

        rewind(arquivo);
        while(fgets(linha, sizeof(linha), arquivo) != NULL){
            quantidadeLinhas++;
        }

        free(linha);

        int linhaAleatoria = randint() % quantidadeLinhas; // Gerando linha aleatoria

        // Faltar completar
    }
}

int main(){
    int operacao;

    FILE *gabarito;

    if(gabarito == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while(TRUE){
        fopen("gabarito.txt", "a+"); // Abertura do arquivo

        printf("Escolha uma operacao:\n1. Para adicionar palavras\n2. Para jogar (Em loop)\n3. Para encerrar\nSua escolha: ");
        scanf("%d", &operacao);

        switch(operacao){
            case 1:
                adicionarPalavra(gabarito);
                break;
            case 2:
                jogar(gabarito);
                break;
            case 3:
                printf("Encerrando o programa!");
                fclose(gabarito);
                return 0;
                break;
            default:
                printf("Operacao invalida! Tente Novamente!");
                break;
        }

        Sleep(5000);
        system("cls");
        Sleep(5000);
    }
}