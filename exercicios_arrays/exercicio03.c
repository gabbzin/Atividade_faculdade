#include <stdio.h>

int main(){
    int i;
    float notas[4];

    for (i = 0; i < 4; i++){
        printf("Digite a %d. nota: ", i + 1);
        scanf("%f", &notas[i]);
    }

    printf("\n -- Mostrando as notas -- \n");

    for (i = 0; i < 4; i++){
        printf("A %d nota e: %.2f \n", i + 1, notas[i]);
    }

    return 0;
}