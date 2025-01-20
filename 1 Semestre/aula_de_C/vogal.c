#include <stdio.h>
#include <ctype.h>

int main(){
    char letra;
    
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    letra = tolower(letra);

    switch (letra){
    case 'a':
        printf("Vogal");
        break;
    case 'e':
        printf("Vogal");
        break;
    case 'i':
        printf("Vogal");
        break;
    case 'o':
        printf("Vogal");
        break;
    case 'u':
        printf("Vogal");
        break;
    default:
        if (isalpha(letra)){
            printf("Consoante");
        } else if (ispunct(letra)){
            printf("Sinal de pontuacao");
        }
        else{
            printf("Nao e uma letra e nem um sinal de pontuacao");
        }
        break;
    }

    return 0;
}