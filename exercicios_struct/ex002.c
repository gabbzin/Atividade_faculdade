#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define MAX_LINHA 100

typedef struct{
    char nome[30];
    float preco;
    int quantidade;
} produto;
produto p;

void sleep(int segundos){
    return Sleep(1000 * segundos);
}
void espaco(){
    printf("\n---------------------------------------------------------------------------------\n\n");
}

void adicionar(){
    sleep(2);

    printf("Digite o nome do produto: "); // Pegando o nome do produto
    // Limpando o buffer de entrada
    fflush(stdin);
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    sleep(1);

    printf("Digite o preco do produto: R$ "); // Pegando o preço do produto
    scanf("%f", &p.preco);

    sleep(1);

    printf("Digite a quantidade do produto: "); // Pegando a quantidade de produto
    scanf("%d", &p.quantidade);

    sleep(2);

    printf("\nAdicionado com sucesso!");

    espaco();
    sleep(2);
}

void alterarDados(FILE *arquivo){ // Arrumar
    char buffer[100], nomeDaBusca[30];
    int operando;
    bool encontrado = false;

    sleep(2);

    printf("Qual produto deseja alterar? "); // Pegando o nome do produto
    fflush(stdin); // Limpando a entrada
    fgets(nomeDaBusca, sizeof(nomeDaBusca), stdin);

    size_t len = strlen(nomeDaBusca); // Não quebrar a linha ao finalizar o fgets
    if (len > 0 && nomeDaBusca[len - 1] == '\n') {
        nomeDaBusca[len - 1] = '\0';
    }

    rewind(arquivo); // Para voltar ao início do arquivo
    while(fgets(buffer, sizeof(buffer), arquivo) != NULL){
        char *nomeProduto = strtok(buffer, ","); // Extraindo o primeiro elemento de cada linha
        if(strcmp(nomeProduto, nomeDaBusca) == 0){
            printf("Produto encontrado com sucesso!");
            encontrado = true;
        }
    }

    if (!encontrado){
        printf("Produto nao encontrado!\n");
        return;
    }

    // Perguntando ao usuário o que será alterado
    printf("O que deseja alterar? \n");
    printf("1. Nome    2. Preco    3. Quantidade \n");
    printf("Sua escolha: ");
    scanf("%d", &operando);

    switch(operando){
        case 1:
            printf("Digite o novo nome do produto: "); // Pegando o nome do produto
            // Limpando o buffer de entrada
            fflush(stdin);
            fgets(p.nome, sizeof(p.nome), stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;

            espaco();
            printf("Nome alterado com sucesso");
            espaco();

            break;
        case 2: // Não está funcionando
            printf("Digite o novo preco do produto: ");
            fflush(stdin); // Limpando a entrada
            fgets(buffer, sizeof(buffer), stdin);
            p.preco = strtod(buffer, NULL);

            espaco();
            printf("O preco foi alterado com sucesso!");
            espaco();

            break;
        case 3:
            printf("Digite a nova quantidade de produto no estoque: ");
            fflush(stdin);
            fgets(buffer, sizeof(buffer), stdin);
            p.quantidade = strtol(buffer, NULL, 10);

            espaco();
            printf("A quantidade foi alterada com sucesso!");
            espaco();

            break;
        default:
            printf("Opcao invalida");
            break;
    }

    sprintf(buffer, "%s,%.2f,%d", p.nome, p.preco, p.quantidade); // Fazendo alterações na linha correspodente

    FILE *arquivoTemporario = fopen("temp.csv", "w");
    if (arquivoTemporario == NULL) {
        printf("Estamos com falhas nessa operacao!");
        return;
    }

    rewind(arquivo);
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        char *nomeProduto = strtok(buffer, ",");
        if (strcmp(nomeProduto, nomeDaBusca) == 0) {
            fprintf(arquivoTemporario, "%s,%.2f,%d\n", p.nome, p.preco, p.quantidade);
        } else {
            fputs(buffer, arquivoTemporario);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemporario);

    remove("arquivo.csv");
    rename("temp.csv", "arquivo.csv");

    printf("Alteracoes salvas com sucesso!\n");

    espaco();
    sleep(2);
}

void lerDados(FILE *arquivo){ // Arrumar
    char linha[MAX_LINHA];
    while(fgets(linha, MAX_LINHA, arquivo)){
        printf("%s", linha);
    }
}
int main(){
    int opcao;
    FILE *arq = fopen("arquivo.csv", "a+");

    if (arq == NULL){
        perror("Erro ao abrir o arquivo!");
        return 1;
    }
    
    while(TRUE){ // Pedindo ao usuário para escolher a opção
        printf("Digite a operacao que deseja realizar: \n");
        printf("1. Adicionar produtos ao estoque \n2. Atualizar produtos do estoque \n3. Listar todos os produtos do estoque \n4. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        espaco();

        // Selecionando qual operação o usuário quer fazer
        switch(opcao){
            case 1: // Adicionar produtos ao estoque
                printf("Opcao selecionada: 1 \n\n");
                adicionar();
                break;
            case 2: // Alterar informações de produtos do estoque
                printf("Opcao selecionada: 2 \n\n");
                alterarDados(arq); // ARRUMAR
                break;
            case 3: // Ler e escrever os produtos do estoque
                printf("Opcao selecionada: 3 \n\n");
                lerDados(arq); // ARRUMAR
                break;
            case 4:
                printf("Encerrando o programa!!!\n");
                fclose(arq);
                return 0;
            default:
                printf("Opcao invalida!");
                break;
        }
    }
}