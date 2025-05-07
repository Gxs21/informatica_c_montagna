#include <stdio.h>

int string_occurrences(char string[], char character);

int main(void) {   

    char string1[] = "giovanni";
    printf("Occrrences of '%c' in '%s': %d\n", 'n', string1, string_occurrences(string1, 'n'));
    printf("Occrrences of '%c' in '%s': %d\n", 'e', string1, string_occurrences(string1, 'e'));
    printf("Occrrences of '\\0' in '%s': %d\n", string1, string_occurrences(string1, '\0'));

    char string2[] = "fondamenti di informatica";
    printf("Occrrences of '%c' in '%s': %d\n", 'n', string2, string_occurrences(string2, 'n'));
    printf("Occrrences of '%c' in '%s': %d\n", 'e', string2, string_occurrences(string2, 'e'));
    printf("Occrrences of '\\0' in '%s': %d\n", string2, string_occurrences(string2, '\0'));

    char string3[] = "";
    printf("Occrrences of '%c' in '%s': %d\n", 'n', string3, string_occurrences(string3, 'n'));
    printf("Occrrences of '%c' in '%s': %d\n", 'e', string3, string_occurrences(string3, 'e'));
    printf("Occrrences of '\\0' in '%s': %d\n", string3, string_occurrences(string3, '\0'));
}

int string_occurrences(char string[], char character) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (character == string[i]) {
            count++;
        }
    }
    return count;
}
