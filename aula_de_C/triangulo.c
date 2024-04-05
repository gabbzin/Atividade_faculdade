#include <stdio.h>

int main(){
    printf("\n\n==== Verificador de triangulos ====\n\n");
    // Declarando as variaveis
    float primeiroLado;
    float segundoLado;
    float terceiroLado;

    // Coletando as informações
    printf("Digite o valor do primeiro lado: ");
    scanf("%f", &primeiroLado);

    printf("Digite o valor do segundo lado: ");
    scanf("%f", &segundoLado);

    printf("Digite o valor do terceiro lado: ");
    scanf("%f", &terceiroLado);

    // Verificando se pode formar um triângulo
    if ((primeiroLado + segundoLado) > terceiroLado && (segundoLado + terceiroLado) > primeiroLado && (primeiroLado + terceiroLado) > segundoLado){
        printf("Com esses valores, podemos formar um triangulo! Agora vamos ver qual o seu tipo. \n\n");
        
        // Verficando qual o tipo do triângulo
        if ((primeiroLado == segundoLado) && (segundoLado == terceiroLado)){ // Lados iguais é um triângulo equilátero
            printf("O triangulo e do tipo equilatero");
        } else if ((primeiroLado == segundoLado) || (primeiroLado == terceiroLado) || (segundoLado == terceiroLado)){ // 2 lados iguais é um triângulo
            printf("O triangulo e do tipo isosceles");
        } else {
            printf("O triangulo e do tipo escaleno");
        }
    }

    printf("\n\n==== Code Executed Successful ====\n\n");

    return 0;
}