#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Custom comparator
int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void generateData(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + (float)rand() / RAND_MAX * (max - min);
    }
}

int linearSearch(float arr[], int n, float x){
    for(int i = 0; i < n; i++){
        if(arr[i] >= x)
            return i;
    }
    return -1;
}

int binarySearch(float arr[], int n, float x){
    int low = 0, high = n - 1, result = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    int n = 1000000;
    float arr[n];
    float x = 30.0;

    srand(time(NULL));
    generateData(arr, n, -20, 50);

    // Sort the temperature array
    qsort(arr, n, sizeof(float), comp);

    // Timing Linear Search
    clock_t start1 = clock();
    int linIndex = linearSearch(arr, n, x);
    clock_t end1 = clock();
    double linDuration = ((double)(end1 - start1)) / CLOCKS_PER_SEC;

    // Timing Binary Search
    clock_t start2 = clock();
    int binIndex = binarySearch(arr, n, x);
    clock_t end2 = clock();
    double binDuration = ((double)(end2 - start2)) / CLOCKS_PER_SEC;

    if (linIndex != -1)
        printf("Linear Search: First occurrence of temperature >= %.1f°C is %.2f°C at index %d\n", x, arr[linIndex], linIndex);
    else
        printf("Linear Search: No temperature >= %.1f°C found\n",x);

    printf("Time taken by Linear Search = %lf seconds\n", linDuration);

    if (binIndex != -1)
        printf("Binary Search: First occurrence of temperature >= %.1f°C is %.2f°C at index %d\n", x, arr[binIndex], binIndex);
    else
        printf("Binary Search: No temperature >= %.1f°C found\n", x);

    printf("Time taken by Binary Search = %lf seconds\n", binDuration);

    return 0;
}
