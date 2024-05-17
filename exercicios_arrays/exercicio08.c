#include <stdio.h>

int main(){
    int i, soma = 0;
    int numero[15];
    int tamanho = sizeof(numero) / sizeof(numero[0]); 

    for (i = 0; i < tamanho; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &numero[i]);

        soma += numero[i];
    }

    printf("%d", soma);

    return 0;
}