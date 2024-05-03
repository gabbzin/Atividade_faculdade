#include <stdio.h>

// Number 01 vai receber o número maior e o Number 02 vai receber o número menor
int mdc(int number01, int number02);

int main(){
    int n1, n2, maiorDivisorComum;

    do {
        printf("Digite o primeiro numero: ");
        scanf("%d", &n1);

        printf("Digite o segundo numero: ");
        scanf("%d", &n2);
    } while (n1 <= 0 && n2 <= 0);
    
    if (n2 > n1) {
        maiorDivisorComum = mdc(n2, n1);
    } else {
        maiorDivisorComum = mdc(n1, n2);
    }
    
    printf("O MDC e igual a %d", maiorDivisorComum);

    return 0;
}

int mdc(int number01, int number02){
    
    int resto;
    resto = number01 % number02;

    if (resto == 0){
        return number02;
    } else {
        return mdc(number02, resto);
    }
}