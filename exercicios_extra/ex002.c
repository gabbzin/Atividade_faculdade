#include <stdio.h>
#include <ctype.h>
#include <string.h>

void isValidInput(float real, float fatorConversao){
    int i, contador = 0;
    char str[20], digito_char;

    snprintf(str, sizeof(str), "%.2f", real);

    for (i = 0; str[i] != '\0'; i++){
        digito_char = str[i];

        if (digito_char == '.'){
            contador ++;
            if(contador > 1){
                printf("Voce digitou varios '.'");
                return;
            }
            continue;
        } else if(!isdigit(digito_char)){
            printf("Digite numero valido\n");
        }
    }

    float euro = real / fatorConversao;

    printf("Deu %.2f", euro);
}

int main(){
    float real, fatorConversao = 5.94573;
    printf("Digite o valor em reais para converter para euro: ");
    scanf("%f", &real);

    isValidInput(real, fatorConversao);

    return 0;
}