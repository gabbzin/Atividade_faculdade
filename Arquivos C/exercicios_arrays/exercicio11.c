#include <stdio.h>

int main(){
    int i, j;
    int numeros[5][5];

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("Digite o numero da linha %d e coluna %d: ", i+1, j+1);
            scanf("%d", &numeros[i][j]);
        }
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (i == j){
                printf("%d ", numeros[i][j]);
            }
        }
    }

    return 0;
}