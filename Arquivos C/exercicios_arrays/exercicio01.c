#include <stdio.h>

int main(){
    int i = 0, numeros[3] = {2, 4, 6};
    
    while (i < 3){
        printf("%d, ", numeros[i]);
        i++;
    }

    return 0;
}