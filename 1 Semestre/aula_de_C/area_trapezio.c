#include <stdio.h>

int main(){
    printf("\n\n---- Bem-vindo a calculadora de area de trapezio ----\n\n");

    // Coletando as informações
    float baseMaior = 8;
    float baseMenor = 4;
    float alturaTrapezio = 3;

    // Calculando a area do trapezio
    float areaDoTrapezio = (baseMaior + baseMenor) * alturaTrapezio / 2;

    // Mostrando o resultado
    printf("A area do trapezio e: %.2f", areaDoTrapezio);

    printf("\n\n ---- Code Executed Successful ---- \n\n");

    return 0;
}