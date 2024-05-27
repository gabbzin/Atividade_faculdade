#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char nome[30];
    float preco;
    int quantidade;
} produto;

produto p;

void sleep(int segundos) {
    Sleep(1000 * segundos);
}

void espaco() {
    printf("\n---------------------------------------------------------------------------------\n\n");
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void adicionar(FILE *arquivo) {
    sleep(2);

    printf("Digite o nome do produto: "); // Pegando o nome do produto
    limparBufferEntrada();
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    sleep(1);

    printf("Digite o preco do produto: R$ "); // Pegando o preço do produto
    scanf("%f", &p.preco);

    sleep(1);

    printf("Digite a quantidade do produto: "); // Pegando a quantidade de produto
    scanf("%d", &p.quantidade);

    fprintf(arquivo, "%s; R$%.2f; %d\n", p.nome, p.preco, p.quantidade);
    sleep(2);

    printf("\nAdicionado com sucesso!");

    espaco();
    sleep(2);
}

void alterarDados(FILE *arquivo) {
    char buffer[100], nomeDaBusca[30];
    int operando;
    bool encontrado = false;

    sleep(2);

    printf("Qual produto deseja alterar? ");
    limparBufferEntrada();
    fgets(nomeDaBusca, sizeof(nomeDaBusca), stdin);
    nomeDaBusca[strcspn(nomeDaBusca, "\n")] = 0;

    FILE *arquivoTemporario = fopen("temp.csv", "w");
    if (arquivoTemporario == NULL) {
        printf("Estamos com falhas nessa operacao!");
        return;
    }

    rewind(arquivo);
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        char *nomeProduto = strtok(buffer, ";");
        if (strcmp(nomeProduto, nomeDaBusca) == 0) {
            encontrado = true;
            printf("Produto encontrado com sucesso!\n");

            printf("O que deseja alterar? \n");
            printf("1. Nome    2. Preco    3. Quantidade \n");
            printf("Sua escolha: ");
            scanf("%d", &operando);
            limparBufferEntrada();

            switch (operando) {
                case 1:
                    printf("Digite o novo nome do produto: ");
                    fgets(p.nome, sizeof(p.nome), stdin);
                    p.nome[strcspn(p.nome, "\n")] = 0;
                    fprintf(arquivoTemporario, "%s; R$%.2f; %d\n", p.nome, p.preco, p.quantidade);
                    printf("Nome alterado com sucesso\n");
                    break;
                case 2:
                    printf("Digite o novo preco do produto: ");
                    scanf("%f", &p.preco);
                    limparBufferEntrada();
                    fprintf(arquivoTemporario, "%s; R$%.2f; %d\n", p.nome, p.preco, p.quantidade);
                    printf("O preco foi alterado com sucesso!\n");
                    break;
                case 3:
                    printf("Digite a nova quantidade de produto no estoque: ");
                    scanf("%d", &p.quantidade);
                    limparBufferEntrada();
                    fprintf(arquivoTemporario, "%s; R$%.2f; %d\n", p.nome, p.preco, p.quantidade);
                    printf("A quantidade foi alterada com sucesso!\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
        } else {
            fputs(buffer, arquivoTemporario);
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado!\n");
    }

    fclose(arquivo);
    fclose(arquivoTemporario);

    remove("arquivo.csv");
    rename("temp.csv", "arquivo.csv");

    espaco();
    sleep(2);
}

void lerDados(FILE *arquivo) {
    char linha[MAX_SIZE];

    rewind(arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0;
        printf("%s\n", linha);
    }

    sleep(2);
    espaco();
}

int main() {
    int opcao;

    while (TRUE) {
        FILE *arq = fopen("arquivo.csv", "a+");
        if (arq == NULL) {
            perror("Erro ao abrir o arquivo!");
            return 1;
        }

        printf("Digite a operacao que deseja realizar: \n");
        printf("1. Adicionar produtos ao estoque \n2. Atualizar produtos do estoque \n3. Listar todos os produtos do estoque \n4. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        espaco();

        switch (opcao) {
            case 1:
                printf("Opcao selecionada: 1 \n\n");
                adicionar(arq);
                break;
            case 2:
                printf("Opcao selecionada: 2 \n\n");
                alterarDados(arq);
                break;
            case 3:
                printf("Opcao selecionada: 3 \n\n");
                lerDados(arq);
                break;
            case 4:
                printf("Encerrando o programa!!!\n\n");
                fclose(arq);
                return 0;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        fclose(arq);
    }
}
