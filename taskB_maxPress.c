#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePressureData(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + (float)rand() / RAND_MAX * (max - min);
    }
}

int findMaxNaive(float arr[], int n){
    for(int i = 0; i < n; i++){
        int Max = 1;
        for(int j = 0; j < n; j++){
            if(arr[j] > arr[i]){
                Max = 0;
                break;
            }
        }
        if(Max) 
            return i;
    }
    return -1;
}

int main(){
    int n = 100000;
    float arr[n];

    generatePressureData(arr, n, 950, 1050);

    clock_t start = clock();
    int maxIndex = findMaxNaive(arr, n);
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Maximum pressure found = %.2f\n", arr[maxIndex]);
    printf("Time taken using Naive Pairwise Comparison = %lf seconds\n", duration);
    return 0;
}
