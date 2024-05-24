#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    char matricula[10];
} informacoes;

int main(){
    FILE *arquivo = fopen("arquivo.txt", "a+");
    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    informacoes aluno;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = 0;

    printf("Digite a matricula do aluno: ");
    fgets(aluno.matricula, sizeof(aluno.matricula), stdin);
    aluno.matricula[strcspn(aluno.matricula, "\n")] = 0;

    fprintf(arquivo, "%s,%s\n", aluno.nome, aluno.matricula);

    printf("Informacoes transcritas no arquivo! \n");

    fclose(arquivo);

    return 0;
}