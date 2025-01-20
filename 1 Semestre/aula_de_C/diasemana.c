#include <stdio.h>

int diames(int day);

int main(){
    int dia;

    printf("Digite o numero do dia do ano: ");
    scanf("%d", &dia);

    diames(dia);

    switch (dia){
        case 1:
            printf("Segunda-feira");
            break;
        case 2:
            printf("Terça-feira");
            break;
        case 3:
            printf("Quarta-feira");
            break;
        case 4:
            printf("Quinta-feira");
            break;
        case 5:
            printf("Sexta-feira");
            break;
        case 6:
            printf("Sábado");
            break;
        case 7:
            printf("Domingo");
            break;
        default:
            printf("Dia invalido");
            break;
    }

    return 0;
}

int diames(int day){
    if (day <= 7){
        return day;
    } else {
        return diames(day - 7);
    }
}