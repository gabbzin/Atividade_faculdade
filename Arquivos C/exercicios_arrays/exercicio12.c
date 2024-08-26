#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#define MAX_SIZE 15

void inserirElemento(int array[], int *tamanho, int maximo, int valor, int indice){
    int i; // Declaração da variável que vai ser usada no for
    // Verificando se há espaço para adicionar outro elemento
    if(valor > maximo){
        printf("Nao e possivel adicionar outro elemento, pois o array esta cheio!\n");
        return;
    }
    // Verificando se o indice é válido
    if(indice < 0 || indice > *tamanho){
        printf("Indice invalido!\n");
        return;
    }

    // Movendo os valores após o indice escolhido para frente
    for(i = *tamanho; i > indice; i--){
        array[i] = array[i-1];
    }
    // Inserindo o valor
    array[indice] = valor;

    // Aumentando o tamanho de elementos do array
    (*tamanho)++;
}
int main(){
    int array[MAX_SIZE] = {10, 20, 30, 40, 50};
    int tamanho = 5;
    int adicionarValor, indice, forloop, i = 10;

    while(TRUE){
        printf("\n\n -- Pode adicionar mais %d valores -- \n\n", i);

        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &adicionarValor);

        printf("Em qual indice deseja adicionar o valor: ");
        scanf("%d", &indice);

        inserirElemento(array, &tamanho, MAX_SIZE, adicionarValor, indice);

        printf("\n\n");

        printf("Se deseja adicionar outro numero, digite 1 \n");
        printf("Se nao deseja adicionar outro numero, digite qualquer outro numero \n");

        printf("Sua escolha: ");
        scanf("%d", &forloop);
        
        printf("\n\n");

        if(forloop == 1){
            i--;
            continue;
        } else {
            break;
        }
    }

    for(i = 0; i < tamanho; i++){
        printf("%d, ", array[i]);
    }

    return 0;
    
}