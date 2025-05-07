#include <stdio.h>
#include <stdlib.h> // for rand()

#define SIZE 100
#define MAX 10

void print_array(unsigned int array[], unsigned int size);
void rand_init(unsigned int array[], unsigned int size, unsigned int max);
void histogram(unsigned int array[], unsigned int size, unsigned int occurrences[]);

int main(void) {   
    int array[SIZE];

    rand_init(array, SIZE, MAX);
    print_array(array, SIZE);

    unsigned int occurrences[MAX] = {};
    histogram(array, SIZE, occurrences);

    for (unsigned int i = 0; i < MAX; i++) {
        printf("Occurrences of %u: ", i);
        for (unsigned int j = 0; j < occurrences[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", occurrences[i]);
    }
}

void print_array(unsigned int array[], unsigned int size) {
    printf("%d", array[0]);
    for (unsigned int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("\n");
}

void rand_init(unsigned int array[], unsigned int size, unsigned int max) {
    for (unsigned int i = 0; i < size; i++) {
        array[i] = ((unsigned int) rand() % max);
    }
}

void histogram(unsigned int array[], unsigned int size, unsigned int occurrences[]) {
    for (unsigned int i = 0; i < size; i++) {
        unsigned int current = array[i];
        occurrences[current]++;
    }
}