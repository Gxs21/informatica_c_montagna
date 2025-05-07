#include <stdio.h>
#include <stdlib.h> // for rand()

#define SIZE 100

void print_array(int array[], int size);
void rand_init(int array[], int size);
int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]);
int count_occurrences(int array[], int size, int n, int indexes[]);
void array_copy(int source[], int size, int destination[]);

int main(void) {   
    int array[SIZE];

    rand_init(array, SIZE);
    print_array(array, SIZE);

    const int k = 3;
    int indexes[k];
    int result[1];
    if (has_k_occurrences(array, SIZE, k, indexes, result)) {
        printf("Number %d occurs exactly %d times:\n", result[0], k);
        for (int i = 0; i < k; i++) {
            printf("\tfor example in position: %d\n", indexes[i]);
        }
    } else {
        printf("No number occurs exactly %d times\n", k);
    }
}

void print_array(int array[], int size) {
    printf("%d", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("\n");
}

void rand_init(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 100);
    }
}

int count_occurrences(int array[], int size, int n, int indexes[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == n) {
            indexes[count] = i;
            count++;
        }
    }
    return count;
}

int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]) {
    int positions[size];
    for (int i = 0; i < size; i++) {
        int current = array[i];
        int occurrences = count_occurrences(array, size, current, positions);
        if (occurrences == k) {
            results[0] = current;
            array_copy(positions, k, indexes);
            return 1;
        }
    }
    return 0;
}

void array_copy(int source[], int size, int destination[]) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}
