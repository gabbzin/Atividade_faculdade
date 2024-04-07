#include <stdio.h>
#include <time.h>

// Criando uma função para o espaçamento, pois será usada algumas vezes
char espacamento() {
    return printf("|\n------------------------------------------------------\n");
}

int main(){

    printf("\n\n------------------ Caixa Eletronico -------------------\n|\n");

    // Criando as variáveis com double
    double saldoContaCorrente = 1652.20;
    double saldoContaPoupanca = 1254.25;
    double limiteDisponivel = saldoContaCorrente + saldoContaPoupanca;
    double valorSaque; // Variável para ver qual o valor do saque

    // Pedindo ao usuário para digitar o valor a ser sacado
    printf("|  Saldo da conta corrente: R$ %.2lf \n", saldoContaCorrente);
    printf("|  Saldo da conta poupanca: R$ %.2lf \n", saldoContaPoupanca);
    printf("|  Limite disponivel para saque: R$ %.2lf \n", limiteDisponivel);
    printf("|  Digite o valor do saque: R$ ");
    scanf("%lf", &valorSaque);

    espacamento(); // Chamada para a função de dar espaço

    while (valorSaque > limiteDisponivel){ // Laço de repetição para o usuário digitar um valor válido
        printf("|  Erro!! Por favor, digite um valor valido!\n");

        // Pedindo novamente ao usuário digitar o valor a ser sacado até ser validado 
        printf("|  Limite disponivel: R$ %.2lf\n", limiteDisponivel);
        printf("|  Digite o valor do saque: ");
        scanf("%lf", &valorSaque);

        espacamento();
    }
    printf("|\n|  Saque realizado com sucesso!!!\n");

    // Cálculo do novo limite parcial (de cada conta) após o saque

    if (valorSaque <= saldoContaCorrente) {
        saldoContaCorrente -= valorSaque;
    } else { // Caso o valor do saque seja maior que o limite disponível na conta corrente
        double saqueTotal = saldoContaCorrente; // Criação de uma nova variável para descontar tudo da conta corrente
        saldoContaCorrente = 0;
        valorSaque -= saqueTotal;
        saldoContaPoupanca -= valorSaque;
    }
    // Cálculo do limite total após o saque
    valorSaque -= limiteDisponivel;

    // Mostrando o novo limite disponível e os saldos restantes das contas Corrente e Poupança
    printf("|  Novo limite disponivel: %.2lf \n", limiteDisponivel);
    printf("|  O saldo restante da sua conta corrente ficou: R$ %.2lf \n", saldoContaCorrente);
    printf("|  O saldo restante da sua conta poupanca ficou: R$ %.2lf", saldoContaPoupanca);

    printf("\n-------------------------------------------------------\n"); // Não pude chamar a função novamente por causa da barra no inicio

    // Fim do programa
    return 0;
}