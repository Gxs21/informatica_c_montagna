#include <stdio.h>
#include <limits.h> // for INT_MAX
#include <stdlib.h> // for rand()

#define SIZE 20

void print_array(long array[], int size);
void rand_init(long array[], int size);
int twomax(long array[], int size, int indexes[], long results[]);

int main(void) {   
    long array[SIZE];

    rand_init(array, SIZE);
    print_array(array, SIZE);

    int max_indexes[2];
    long max_values[2];
    int results = twomax(array, SIZE, max_indexes, max_values);

    printf("Trovati %ld massimi:\n", results);
    for (int i = 0; i < results; i++) {
        printf("\tMax%d = %ld, avente indice %d\n", i + 1, max_values[i], max_indexes[i]);
    }
}

void print_array(long array[], int size) {
    printf("%ld", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %ld", array[i]);
    }
    printf("\n");
}

void rand_init(long array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 100);
    }
}

int twomax(long array[], int size, int indexes[], long results[]) {
    if (size <= 0) return -1;
    if (size == 1) {
        indexes[0] = 0;
        results[0] = array[0];
        return 1;
    }

    int index1 = 0, index2;
    long max1 = array[index1], max2;
    for (int i = 1; i < size; i++) {
        long current = array[i];
        if (current > max1) {
            max2 = max1;
            index2 = index1;
            max1 = current;
            index1 = i; 
        } else if (current > max2) {
            max2 = current;
            index2 = i;
        }
    }

    indexes[0] = index1;
    indexes[1] = index2;
    results[0] = max1;
    results[1] = max2;
    return 2;
}
