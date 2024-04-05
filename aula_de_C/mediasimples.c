#include <stdio.h>

int main(){
    int n1;
    int n2;
    int n3;

    printf("Digite um numero: ");
    scanf("%d", &n1);

    printf("Digite outro numero: ");
    scanf("%d", &n2);

    printf("Digite outro numero: ");
    scanf("%d", &n3);

    double media  = (n1 + n2 + n3) / 3;

    printf("\nA media dos numeros digitados e: %.2lf\n", media);

    return 0;
}