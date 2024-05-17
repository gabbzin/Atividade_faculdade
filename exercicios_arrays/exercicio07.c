#include <stdio.h>

int main(){
    int i, soma = 0, numero[] = {2, 4, 6, 8, 11, 12, 13};
    int tamanho = sizeof(numero) / sizeof(numero[0]); 

    for (i = 0; i < tamanho; i++){
        soma += numero[i];
    }

    printf("%d", soma);

    return 0;
}