#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Si realizzi una funzione `concat_all` che, dato in ingresso un array di stringhe qualsiasi, 
 * e la dimensione di tale array, ne produca la concatenazione in un'unica stringa.
 * In particolare, la funzione restituisce una NUOVA stringa, contentente tutti i caratteri 
 * delle stringhe presenti nell'array, nell'ordine in cui queste appaiono nell'array.
 * E' responsabilità della funzione allocare la minimima quantità di memoria necessaria per
 * contenere il risultato. 
 * 
 * Quindi, ad esempio, dato l'array { "ciao", " ", "mondo", "!" } contenente 4 stringhe, 
 * la funzione restituisce: "ciao mondo!"
 * 
 * Suggerimenti e vincoli:
 * - si faccia attenzione ai caratteri di terminazione delle stringhe
 * 
 * - è possibile ed anche consigliato utilizzare le funzioni di libreria `strlen` e `strcpy`:
 * 
 *      char *strcpy( char *dest, const char *src );
 *              Copies the null-terminated byte string pointed to by src, including the null terminator, 
 *              to the character array whose first element is pointed to by dest.
 * 
 *      size_t strlen( const char *str );
 *              Returns the length of the given null-terminated byte string.
 *              (size_t is an implementation-defined unsigned integer type)
 * 
 * - la propria soluzione va inserita nella porzione del sorgente inclusa tra i commenti single-line
 *   `// STUDENT-SOLUTION-START` e  `// STUDENT-SOLUTION-END`.
 *   Codice scritto al di fuori di tali commenti non sarà considerato durante la valutazione.
 * 
 * - è possibile ed anche consigliato realizzare funzioni ausiliarie, purche comprese tra la coppia di commenti suddetti
 * 
 * - ATTENZIONE: la soluzione verrà confrontata con quella dei colleghi mediante strumenti automatici al fine 
 *   di rilevare potenziali copiature. Il controllo è resistente a rename di variabili, spezzamento di espressioni etc.
 *   Qualora vengano riscontrate similarità importanti, è possibile che la prova possa venire annullata, e che ulteriori
 *   modalità di verifica di competenze (ad es., prove orali) siano attuate. 
 */
char *concat_all(char** strings, int strings_count);
int test_concat_all(char** strings, int strings_count, char *expected);

// STUDENT-SOLUTION-START
char *concat_all(char** strings, int strings_count) {
    int total_length = 0;
    for (int i = 0; i < strings_count; i++) {
        total_length += strlen(strings[i]);
    }
    char *result = malloc(total_length + 1);
    int result_index = 0;
    for (int i = 0; i < strings_count; i++) {
        const char *current = strings[i];
        for (int j = 0; current[j] != '\0'; j++) {
            result[result_index++] = current[j];
        }
    }
    result[result_index] = '\0';
    return result;
}
// STUDENT-SOLUTION-START

int main() {
    int status = 0;

    char *input1[] = { "abc", "ABC", "123" };
    status |= test_concat_all((char **) input1, 3, "abcABC123");

    char *input2[] = { "abc", "AB", "1" };
    status |= test_concat_all((char **) input2, 3, "abcAB1");

    char *input3[] = { "a", "AB", "123" };
    status |= test_concat_all((char **) input3, 3, "aAB123");

    char *input4[] = { "hello", " ", "world", "!" };
    status |= test_concat_all((char **) input4, 4, "hello world!");

    char *input5[] = { "just one" };
    status |= test_concat_all((char **) input5, 1, "just one");

    status |= test_concat_all(NULL, 0, "");

    char *input7[] = { "", "ciao", "", "mondo", "" };
    status |= test_concat_all((char **) input7, 5, "ciaomondo");

    return status;
}

int test_concat_all(char** strings, int strings_count, char *expected) {
    printf("Concatenating the following strings:\n");
    for (int i = 0; i < strings_count; i++) {
        printf("\t- '%s'\n", strings[i]);
    }
    printf("Results:\n");
    printf("\texpected: '%s'\n", expected);
    char *actual = concat_all(strings, strings_count);
    if (expected == NULL) {
        printf("\t  actual: NULL\n");
    } else {
        printf("\t  actual: '%s'\n", actual);
    }
    if (strcmp(expected, actual) == 0) {
        printf("\tOK!\n");
        return 0;
    } else {
        printf("\tERROR: unexpected result!\n");
        return 1;
    }
}
