#include <stdio.h>

void inverse_print(int array[], int size);

#define N 10

int main(void) {
    int array[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    inverse_print(array, N);
    return 0;
}

void inverse_print(int array[], int size) {
    printf("%d", array[size - 1]);
    for (int i = size - 2; i >= 0; i--) {
        printf(", %d", array[i]);
    }
    printf("\n");
}