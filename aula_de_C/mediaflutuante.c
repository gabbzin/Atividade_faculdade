#include <stdio.h>

int main(){

    printf("\n\nPor favor, utlize o (.) em vez de virgula\n\n");
    
    float n1;
    float n2;
    float n3;

    printf("Digite um numero nao inteiro: ");
    scanf("%f", &n1);

    printf("Digite outro numero nao inteiro: ");
    scanf("%f", &n2);

    printf("Digite o ultimo numero nao inteiro: ");
    scanf("%f", &n3);

    float media = (n1 + n2 + n3) / 3;

    printf("\n\nA media dos numeros digitados e igual a %.2f", media);

    return 0;
}