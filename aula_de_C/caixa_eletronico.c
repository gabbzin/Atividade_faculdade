#include <stdio.h>

int main(){
    // Criando as variáveis com double
    double saldoContaCorrente = 1652.20;
    double saldoContaPoupanca = 1254.25;
    double limiteDisponivel = saldoContaCorrente + saldoContaPoupanca;
    double valorSaque;

    printf("Limite disponivel: %.2f\n", limiteDisponivel);
    printf("Digite o valor do saque: ");
    scanf("%lf", &valorSaque);

    if (valorSaque > limiteDisponivel){
        printf("\nValor insuficiente na conta!\n");
    } else {
        printf("\n-- Saque realizado com sucesso --\n");

        limiteDisponivel -= valorSaque;

        printf("O saque disponivel agora e: %.2lf\n", limiteDisponivel);
    }

    return 0;
}