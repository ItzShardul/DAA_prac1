#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + (float)rand() / RAND_MAX * (max - min);
    }
}

int findMin(float arr[], int n){
    for(int i = 0; i < n; i++){
        int Min = 1;
        for(int j = 0; j < n; j++){
            if(arr[j] < arr[i]){
                Min = 0;
                break;
            }
        }
        if(Min) 
            return i;
    }
    return -1;
}

int main(){
    int n = 100000;
    float arr[n];

    generateData(arr, n, -20, 50);

    clock_t start = clock();
    int minIndex = findMin(arr, n);
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum temperature found = %.2f°C\n", arr[minIndex]);
    printf("Time taken using Naive Pairwise Comparison = %lf seconds\n", duration);
    return 0;
}
