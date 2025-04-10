#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *v, int n){
    if (n < 1) return;

    for (int i = 0; i < n; i++){
        if (v[i] > v[i+1]){
            swap(&v[i], &v[i+1]);
        }
    }

    bubbleSort(v, n - 1);
}

int main(){
    int vetor[8] = {150, 75, 200, 50, 100, 175, 125, 25};
    int i;

    bubbleSort(vetor, 7);

    for (i = 0; i < 8; i++){
        printf("%d ", vetor[i]);
    }
    
    return 0;
}