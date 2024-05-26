#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_CONSULTAS 20

typedef struct{
    char nomePaciente;
    char dataHora[17]; // Formato DD/MM/AAAA/HH:MI
    char nomeMedico;
} consulta;

void adicionarConsulta(int indice, consulta *lista){
    char buffer[50];

    int *data = malloc(3 * sizeof(int));
    int *hora = malloc(2 * sizeof(int));

    printf("Nome do Paciente: ");
    fgets(buffer, sizeof(buffer), stdin);

    lista[indice].nomePaciente = buffer;

    printf("Preencha data e hora usando numeros no formato (DD/MM/AAAA  Hora:Minuto)\n");

    printf("Dia da consulta: \n");
    scanf("%d", &data[0]);
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