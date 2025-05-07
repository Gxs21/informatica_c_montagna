#include <stdio.h>

#define MAX_LENGTH 9

int string_search(char strings[][MAX_LENGTH], int n, char key[]);
int string_equal(char string1[], char string2[]);

int main(void) {
    char contacts[][MAX_LENGTH] = {"andrea", "mirko", "giovanni", "matteo", "roberto", "danilo"};
    const int n = sizeof(contacts) / MAX_LENGTH;

    int indexOfGiovanni = string_search(contacts, n, "giovanni");
    int indexOfAlessandro = string_search(contacts, n, "alessandro");

    printf("Giovanni è in posizione %d.\n", indexOfGiovanni); // 2

    printf("Alessandro è in posizione %d.\n", indexOfAlessandro); // -1
}

int string_search(char strings[][MAX_LENGTH], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (string_equal(strings[i], key)) {
            return i;
        }
    }
    return -1;
}

int string_equal(char string1[], char string2[]) {
    int i;
    for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++) {
        if (string1[i] != string2[i]) {
            return 0;
        }
    }
    return string1[i] == string2[i];
}
