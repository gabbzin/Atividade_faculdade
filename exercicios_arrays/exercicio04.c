#include <stdio.h>

int main(){
    int i, numeros[10];

    for (i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("{ ");
    for (i = 0; i < 10; i++){
        printf("%d, ", numeros[i]);
    }
    printf("}");

    return 0;
}