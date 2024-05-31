#include <stdio.h>
#include <string.h>

int main(){
    char nome[30], profissao[30], biografia[200];
    int idade;

    FILE *arquivo = fopen("index.html", "w");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Digite seu nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Digite sua profissao: ");
    fflush(stdin);
    fgets(profissao, sizeof(profissao), stdin);
    profissao[strcspn(profissao, "\n")] = 0;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite uma breve biografia sobre voce:\n");
    fflush(stdin);
    fgets(biografia, sizeof(biografia), stdin);
    biografia[strcspn(biografia, "\n")] = 0;

    fprintf(arquivo, 
    "<html>\n<head>\n<title>%s</title>\n</head>\n<body>\n    <p>%s</p>\n    <p>%s</p>\n    <p>%d</p>\n    <p>%s</p>\n</body>\n</html>", nome, nome, profissao, idade, biografia);

    fclose(arquivo);

    return 0;
}