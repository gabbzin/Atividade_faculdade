#include <stdio.h>

int main(){
    int nota;
    printf("Digite sua nota: ");
    scanf("%d", &nota);

    switch(nota){
        case 3:
            printf("EM RECUPERACAO");
            break;
        case 5:
            printf("REPROVADO");
            break;
        case 7:
            printf("APROVADO");
            break;
        default:
            printf("E necessario entrar em contato com a coordenacao do curso");
            break;
    }

    return 0;
}