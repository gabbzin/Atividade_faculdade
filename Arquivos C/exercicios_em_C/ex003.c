// Crie um programa em C que verifica se o ano é bissexto
#include <stdio.h>

int main(){
    int ano;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))){
        printf("O ano %d e bissexto.\n", ano);
    } else {
        printf("O ano %d não e bissexto.\n", ano);
    }

    return 0;
}