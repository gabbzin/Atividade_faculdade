#include <stdio.h>

int main(){
    int i, j;
    int arrayOriginal[10], arrayInvertido[10];

    for (i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &arrayOriginal[i]);
    }
    for (j = 9; j >= 0; j--){
        arrayInvertido[j] = arrayOriginal[j];
    }

    for (i = 0; i < 10; i++){
        printf("%d, ", arrayOriginal[i]);
    }

    printf("\n\n Mostrando os arrays \n\n");

    for (j = 9; j >= 0; j--){
        printf("%d, ", arrayInvertido[j]);
    }

    return 0;
}