#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_CONSULTAS 20

typedef struct{
    char *nomePaciente;
    char *dataHora; // Formato DD/MM/AAAA/HH:MI
    char *nomeMedico;
} consulta;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarConsulta(int indice, consulta *lista){
    char buffer[50];
    char dataHoraBuffer[20];

    int data[3];
    int hora[2];

    printf("Nome do Paciente: ");
    limparBufferEntrada();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove o newline do final da string
    lista[indice].nomePaciente = strdup(buffer);

    printf("Preencha data e hora usando numeros no formato (DD/MM/AAAA Hora:Minuto)\n");

    printf("Dia da consulta: ");
    scanf("%d", &data[0]);
    printf("Mes da consulta: ");
    scanf("%d", &data[1]);
    printf("Ano da consulta: ");
    scanf("%d", &data[2]);

    printf("Hora da consulta: ");
    scanf("%d", &hora[0]);
    printf("Minutagem: ");
    scanf("%d", &hora[1]);

    snprintf(dataHoraBuffer, sizeof(dataHoraBuffer), "%02d/%02d/%04d %02d:%02d", data[0], data[1], data[2], hora[0], hora[1]);
    lista[indice].dataHora = strdup(dataHoraBuffer);

    printf("Nome do Medico: ");
    limparBufferEntrada();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove o newline do final da string
    lista[indice].nomeMedico = strdup(buffer);
}

void listarConsultas(int total, consulta *lista) {
    int i;
    for(i = 0; i < total; i++) {
        printf("Consulta %d:\n", i + 1);
        printf("Paciente: %s\n", lista[i].nomePaciente);
        printf("Data/Hora: %s\n", lista[i].dataHora);
        printf("Medico: %s\n\n", lista[i].nomeMedico);
    }
}

void cancelarConsulta(int *total, consulta *lista) {
    int i;
    if (*total == 0) {
        printf("Nenhuma consulta para cancelar.\n");
        return;
    }
    listarConsultas(*total, lista);
    printf("Digite o numero da consulta a ser cancelada: ");
    int indice;
    scanf("%d", &indice);
    if (indice < 1 || indice > *total) {
        printf("Indice invalido!\n");
        return;
    }
    indice--; // ajustar para indice baseado em zero

    free(lista[indice].nomePaciente);
    free(lista[indice].dataHora);
    free(lista[indice].nomeMedico);

    for( i = indice; i < *total - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*total)--;
    printf("Consulta cancelada com sucesso.\n");
}

int main(){
    consulta listaDeConsultas[MAXIMO_CONSULTAS];
    int totalConsultas = 0;
    int opcao, i;

    printf("\n\nSeja bem-vindo a assistencia de consultas.\n\n");
    while (1){
        printf("====== Total de consultas: %d ====== \n\n", totalConsultas);
        printf("Por favor escolha uma opcao:\n");
        printf("1 - Cadastrar Consulta\n2 - Cancelar Consulta\n3 - Listar consultas\n4 - Encerrar programa\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if (totalConsultas < MAXIMO_CONSULTAS) {
                    printf("Preencha os dados abaixo: \n");
                    adicionarConsulta(totalConsultas, listaDeConsultas);
                    totalConsultas++;
                } else {
                    printf("Numero maximo de consultas atingido!\n");
                }
                break;
            case 2:
                cancelarConsulta(&totalConsultas, listaDeConsultas);
                break;
            case 3:
                printf("\nListando suas consultas: \n");
                listarConsultas(totalConsultas, listaDeConsultas);
                break;
            case 4:
                for (i = 0; i < totalConsultas; i++) {
                    free(listaDeConsultas[i].nomePaciente);
                    free(listaDeConsultas[i].dataHora);
                    free(listaDeConsultas[i].nomeMedico);
                }
                printf("Programa encerrado.\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
