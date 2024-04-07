#include <stdio.h>
#include <windows.h> // Adição do sleep (Medido em milisegundos); 100ms equivalentem a 1s

// Função para o espaçamento, evitando repetições
char espacamento() {
    return printf("|\n-----------------------------------------------------------------\n");
}
// Função para colocar um intervalo de tempo entre os códigos
void sleep(int segundos) {
    Sleep(segundos * 1000); // Convertendo de Segundos para MiliSegundos
}
// Principal
int main(){

    printf("\n\n----------------------- Caixa Eletronico ------------------------\n|\n");

    // Criando as variáveis com double
    double saldoContaCorrente = 1652.20;
    double saldoContaPoupanca = 1254.25;
    double limiteDisponivel = saldoContaCorrente + saldoContaPoupanca;
    double valorSaque;

    // Pedindo ao usuário para digitar o valor a ser sacado
    printf("|  Saldo da conta corrente: R$ %.2lf \n", saldoContaCorrente);
    printf("|  Saldo da conta poupanca: R$ %.2lf \n", saldoContaPoupanca);
    printf("|  Limite disponivel para saque: R$ %.2lf \n", limiteDisponivel);
    printf("|  Digite o valor do saque: R$ ");
    scanf("%lf", &valorSaque);

    espacamento(); // Chamada para a função de dar espaço
    sleep(2); // Esperando 2s

    while (valorSaque > limiteDisponivel){ // Laço de repetição para o usuário digitar um valor válido
        printf("|  Erro!! Por favor, digite um valor valido!\n");

        sleep(2); // Esperando 2s        

        // Pedindo novamente ao usuário digitar o valor a ser sacado até ser validado 
        printf("|  Limite disponivel: R$ %.2lf\n", limiteDisponivel);
        printf("|  Digite o valor do saque: ");
        scanf("%lf", &valorSaque);

        espacamento();
    }
    printf("|\n|  Saque realizado com sucesso!!!\n");

    espacamento();
    printf("|\n");

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
    limiteDisponivel -= valorSaque;

    sleep(2); // Esperando 2s

    // Mostrando o novo limite disponível e os saldos restantes das contas Corrente e Poupança
    printf("|  Novo limite disponivel: %.2lf \n", limiteDisponivel);
    printf("|  O saldo restante da sua conta corrente ficou: R$ %.2lf \n", saldoContaCorrente);
    printf("|  O saldo restante da sua conta poupanca ficou: R$ %.2lf \n", saldoContaPoupanca);

    espacamento();

    // Fim do programa
    return 0;
}