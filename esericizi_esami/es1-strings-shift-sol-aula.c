#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int string_equals(char a[], char b[]);
int check(char input[], int shift, char expected[]);
void print_string(char a[]);

/*
Realizzare una funzione `f(s)` con l'obiettivo di riempira una nuova stringa, determinata a partire dalla stringa `s` in input,
 mediante traslazione  (o shift) dei caratteri di tale stringa in input, verso destra o verso sinistra,  con traboccamento nella parte opposta.

Si consideri le seguenti corrispondenze di input/output:

* f("abcde", 5, N)
    * N = +1 => risultato "eabcd" (i caratteri scivolano verso destra, l'ultimo carattere "trabocca" e passa alla prima posizione)
    * N = -1 => risultato "bcdea" (i caratteri scivolano verso sinistra, il primo carattere "trabocca" e passa all'ultima posizione)
    * N = 0 => risultato "abcde"
    * N = 4 => risultato "bcdea"
    * N = 5 => risultato "abcde"
    * N = -5 => risultato "abcde"

Si noti che espressioni `x % N` restituiscono valori modulo `N` (ovvero tra 0..`N`) in valore assoluto,
ma preservano il segno. Quindi `-1 % 5` dà `-1`, e `-7 % 5` dà `-2`.

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
void f(char s[], int shift, char r[]) {
    int l = strlen(s);
    if (l>0){
        shift= (shift>0) ? shift%l : (shift+l)%l;

        int i;
        for(i=0; i<l-shift;i++){
            r[i+shift] = s[i];     
        }
        for( ; s[i]!=0; i++){
            r[i-(l-shift)] = s[i];
        }
    }
    
    r[l] = '\0';
}
// STUDENT-SOLUTION-END

void test(){
    check("abcde", 0, "abcde");
    check("abcde", 1, "eabcd");
    check("abcde", -1, "bcdea");
    check("abcde", 4, "bcdea");
    check("abcde", 5, "abcde");
    check("abcde", -5, "abcde");
    check("abcde", +7, "deabc");
    check("", 1, "");
    check("", 99, "");
    check("a", 0, "a");
    check("a", 99, "a");
}

int string_equals(char a[], char b[]) {
    return strcmp(a, b) == 0;
}

int check(char input[], int shift, char expected[]) {
    char result[strlen(input)];
    f(input, shift,result);
    int is_equal = string_equals(result, expected);
    printf("Test %s: input=\"%s\",\tshift=%2d, expected=\"%s\",\tgot=\"%s\"\n",
           is_equal ? "PASSED" : "FAILED", input, shift, expected, result);
    //free(result);
    return is_equal;
}

void print_string(char a[]) {
    printf("%s\n", a);
}

int main() {
    test();
    return 0;
}