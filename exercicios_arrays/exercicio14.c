#include <stdio.h>

int main(){
    int i, j = 0;
    int array01[] = {10, 30, 50, 70, 90};
    int array02[] = {20, 40, 60, 80, 100};
    int array03[10];

    int tamanhoArray01 = sizeof(array01) / sizeof(array01[0]);
    int tamanhoArray02 = sizeof(array02) / sizeof(array02[0]);
    int tamanhoArray03 = tamanhoArray01 + tamanhoArray02;

    for (i = 0; i < tamanhoArray01; i++){
        array03[j++] = array01[i];
        array03[j++] = array02[i];
    }

    for (i = 0; i < tamanhoArray03; i++){
        printf("%d, ", array03[i]);
    }

    return 0;
}