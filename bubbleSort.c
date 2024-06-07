#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *v, int n){
    int i;
    if (n < 1)return;

    for(i = 0; i < n; i++){
        if(v[i] > v[i+1]){
            swap(&v[i], &v[i+1]);
        }
    bubbleSort(v, n - 1);
    }
}

int main(){
    int tamanho, i, *v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    
}