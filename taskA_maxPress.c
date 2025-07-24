#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void generateData(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + (float)rand() / RAND_MAX * (max - min);
    }
}

int findMax(float arr[], int n){
    int max = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int n = 1000000;
    float arr[n];
    generateData(arr, n, 950, 1050);

    // Timing start
    clock_t start, end;
    double duration;
    start = clock();

    int maxIndx = findMax(arr, n);

    end = clock();
    duration = ((double) (end - start)) / CLOCKS_PER_SEC;
    // Timing end

    printf("Max value of pressure is = %.2f\n", arr[maxIndx]);
    printf("Time taken to find min = %lf seconds\n",duration);

    return 0;
}
