#include <stdio.h>
#include <string.h>

int main(){
    char frase[50];
    FILE *arquivo = fopen("arquivo.txt", "a+");

    if (arquivo == NULL){
        return 1;
    }

    printf("Digite uma mensagem: ");
    fgets(frase, 50, stdin);

    fprintf(arquivo, "%s", frase);

    printf("Frase escrita no arquivo!");

    fclose(arquivo);

    return 0;
}