#include <stdio.h>

int main(){
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade < 16){
        printf("Nao pode votar!");
    } else if (idade >= 18 && idade <= 65){
        printf("Voto obrigatorio!");
    } else {
        printf("Voto opcional");
    }

    return 0;
}