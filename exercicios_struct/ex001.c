#include <stdio.h>
#include <windows.h>

void sleep(int segundos);

int main(){
    int timer, i;

    printf("Digite os segundos do timer: ");
    scanf("%d", &timer);

    for(i = timer; i >= 0; i--){
        printf("%d \n", i);

        sleep(1);
    }

    return 0;
}

void sleep(int segundos){
    return Sleep(segundos * 1000);
}