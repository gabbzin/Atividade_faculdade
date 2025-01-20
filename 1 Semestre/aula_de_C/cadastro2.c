#include <stdio.h>

int main() {
    char nome[50];
    char sobrenome[50];
    int idade;
    float altura;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    printf("\n\n== Dados coletados com sucesso ==\n\n");
    printf("Mostrando dados: \n");

    printf("Nome Completo: %s %s \n", nome, sobrenome);
    printf("Idade: %d \n", idade);
    printf("Altura: %.2f", altura);

    printf("\n\n== Code Execute Successful ==");

    return 0;
}