#include <stdio.h>
#define SEGUNDOS_POR_ANO 31536000

int main(){
    int idade;
    long long int idadeSegundos;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    idadeSegundos = (long long int) idade * SEGUNDOS_POR_ANO;

    printf("Voce viveu: %lld", idadeSegundos);

    return 0;
}