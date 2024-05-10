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
        }
        else{
            printf("Nao e uma letra");
        }
        break;
    }

    return 0;
}