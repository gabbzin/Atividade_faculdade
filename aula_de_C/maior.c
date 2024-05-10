#include <stdio.h>

int main(){
    int n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);

    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    switch(n1 > n2){
        case 0:
            if (n1 == n2){
                printf("Os numeros sao iguais");
            } else {
                printf("O maior numero e: %d", n2);
            }
            break;
        case 1:
            printf("O maior numero e: %d", n1);
            break;
        default:
            printf("ERRO!!");
            break;
    }
    return 0;
}