#include <stdio.h>

int main(){
    printf("=== Calculadora de area de retangulo ===\n\n");

    float baseRetangulo = 10;
    float alturaRetangulo = 5;

    float area = baseRetangulo * alturaRetangulo;
    
    printf("\nA area do retangulo e igual a: %.2fcm2", area);

    printf("\n\n=== Code execute successful ===");

    return 0;
}