#include <stdio.h>

int string_find(char string[], char character);
int char_equal(char c1, char c2);

int main(void) {   

    char string1[] = "giovanni";
    printf("Position of '%c' in '%s': %d\n", 'A', string1, string_find(string1, 'A'));

    char string2[] = "Fondamenti di Informatica";
    printf("Position of '%c' in '%s': %d\n", ' ', string2, string_find(string2, ' '));

    char string3[] = "";
    printf("Position of '%c' in '%s': %d\n", 'b', string3, string_find(string3, 'b'));

}

int string_find(char string[], char character) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (char_equal(character, string[i])) {
            return i;
        }
    }
    return -1;
}

int char_equal(char c1, char c2) {
    if (c1 >= 'a' && c1 <= 'z') {
        c1 -= ('a' - 'A');
    }
    if (c2 >= 'a' && c2 <= 'z') {
        c2 -= ('a' - 'A');
    }
    return c1 == c2;
}
