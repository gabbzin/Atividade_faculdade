#include <stdio.h>

int calcularDeterminante(int mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

int main() {
    int i, j;
    int A[3][3], B[3];

    printf("\n\nFormato das equacoes. Exemplo: ax + by + cz = d \n\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (j < 3) {
                printf("Digite o valor da %d linha e %d coluna: ", i + 1, j + 1);
                scanf("%d", &A[i][j]);
            } else {
                printf("Digite o valor do termo independente da %d linha: ", i + 1);
                scanf("%d", &B[i]);
            }
        }
    }

    int determinanteGeral = calcularDeterminante(A);

    if (determinanteGeral == 0) {
        printf("O sistema não tem solucao unica.\n");
        return 1;
    }

    // Matriz A1 (substituindo a primeira coluna de A por B)
    int A1[3][3] = {
        {B[0], A[0][1], A[0][2]},
        {B[1], A[1][1], A[1][2]},
        {B[2], A[2][1], A[2][2]}
    };

    // Matriz A2 (substituindo a segunda coluna de A por B)
    int A2[3][3] = {
        {A[0][0], B[0], A[0][2]},
        {A[1][0], B[1], A[1][2]},
        {A[2][0], B[2], A[2][2]}
    };

    // Matriz A3 (substituindo a terceira coluna de A por B)
    int A3[3][3] = {
        {A[0][0], A[0][1], B[0]},
        {A[1][0], A[1][1], B[1]},
        {A[2][0], A[2][1], B[2]}
    };

    // Calculando o Dx, Dy e Dz
    double detA1 = calcularDeterminante(A1);
    double detA2 = calcularDeterminante(A2);
    double detA3 = calcularDeterminante(A3);

    // Soluções
    double x1 = detA1 / determinanteGeral;
    double x2 = detA2 / determinanteGeral;
    double x3 = detA3 / determinanteGeral;

    printf("Solucoes: \nx = %.2lf \ny = %.2lf \nz = %.2lf \n", x1, x2, x3);

    return 0;
}
