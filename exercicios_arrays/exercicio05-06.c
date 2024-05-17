#include <stdio.h>

int main(){
    int i = 0, j = 0, numeros[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            if (numeros[i][j] % 2 == 0){
                numeros[i][j] = 0;
            }
            printf("%d, ", numeros[i][j]);
        }
    }

    return 0;
}