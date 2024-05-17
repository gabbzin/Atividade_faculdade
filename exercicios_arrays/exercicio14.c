#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    int array01[] = {10, 30, 50, 70, 90};
    int array02[] = {20, 40, 60, 80, 100};
    int array03[10];

    int tamanho =  sizeof(array01) + sizeof(array02);

    int tamanhoArray = tamanho / sizeof(array01[0]);

    for (i = 0; i < tamanhoArray; i++){
        for (j = 0; j < tamanhoArray; j++){
            if (i % 2 == 0){
                array03[i] = array01[i];
            } else {
                array03[i] = array02[i];
            }
        }
    }

    for (i = 0; i < tamanhoArray; i++){
        printf("%d, ", array03[i]);
    }

    return 0;
}