#include <stdio.h>

int string_length(char string[]);

int main(void) {   

    char string1[] = "giovanni";
    printf("Length of '%s' is %d\n", string1, string_length(string1));

    char string2[] = "fondamenti di informatica";
    printf("Length of '%s' is %d\n", string2, string_length(string2));

    char string3[] = "";
    printf("Length of '%s' is %d\n", string3, string_length(string3));
}

int string_length(char string[]) {
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}
