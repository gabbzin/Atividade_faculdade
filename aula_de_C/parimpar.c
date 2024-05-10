#include <stdio.h>

int main(){
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    int res = numero % 2;

    switch(res){
        case 0:
            printf("O numero %d e par", numero);
            break;
        case 1:
            printf("O numero %d e impar", numero);
            break;
        default:
            printf("Numero invalido");
            break;
    }

    return 0;
}