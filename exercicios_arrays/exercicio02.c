#include <stdio.h>

int main(){
    int i = 0, j = 0;
    int numbers[4][4] = {{0}, {0}, {0}, {0}};

    while (i < 4){
        j = 0;
        
        while (j < 4){
            if (i % 2 == 0){
            numbers[i][j] = 1;
            }

            printf("%d, ", numbers[i][j]);
            j++;
        }

        printf("\n");
        i++;
    }

    return 0;
}