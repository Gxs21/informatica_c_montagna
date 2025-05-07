#include <stdio.h>

double scalar_product(double x[], double y[], int size);

#define N 3

int main(void) {
    double x[] = { 1.0, -2.0, 4.0 };
    double y[] = { -1.0, 0.5, 0.25 };
    printf("Scalar product = %g\n", scalar_product(x, y, N)); // -1
    return 0;
}

double scalar_product(double x[], double y[], int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += x[i] * y[i];
    }
    return result;
}