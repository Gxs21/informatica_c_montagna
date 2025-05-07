#include <stdio.h>
#include <limits.h> // for INT_MAX
#include <stdlib.h> // for rand()

#define SIZE 20

void print_array(double array[], int size);
void rand_init(double array[], int size);
int min(double array[], int size, double result[]);

int main(void) {   
    double array[SIZE];

    rand_init(array, SIZE);
    print_array(array, SIZE);

    double min_value[1];
    int min_index = min(array, SIZE, min_value);


    printf("Min: %g, of index %d\n", min_value[0], min_index);
}

void print_array(double array[], int size) {
    printf("%g", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %g", array[i]);
    }
    printf("\n");
}

void rand_init(double array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 100) / 100.0;
    }
}

int min(double array[], int size, double result[]) {
    if (size <= 0) return -1;

    double min = array[0];
    int min_index = 0;
    
    for (int i = 1; i < size; i++) {
        double current = array[i];
        if (current < min) {
            min = current;
            min_index = i;
        }
    }

    result[0] = min;
    return min_index;
}