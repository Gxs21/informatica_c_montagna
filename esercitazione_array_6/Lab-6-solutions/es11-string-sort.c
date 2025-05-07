#include <stdio.h>

void char_sort(char string[]);
int char_min(char string[], int start_index);

int main(void) {   

    char string1[] = "giovanni";
    char_sort(string1);
    printf("String 'giovanni' after sort: '%s'\n", string1);

    char string2[] = "Fondamenti di Informatica";
    char_sort(string2);
    printf("String 'Fondamenti di Informatica' after sort: '%s'\n", string2);

    char string3[] = "";
    char_sort(string3);
    printf("String '' after sort: '%s'\n", string3);

    char string4[] = "ciao";
    char_sort(string4);
    printf("String 'ciao' after sort: '%s'\n", string4);

}

void char_sort(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        int min_index = char_min(string, i);
        char tmp = string[min_index];
        string[min_index] = string[i];
        string[i] = tmp;
    }
}

int char_min(char string[], int start_index) {
    int min_index = start_index;
    char min = string[start_index];

    for (int i = start_index + 1; string[i] != '\0'; i++) {
        if (string[i] < min) {
            min = string[i];
            min_index = i;
        }
    }

    return min_index;
}
