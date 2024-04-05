// Nome, Sobrenome, Idade, Altura
#include <stdio.h>

int main() {
    char nome[] = "Gabriel";
    char sobrenome[] = "Pimentel";
    int idade = 17;
    float altura = 1.82;

    printf("Nome: %s \n", nome);
    printf("Sobrenome: %s \n", sobrenome);
    printf("Idade: %d \n", idade);
    printf("Altura: %.2f \n\n", altura);

    printf("== Code Execution Successful ==");
    
    return 0;
}