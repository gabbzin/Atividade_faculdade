#include <stdio.h>

int main(){
    int array01[8], array02[8], array03[8], i;

    printf("Digite os valores do primeiro array\n");
    for (i = 0; i < 8; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &array01[i]);
    }

    printf("\n\n");

    printf("Digite os valores do segundo array\n");
    for (i = 0; i < 8; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &array02[i]);
    }

    for (i = 0; i < 8; i++){
        array03[i] = array01[i] + array02[i];
    }

    for (i = 0; i < 8; i++){
        printf("Array 03: %d, ", array03[i]);
    }

    return 0;
}