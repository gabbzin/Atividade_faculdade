#include <stdio.h>

int main(){
    printf("\n\n===== Verificador de notas =====\n\n");
    
    // Criando as variáveis e coletando as informações
    float primeiraNota;
    float segundaNota;

    printf("Digite sua primeira nota: ");
    scanf("%f", &primeiraNota);

    printf("Digite sua segunda nota: ");
    scanf("%f", &segundaNota);

    if ((primeiraNota > 100) || (segundaNota > 100)){
        printf("\nNao foi possivel calcular a media, pois as notas sao inexistentes");
    } else {
        // Calculando a média final
        float mediaFinal = (primeiraNota + segundaNota) / 2;
        
        if(mediaFinal >= 70){
            printf("\nAprovado!");
        } else if ((mediaFinal > 40) && (mediaFinal < 70)) {
            printf("\nEm exame final!");

            // Exame final
            float notaExame;

            printf("\nAgora digite a nota do exame final\n");
            scanf("%f", notaExame);

            if (notaExame > 100){
                printf("A nota do exame nao pode ser maior que 100.\nTente novamente.");
            } else{
                float resultadoFinal = mediaFinal + notaExame;

                if (resultadoFinal >= 100){
                    printf("O aluno esta aprovado!");   
                } else {
                    printf("O aluno esta reprovado!");
                }
            }

        } else {
            printf("\nReprovado!");
        }
    }
}