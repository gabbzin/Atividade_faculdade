#include <stdio.h>

int main(){

    printf("\n\nPor favor, utlize o (.) em vez de virgula\n\n");
    
    float n1, n2, n3;
    float maior, menor, intermediario;

    printf("Digite um numero nao inteiro: ");
    scanf("%f", &n1);

    printf("Digite outro numero nao inteiro: ");
    scanf("%f", &n2);

    printf("Digite o ultimo numero nao inteiro: ");
    scanf("%f", &n3);

    printf("\n\n");

    if ((n1 > n2) && (n1 > n3)){
        maior = n1;
        if (n2 > n3){
            intermediario = n2;
            menor = n3;
        } else {
            intermediario = n3;
            menor = n2;
        }
    } else if ((n2 > n1) && (n2 > n3)){
        maior = n2;
        if (n1 > n3){
            intermediario = n1;
            menor = n3;
        } else {
            intermediario = n3;
            menor = n1;
        }
    } else if ((n3 > n1) && (n3 > n2)){
        maior = n3;
        if (n1 > n2){
            intermediario = n1;
            menor = n2;
        } else {
            intermediario = n2;
            menor = n1;
        }
    }

    printf("O maior valor e o %.2f \n", maior);
    printf("O valor intermediario e o %.2f \n", intermediario);
    printf("O menor valor e o %.2f \n", menor);

    return 0;
}