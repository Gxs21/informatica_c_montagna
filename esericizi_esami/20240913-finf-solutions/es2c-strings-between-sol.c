#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 400

int string_equals(char* a, char* b);
int check(char *s, char c, char *expected);
void print_string(char *a);

/*
Realizzare una funzione `between(s,c)` che, data una stringa s e un carattere c, 
restituire una NUOVA stringa contenente i caratteri compresi tra la prima e la seconda
occorrenza di c in s (escluse). Si assuma che il carattere c sia
sempre presente almeno due volte in s; di conseguenza, la stringa s
avrà sempre lunghezza maggiore o uguale a due. 

Ad esempio, se s = "abracadabra" e c='a', la funzione deve
restituire la stringa "br". Si faccia riferimento ai test per
ulteriori esempi.

Se lo si ritiene utile, è possibile usare la funzione strlen();
nessun'altra funzione definita nel file string.h puo' essere usata,
quindi niente strcpy(), strcat() e altre.

NOTE GENERALI:
*) ATTENZIONE: la propria soluzione va inserita nella porzione del sorgente inclusa tra i commenti single-line
`// STUDENT-SOLUTION-START` e  `// STUDENT-SOLUTION-END`.
Codice scritto al di fuori di tali commenti non sarà considerato durante la valutazione.
*) E' possibile definire più funzioni ausiliarie qualora lo si ritenga opportuno. 
Ma lo si faccia all'interno dei commenti, come indicato nel punto precedente.
*) ATTENZIONE: la soluzione verrà confrontata con quella dei colleghi mediante strumenti automatici al fine
di rilevare potenziali copiature. Il controllo è resistente a rename di variabili, spezzamento di espressioni etc.
Qualora vengano riscontrate similarità importanti, è possibile che la prova possa venire annullata, e che ulteriori
modalità di verifica di competenze (ad es., prove orali) siano attuate.
*/

// STUDENT-SOLUTION-START
char *between(char *s, char c)
{
    int prima, seconda;
    int src, dest;
    char *result;
    /* Cerchiamo la posizione della prima occorrenza di c in s */
    for (prima=0; s[prima] != c; prima++) ;
    /* Cerchiamo la posizione della seconda occorrenza di c in s */
    for (seconda = prima+1; s[seconda] != c; seconda++) ;
    /* Allochiamo lo spazio per il risultato */
    result = (char*)malloc(seconda-prima+1);
    /* Copiamo i caratteri */
    dest = 0;
    src = prima+1;
    while (src<seconda) {
        result[dest] = s[src];
        dest++;
        src++;
    }
    /* Aggiungiamo il terminatore */
    result[dest] = '\0';
    return result;
}

// STUDENT-SOLUTION-END

void test() {
    check("abcdefghijklmnopqrstuvwxyza", 'a', "bcdefghijklmnopqrstuvwxyz");
    check("abcbdbeb", 'b', "c");
    check("abracadabra", 'a', "br");
    check("supercalifragilistichespiralidoso", 'i', "frag");
    check("SuperCaliFragilistiCheSpiralidoso", 'C', "aliFragilisti");
    check("12341234", '2', "341");
    check("uno!due!tre", '!', "due");
    check("uno!!due!tre", '!', "");
    check(" uno due tre ", ' ', "uno");
    check("aa", 'a', "");
    check("aaa", 'a', "");
    check("abcDdefDD", 'D', "def");
    check("uno,due;tre,quattro,,", ',', "due;tre");
}

int string_equals(char* a, char* b) {
    if(a!=b && (a == NULL || b == NULL)) return 0;
    return strcmp(a, b) == 0;
}
 

int ntot = 0, npassed = 0;
int check(char *s, char c, char *expected) {
    ntot++;
    char *result = between(s, c);
    int is_equal = string_equals(result, expected);
    printf("Test %s: input=\"%s\", character=\"%c\", expected=\"%s\", got=\"%s\"\n",
           is_equal ? "PASSED" : "FAILED", s, c, expected, result);
    if(is_equal) npassed++;
    free(result);
    return is_equal;
}

void print_string(char *a) {
    printf("%s\n", a);
}

int main() {
    test();
    printf("Passed %d/%d tests.\n", npassed, ntot);
    return 0;
}
