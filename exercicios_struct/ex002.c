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
                printf("Voce selecionou a opcao de adicionar produtos ao estoque! Vamos la!\n\n");
                adicionar();
                fprintf(arq, "%s,R$%.2f,%d\n", p.nome, p.preco, p.quantidade);

                break;
            case 2:
                printf("Voce selecionou a opcao de alterar informacoes do estoque. Vamos la! \n\n");

                break;
            case 3:
                printf("Voce selecionou a opcao de listar todas as informacoes existentes");
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