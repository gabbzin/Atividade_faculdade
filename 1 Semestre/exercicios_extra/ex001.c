#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    char operacao;
    float numero01, numero02, resultado;

    while (1){
        system("cls");
        
        printf("Escolha uma operacao: \n+ para adicao\n- para subtracao\n* para multiplicacao\n / para divisao\nPara encerrar o programa, digite 0\nSua escolha: ");
        scanf("%c", &operacao);

        if(operacao == 0){return 0;}

        printf("Digite o primeiro numero: ");
        scanf("%f", &numero01);

        
        printf("Digite o segundo numero: ");
        scanf("%f", &numero02);

        switch(operacao){
            case '+':
                resultado = numero01 + numero02;
                break;
            case '-':
                resultado = numero01 - numero02;
                break;
            case '*':
                resultado = numero01 * numero02;
                break;
            case '/':
                resultado = numero01 / numero02;
                break;
            default:
                printf("Digite uma operacao valida!");
                break;
        }

        printf("O resultado e igual a: %.2f", resultado);

        Sleep(5000);
    }
}