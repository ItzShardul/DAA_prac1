#include <stdio.h>
#include <math.h>
#include <time.h>

double binarySearchSqrt(double n, int iterations) {
    double low = 0.0, high = n;
    if (n < 1.0) high = 1.0;
    double mid;

    for (int i = 0; i < iterations; i++) {
        mid = (low + high) / 2.0;
        if (mid * mid < n)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2.0;
}

int main() {
    double number = 1000000.0;
    int iterations = 50;

    clock_t start = clock();
    double result = binarySearchSqrt(number, iterations);
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Binary Search Method: Square root of %.0f is %.9f\n", number, result);
    printf("Time taken by Binary Search method (%d iterations): %lf seconds\n", iterations, duration);

    return 0;
}
