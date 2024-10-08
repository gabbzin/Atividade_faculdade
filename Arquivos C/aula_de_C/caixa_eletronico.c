#include <stdio.h>
#include <windows.h> // Adição do sleep (Medido em milisegundos); 1000ms equivalentem a 1s

// Função para o espaçamento, evitando repetições
char espacamento() {
    return printf("|\n|---------------------------------------------------------------\n");
}
// Função para colocar um intervalo de tempo entre os códigos
void sleep(int segundos) {
    Sleep(segundos * 1000); // Convertendo de Segundos para MiliSegundos
}
// Principal
int main(){

    printf("\n\n----------------------- Caixa Eletronico ------------------------\n|\n");

    // Criando as variáveis com double
    int realizarOperacao; // Para o usuário escolher a opção a ser realizada
    int escolhaConta; // Escolha da conta a ser utilizada para o depósito
    double saldoContaCorrente = 1652.20; // Saldo da conta corrente
    double saldoContaPoupanca = 1254.25; // Saldo da conta poupança
    double limiteDisponivel = saldoContaCorrente + saldoContaPoupanca; // Limite disponível 
    double valorSaque; // Valor do saque
    double valorDeposito; // Valor do depósito

    while (TRUE){
        // Pedindo ao usuário para escolher uma operação
        printf("|  Escolha uma das opcoes abaixo: \n");
        printf("|  1. Sacar     2. Depositar     3. Sair \n|\n");
        printf("|  Qual operacao deseja realizar: ");
        scanf("%d", &realizarOperacao);

        espacamento();

        switch(realizarOperacao){
            // Operação de saque    
            case 1:
                // Pedindo ao usuário para digitar o valor a ser sacado
                printf("|  Saldo da conta corrente: R$ %.2lf \n", saldoContaCorrente);
                printf("|  Saldo da conta poupanca: R$ %.2lf \n", saldoContaPoupanca);
                printf("|  Limite disponivel para saque: R$ %.2lf \n", limiteDisponivel);
                printf("|  Digite o valor do saque: R$ ");
                scanf("%lf", &valorSaque);

                espacamento(); // Função para dar espaço
                sleep(2); // Esperando 2s

                while (valorSaque > limiteDisponivel || valorSaque <= 0){ // Laço de repetição para o usuário digitar um valor válido
                    printf("|  Erro!! Por favor, digite um valor valido!\n");

                    sleep(2); // Esperando 2s

                    // Pedindo novamente ao usuário digitar o valor a ser sacado até ser validado 
                    printf("|  Limite disponivel: R$ %.2lf\n", limiteDisponivel);
                    printf("|  Digite o valor do saque: R$ ");
                    scanf("%lf", &valorSaque);

                    espacamento();

                }
                
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
                limiteDisponivel = saldoContaCorrente + saldoContaPoupanca;
                
                // Informando que o saque foi realizado
                printf("|\n|  O saque foi realizado com sucesso!!!\n");

                espacamento();
                printf("|\n");

                sleep(2); // Esperando 2s

                // Mostrando o novo limite disponível e os saldos restantes das contas Corrente e Poupança
                printf("|  Novo limite disponivel: R$ %.2lf \n", limiteDisponivel);
                printf("|  O saldo restante da sua conta corrente ficou: R$ %.2lf \n", saldoContaCorrente);
                printf("|  O saldo restante da sua conta poupanca ficou: R$ %.2lf \n", saldoContaPoupanca);

                espacamento();
                break;
            case 2:
                // Mostrando o saldo de cada conta
                printf("|  Saldo da conta corrente: R$ %.2lf \n", saldoContaCorrente);
                printf("|  Saldo da conta poupanca: R$ %.2lf \n", saldoContaPoupanca);

                // Pedindo ao usuário o valor a ser depositado
                printf("|  Qual valor deseja depositar: R$ ");
                scanf("%lf", &valorDeposito);

                espacamento();
                sleep(2);

                // Verificação para evitar depósitos negativos (while) e escolha da conta onde o dinheiro vai ser depositado ()
                while(valorDeposito <= 0){
                    printf("|  O valor digitado e invalido! \n|  Digite um valor maior do que 0 \n");
                    sleep(2);

                    printf("|  Qual valor deseja depositar: R$ ");
                    scanf("%lf", &valorDeposito);

                    espacamento();
                    sleep(2);
                }

                printf("|  Em qual conta deseja depositar: \n");
                printf("|  1. Corrente        2. Poupanca \n");
                printf("|  Sua escolha: ");
                scanf("%d", &escolhaConta);
                
                espacamento();
                sleep(2);

                // Escolha da conta para ser depositado o dinheiro
                while ((escolhaConta != 1) && (escolhaConta != 2)){

                    printf("|  A opcao escolhida nao existe, por favor tente novamente!\n|\n");

                    sleep(2);

                    printf("|  Em qual conta deseja depositar: \n");
                    printf("|  1. Corrente        2. Poupanca \n");
                    printf("|  Sua escolha: ");
                    scanf("%d", &escolhaConta);

                    espacamento();
                    sleep(2);
                }

                if (escolhaConta == 1){
                    // Depositando na conta corrente
                    saldoContaCorrente += valorDeposito;
                    printf("|  Novo saldo da conta corrente: R$ %.2lf \n", saldoContaCorrente);
                } else if (escolhaConta == 2){
                    // Depositando na conta poupança
                    saldoContaPoupanca += valorDeposito;
                    printf("|  Novo saldo da conta poupanca: R$ %.2lf \n", saldoContaPoupanca);
                }

                limiteDisponivel = saldoContaCorrente + saldoContaPoupanca; // Calculando o novo limite

                espacamento();
                sleep(2);

                break;
            default: // Caso o usuario digite um valor invalido
                if (realizarOperacao != 3){
                    printf("|  Por favor digite um valor valido.\n");

                    espacamento();
                    sleep(2);

                    break;
                }
        }
        if (realizarOperacao == 3){
            break;
        } 
    }
    printf("|  Obrigado por utilizar o nosso sistema. \n");

    espacamento();
    sleep(2);

    return 0;
}