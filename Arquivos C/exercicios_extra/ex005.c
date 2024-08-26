#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 30

const char UNDERLINE = '_';

int i;

void adicionarPalavra(FILE *arquivo) {
    char palavra[MAX_PALAVRA];
    printf("Digite a palavra a ser adicionada: ");
    fflush(stdin);
    fgets(palavra, sizeof(palavra), stdin);

    // Remove newline character, if present
    size_t len = strlen(palavra);
    if (len > 0 && palavra[len-1] == '\n') {
        palavra[len-1] = '\0';
    }

    fprintf(arquivo, "%s\n", palavra);
    fclose(arquivo);
}

void exibirPalavra(char palavra[], int acertos[], int tamanho) {
    for (i = 0; i < tamanho; i++) {
        if (acertos[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("%c ", UNDERLINE);
        }
    }
    printf("\n");
}

int verificarLetra(char letra, char palavra[], int tamanho, int acertos[]) {
    int acerto = 0;
    for (i = 0; i < tamanho; i++) {
        if (toupper(letra) == toupper(palavra[i]) && !acertos[i]) {
            acertos[i] = 1;
            acerto = 1;
        }
    }
    return acerto;
}

void jogar(FILE *arquivo) {
    char palavra[MAX_PALAVRA];
    char linha[MAX_PALAVRA];
    int quantidadeLinhas = 0;
    srand(time(NULL));

    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        quantidadeLinhas++;
    }

    int linhaAleatoria = rand() % quantidadeLinhas;

    rewind(arquivo);
    for (i = 0; i <= linhaAleatoria; i++) {
        fgets(palavra, sizeof(palavra), arquivo);
    }

    // Remove newline character, if present
    size_t len = strlen(palavra);
    if (len > 0 && palavra[len-1] == '\n') {
        palavra[len-1] = '\0';
    }

    int tamanho = strlen(palavra);
    int acertos[tamanho];
    for (i = 0; i < tamanho; i++) {
        acertos[i] = 0;
    }

    int tentativas = 0;
    char letra;
    while (tentativas < MAX_TENTATIVAS) {
        exibirPalavra(palavra, acertos, tamanho);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (!verificarLetra(toupper(letra), palavra, tamanho, acertos)) {
            tentativas++;
        }

        int completou = 1;
        for (i = 0; i < tamanho; i++) {
            if (!acertos[i]) {
                completou = 0;
                break;
            }
        }

        if (completou) {
            printf("Parabens! Voce adivinhou a palavra: %s\n", palavra);
            return; // Sai do jogo ao completar a palavra
        }
    }

    printf("Voce perdeu! A palavra era: %s\n", palavra);
}

int main() {
    int operacao;
    FILE *gabarito;

    while (1) {
        gabarito = fopen("gabarito.txt", "a+"); // Abertura do arquivo

        if (gabarito == NULL) {
            perror("Erro ao abrir o arquivo.\n");
            return 1;
        }

        printf("Escolha uma operacao:\n1. Para adicionar palavras\n2. Para jogar (Em loop)\n3. Para encerrar\nSua escolha: ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                adicionarPalavra(gabarito);
                break;
            case 2:
                jogar(gabarito);
                break;
            case 3:
                printf("Encerrando o programa!\n");
                fclose(gabarito);
                return 0;
            default:
                printf("Operacao invalida! Tente Novamente!\n");
                break;
        }

        fclose(gabarito);
        Sleep(5000);
        system("cls");
    }
}
