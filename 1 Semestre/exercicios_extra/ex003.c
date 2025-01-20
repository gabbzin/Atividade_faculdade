#include <stdio.h>

int main(){
    char frase[50];
    FILE *arquivo = fopen("arquivo.txt", "a+");

    if (arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Digite a frase que sera gravada no arquivo: ");
    fgets(frase, sizeof(frase), stdin);

    fprintf(arquivo, "%s", frase);

    fclose(arquivo);

    return 0;
}