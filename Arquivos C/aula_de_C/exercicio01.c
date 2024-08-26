#include <stdio.h>

int main(){
    float n1, n2, n3;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);

    float media = (n1 + n2 + n3) / 3;

    printf("A media dos numeros digitados e igual a %.2f", media);

    return 0;
}