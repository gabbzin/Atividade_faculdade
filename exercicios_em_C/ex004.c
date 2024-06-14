#include <stdio.h>
#define PI 3.14

double calcularAreaCirculo(double raio){
    double area = PI * (raio * raio);
    return area;
}

int main(){
    double raio;
    printf("Digite o raio do circulo: ");
    scanf("%d", &raio);

    calcularAreaCirculo(raio);

    return 0;
}