#include <stdio.h>

int main(){
    int ultimo = 0, penultimo = 1, termo; // Varíaveis para montar a sequência de Fibonacci
    int numero, i = 3; // Variável que indicará quantos números da sequência irá aparecer

    // Coletando os dados
    printf("Digite quantos numeros da sequencia de Fibonacci deseja ver: ");
    scanf("%d", &numero);

    printf("A sequencia de Fibonacci: ");
    
    if (numero == 1){
        printf("0");
    } else if (numero == 2){
        printf("0, 1");
    } else {
        printf("0, 1");
        while (i <= numero){
            termo = ultimo + penultimo;

            printf(", %d", termo);

            ultimo = penultimo;
            penultimo = termo;

            i++;
        }
    }
    
    return 0;
}