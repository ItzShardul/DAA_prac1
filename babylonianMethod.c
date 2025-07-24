#include <stdio.h>
#include <math.h>
#include <time.h>

double babylonianSqrt(double n, int iterations) {
    double x = n;
    double y = 1.0;

    for (int i = 0; i < iterations; i++) {
        x = (x + y) / 2.0;
        y = n / x;
    }

    return x;
}

int main() {
    double number = 1000000.0;
    int iterations = 7;

    clock_t start = clock();
    double result = babylonianSqrt(number, iterations);
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Babylonian Method: Square root of %.0f is %.9f\n", number, result);
    printf("Time taken by Babylonian method (%d iterations): %lf seconds\n", iterations, duration);

    return 0;
}
