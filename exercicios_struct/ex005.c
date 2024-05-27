#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_CONSULTAS 20

typedef struct{
    char nomePaciente;
    char dataHora; // Formato DD/MM/AAAA/HH:MI
    char nomeMedico;
} consulta;

void adicionarConsulta(int indice, consulta *lista){
    char buffer[50];
    char dataHoraBuffer[20];

    int *data = malloc(3 * sizeof(int));
    int *hora = malloc(2 * sizeof(int));

    printf("Nome do Paciente: ");
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);

    lista[indice].nomePaciente = strdup(buffer);

    printf("Preencha data e hora usando numeros no formato (DD/MM/AAAA  Hora:Minuto)\n");

    printf("Dia da consulta: \n");
    scanf("%d", &data[0]);
    printf("Mes da consulta: \n");
    scanf("%d", &data[1]);
    printf("Ano da consulta: \n");
    scanf("%d", &data[2]);

    printf("Hora da consulta: ");
    scanf("%d", &hora[0]);
    printf("Minutagem: ");
    scanf("%d", &hora[1]);

    // Formatando a data e hora em um buffer
    snprintf(dataHoraBuffer, sizeof(dataHoraBuffer), "%02d/%02d/%04d %02d:%02d", data[0], data[1], data[2], hora[0], hora[1]);
    lista[indice].dataHora = strdup(dataHoraBuffer);

    free(data);
    free(hora);

    printf("Nome do Medico: ");
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);

    lista[indice].nomeMedico = strdup(buffer);
}
int main(){
    consulta listaDeConsultas[MAXIMO_CONSULTAS];
    int i=0 /*Indice de consulta*/, opcao;

    printf("\n\nSeja bem-vindo a assistencia de consultas.\n\n");
    while (1){ // Loop infinito
        printf("====== Total de consultas: %d ====== \n\n", i);
        printf("Por favor escolha uma opcao:\n");
        printf("1 - Cadastrar Consulta\n2 - Cancelar Consulta\n3 - Listar consultas\n4 - Encerrar programa\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        fflush(stdin);

        switch(opcao){
            case 1:
                printf("Preencha os dados abaixo: \n");
                adicionarConsulta(i, listaDeConsultas);
                i++;
            case 2:
            case 3:
            case 4:
                return 0;
                break;

            default:
                printf("Opcao invalida!");
                break;
        }
    }
}