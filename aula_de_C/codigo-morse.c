#include <stdio.h>
#include <windows.h> // Biblioteca com sleep e o beep

/*
    Caso se trate de uma frase, existe um silêncio de três unidades entre uma palavra e outra.
    No caso de mensagens mais longas, com mais de uma frase,
    o intervalo entre o fim de uma sentença e o começo de outra é de sete unidades.

    Os pontos têm duração curta, de uma unidade;
    Os traços têm duração mais longa, que duram, em média, três unidades de tempo.
*/

void somPonto(){
    Beep(1000, 500);
}

void somBarra(){
    Beep(1000, 1500);
}

char espacamento(){
    return printf("------------------------------------------------------------------------------- \n");
}

void sleep(int segundos){
    Sleep(segundos * 1000);
}

int main(){
    // Declaração das variáveis
    char frase[100]; // Variável para armazenar a frase
    char mensagemMorse[150]; // Variável para armazenar 
    int i = 0; // Variável criada para percorrer o array
    int realizarOperacao; // Variável para escolher a operação a ser realizada

    espacamento();

    // Início do programa

    printf("Ola, seja bem-vindo a codificador de codigo morse!! \n");
    printf("Antes de comecar, eu quero te passar algumas dicas: \n\n");

    sleep(2);

    printf("* Nao utilize acentos na hora de escrever a frase que sera codificada!\n");

    sleep(1);

    printf("* Caso use, as letras acentuadas nao serao codificadas \n");

    sleep(1);

    printf("* Habilite o som do seu dispositivo, caso queira ouvir o som \n");

    espacamento();
    sleep(2);

    while(TRUE){
        // Pedindo ao usuário qual operação ele quer realizar
        printf("\n\n");
        printf("Qual operacao voce deseja realizar: \n1. Codificar     2. Decodificar     3. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &realizarOperacao);

        espacamento();

        if (realizarOperacao == 1){
            // Pedindo que o usuário digite a frase que será codificada
            printf("Digite uma frase: ");
            fflush(stdin);  // Função para quebrar o input feito pelo scanf
            fgets(frase, sizeof(frase), stdin); // Input para entrada da frase

            sleep(2);

            // Percorrendo letra a letra da variável FRASE
            while (frase[i] != '\0'){
                // Transformando cada letra do array em letra minúscula
                frase[i] = tolower(frase[i]);

                // Código para cada letra
                switch (frase[i]){
                    case 'a':
                        printf(".- ");
                        somPonto(); somBarra();

                        sleep(1);
                        break;

                    case 'b':
                        printf("-... ");
                        somBarra(); somPonto(); somPonto(); somPonto();

                        sleep(1);
                        break;

                    case 'c':
                        printf("-.-. ");
                        somBarra(); somPonto(); somBarra(); somPonto();

                        sleep(1);
                        break;

                    case 'd':
                        printf("-.. ");
                        somBarra(); somPonto(); somPonto();

                        sleep(1);
                        break;
                        
                    case 'e':
                        printf(". ");
                        somPonto();

                        sleep(1);
                        break;

                    case 'f':
                        printf("..-. ");
                        somPonto(); somPonto(); somBarra(); somPonto();
                        
                        sleep(1);
                        break;

                    case 'g':
                        printf("--.");
                        somBarra(); somBarra(); somPonto();

                        sleep(1);
                        break;

                    case 'h':
                        printf(".... ");
                        somPonto(); somPonto(); somPonto(); somPonto();
                        sleep(1);
                        break;

                    case 'i':
                        printf(".. ");
                        somPonto(); somPonto();
                        sleep(1);
                        break;

                    case 'j':
                        printf(".--- ");
                        somPonto(); somBarra(); somBarra(); somBarra();
                        sleep(1);
                        break;

                    case 'k':
                        printf("-.- ");
                        somBarra(); somPonto(); somBarra();
                        sleep(1);
                        break;

                    case 'l':
                        printf(".-.. ");
                        somPonto(); somBarra(); somPonto(); somPonto();
                        sleep(1);
                        break;

                    case 'm':
                        printf("-- ");
                        somBarra(); somBarra();
                        sleep(1);
                        break;

                    case 'n':
                        printf("-. ");
                        somBarra(); somPonto();
                        sleep(1);
                        break;

                    case 'o':
                        printf("--- ");
                        somBarra(); somBarra(); somBarra();
                        sleep(1);
                        break;

                    case 'p':
                        printf(".--. ");
                        somPonto(); somBarra(); somBarra(); somPonto();
                        sleep(1);
                        break;

                    case 'q':
                        printf("--.- ");
                        somBarra(); somBarra(); somPonto(); somBarra();
                        sleep(1);
                        break;

                    case 'r':
                        printf(".-. ");
                        somPonto(); somBarra(); somPonto();
                        sleep(1);
                        break;

                    case 's':
                        printf("... ");
                        somPonto(); somPonto(); somPonto();
                        sleep(1);
                        break;

                    case 't':
                        printf("- ");
                        somBarra();
                        sleep(1);
                        break;

                    case 'u':
                        printf("..- ");
                        somPonto(); somPonto(); somBarra();
                        sleep(1);
                        break;

                    case 'v':
                        printf("...- ");
                        somPonto(); somPonto(); somPonto(); somBarra();
                        sleep(1);
                        break;

                    case 'w':
                        printf(".-- ");
                        somPonto(); somBarra(); somBarra();
                        sleep(1);
                        break;

                    case 'x':
                        printf("-..- ");
                        somBarra(); somPonto(); somPonto(); somBarra();
                        sleep(1);
                        break;

                    case 'y':
                        printf("-.-- ");
                        somBarra(); somPonto(); somBarra(); somBarra();
                        sleep(1);
                        break;

                    case 'z':
                        printf("--.. ");
                        somBarra(); somBarra(); somPonto(); somPonto();
                        sleep(1);
                        break;
                }
                i++;
            }
            printf("\n\n");
            espacamento();
        }

        if (realizarOperacao ==2 ){
            printf("Para digitar a mensagem codificada, utilize pontos e tracos, e separe cada letra com espaços");
            printf("Digite a mensagem que deseja traduzir: ");
            scanf("%s", &mensagemMorse);

            
        }

        if (realizarOperacao == 3){ // Opção para encerrar o programa
            printf("Obrigado por utilizar o nosso programa!!\n\n");
            break;
        }
    }
    
    return 0;
}