#define MAX_SIZE 20
#include <stdio.h>

int main(){
    int i = 0, resposta, numeros[MAX_SIZE];

    do {
        if (i >= MAX_SIZE) {
            printf("Limite de %d números atingido.\n", MAX_SIZE);
            break;
        }

        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);

        i++;

        printf("Deseja adicionar outro numero? [Digite 0 para encerrar]: ");
        scanf("%d", &resposta);
    } while (resposta != 0);

    int tamanho = i;

    for (i = 0; i < tamanho; i++){
        if (numeros[i] % 2 == 0){
            printf("%d, ", numeros[i]);
        }
    }

    return 0;
}