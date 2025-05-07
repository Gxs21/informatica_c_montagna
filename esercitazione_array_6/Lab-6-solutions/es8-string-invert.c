#include <stdio.h>

void invert_string(char string[], char result[]);
int string_length(char string[]);


int main(void) {   

    char string1[] = "giovanni";
    char string1_inv[sizeof(string1)];
    invert_string(string1, string1_inv);
    printf("Inversion of '%s' is '%s'\n", string1, string1_inv);

    char string2[] = "fondamenti di informatica";
    char string2_inv[sizeof(string2)];
    invert_string(string2, string2_inv);
    printf("Inversion of '%s' is '%s'\n", string2, string2_inv);

    char string3[] = "";
    char string3_inv[sizeof(string3)];
    invert_string(string3, string3_inv);
    printf("Inversion of '%s' is '%s'\n", string3, string3_inv);
}

void invert_string(char string[], char result[]) {
    int length = string_length(string);
    for (int i = 0; i < length; i++) {
        result[length - 1 - i] = string[i];
    }
}

int string_length(char string[]) {
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}
