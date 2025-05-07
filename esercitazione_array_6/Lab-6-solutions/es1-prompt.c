
#include <stdio.h>

void prompt_array(int array[], int size);
void print_array(int array[], int size);

int main(void) {
    int n;
    do {
        printf("Inserire una dimensione:\n> ");
        scanf("%d", &n);
    } while(n <= 0);

    int array[n];
    prompt_array(array, n);
    print_array(array, n);
    return 0;
}

void prompt_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Inserire il numero in posizione %d:\n> ", i);
        scanf("%d", &(array[i]));
    }
}

void print_array(int array[], int size) {
    printf("%d", array[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", array[i]);
    }
    printf("\n");
}
