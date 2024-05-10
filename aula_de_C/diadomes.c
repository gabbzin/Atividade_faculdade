#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Meses: Janeiro, Fevereiro, Março, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro*/

int main(){
    char mes[10], inicioMes;
    int i = 0;

    printf("Digite um mes: ");
    scanf("%s", &mes);

    while(mes[i] != '\0'){
        mes[i] = tolower(mes[i]);
        i++;
    }

    inicioMes = mes[0];

    switch(inicioMes){
        case 'j':
            if (strcmp(mes, "janeiro") == 0 || strcmp(mes, "julho") == 0){
                printf("O mes %s tem 31 dias", mes);
            } else if (strcmp(mes, "junho") == 0){
                printf("O mes %s tem 30 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'f':
            if (strcmp(mes, "fevereiro") == 0){
                printf("O mes %s tem 28 ou 29 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'm':
            if (strcmp(mes, "marco") == 0 || strcmp(mes, "maio") == 0){
                printf("O mes %s tem 31 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'a':
            if (strcmp(mes, "abril") == 0){
                printf("O mes %s tem 30 dias", mes);
            } else if (strcmp(mes, "agosto") == 0){
                printf("O mes %s tem 31 dias", mes);
            } else {
                printf("Mes invalido"); 
            }
            break;
        case 's':
            if (strcmp(mes, "setembro") == 0){
                printf("O mes %s tem 30 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'o':
            if (strcmp(mes, "outubro") == 0){
                printf("O mes %s tem 31 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'n':
            if (strcmp(mes, "novembro") == 0){
                printf("O mes %s tem 30 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
        case 'd':
            if (strcmp(mes, "dezembro") == 0){
                printf("O mes %s tem 31 dias", mes);
            } else {
                printf("Mes invalido");
            }
            break;
    }
    return 0;
}