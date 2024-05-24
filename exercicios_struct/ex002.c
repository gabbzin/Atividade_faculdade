#include <stdio.h>
#include <windows.h>

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
    return printf("\n---------------------------------------\n\n");
}

void adicionar(){
    sleep(2);

    printf("Digite o nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);

    espaco();
    sleep(2);

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);

    espaco();
    sleep(2);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);

    sleep(1);

    printf("Adicionado com sucesso! \n\n");

    espaco();
    sleep(2);
}

void alterarDados(){
    int operando;
    sleep(2);

    printf("O que deseja alterar? \n");
    printf("1. Nome    2. Preco    3. Quantidade \n");
    printf("Sua escolha: ");
    scanf("%d", &operando);
}

int main(){
    int opcao;
    FILE *arq = fopen("arquivo.txt", "a+");
    
    while(TRUE){
        printf("Digite a operacao que deseja realizar: \n");
        printf("1. Adicionar produtos ao estoque \n2. Atualizar produtos do estoque\n 3. Listar todos os produtos do estoque\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        // Selecionando qual operação o usuário quer fazer
        switch(opcao){
            case 1: // Adicionar produtos ao estoque
                printf("Voce selecionou a opcao de adicionar produtos ao estoque! Vamos la!\n\n");
                adicionar();
                break;
            case 2:
                printf("Voce selecionou a opcao de alterar informacoes do estoque. Vamos la! \n\n");
            case 3:
            default:
                printf("Opcao invalida!");
                break;
        }
    }
}