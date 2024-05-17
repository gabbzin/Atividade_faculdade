#define MAX_SIZE 100
#include <stdio.h>

int main(){
    int i = 0, resposta = 1, numeros[MAX_SIZE];
    int maior = 0, menor;

    do {
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);

        if (numeros[i] > maior){
            maior = numeros[i];
        } else if (numeros[i] < menor){
            menor = numeros[i];
        }

        i++;

        printf("Deseja adicionar outro numero? [Digite 0 para encerrar]: ");
        scanf("%d", &resposta);
    } while (resposta != 0);

    printf("O maior numero digitado foi: %d \n", maior);
    printf("O menor numero digitado foi: %d \n", menor);

    return 0;
}