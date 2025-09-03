#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // cf. INT_MAX, INT_MIN
#include <stdarg.h> // for variadic functions

const char NON_DEC_LENGTHS = 1;
const char NON_DEC_SUMS = 2;

typedef struct list {
    int val;
    struct list *next;
} list;

typedef struct lol {
    struct list *val;
    struct lol *next;
} list_of_lists;

/* Questi funzioni sono gia' definite, quindi e' possibile usarle direttamente */
list_of_lists *lol_create(list* val, list_of_lists *t);
void lol_print(list_of_lists *L);
void lol_destroy(list_of_lists *L);
list_of_lists *list_of_lists_create(int count, ...);

list *list_create(int val, list *t);
int list_length(list *L);
void list_destroy(list *L);
void list_print(list *L);
int is_empty(list *L);
list *list_from_array(int v[], int n);
list *list_clone(list *list);
/*
Realizzare una funzione `char f(list_of_lists *ll)` che accetta in ingresso una lista di liste di interi `ll` (si veda la struct `list_of_lists`) e restituisce
 un intero che impacchetta alcune proprietà booleane di tale lista di liste.

In particolare, si assuma output intero con rappresentazione binaria [ b7 b6 b5 b4 b3 b2 b1 b0 ], allora:

    * b0 vale 1 sse `ll` è ordinata per lunghezze non decrescenti delle sue liste componenti;
    * b1 vale 1 sse `ll` è ordinata per somme non-decrescenti degli elementi delle sue liste componenti.

Si noti che sono definite costanti per le  maschere di bit corrispondenti a queste proprietà: NON_DEC_LENGTHS, NON_DEC_SUMS..

Ad esempio, se ll = ( (1), (2, 3), (2, 5) ) l'output sarà 3 (in binario `00000011`), in quanto
    * b0 = 1, poiché (1) è più corta o uguale di (2,3) che è più corta o uguale di (2,5)
    * b1 = 1, poiché (1) ha somma 1, che è minore o uguale a alla somma 5 degli elementi di (2,3), che è minore o uguale alla somma 7 degli elementi di (2,5)

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
char f(list_of_lists *ll) {
    char result = NON_DEC_LENGTHS + NON_DEC_SUMS;
    int maxlen = -1;
    int maxsum = INT_MIN;
    for(; ll != NULL; ll = ll->next) {
        if(ll->val == NULL) continue;
        list *curlist = ll->val;
        int curlen = list_length(curlist);
        if(curlen < maxlen) result &= ~NON_DEC_LENGTHS; else maxlen = curlen;
        
        int cursum = 0;
        for(; curlist; curlist = curlist->next) {
            cursum += curlist->val;
        }
        if(cursum < maxsum) result &= ~NON_DEC_SUMS; else maxsum = cursum;
    }
    return result;
}

// STUDENT-SOLUTION-END

/**
 ** Non dovrebbe essere necessario modificare la parte seguente
 **/

/* Clona una lista */
list *list_clone(list *list) {
    if (list == NULL) return NULL;
    return list_create(list->val, list_clone(list->next));
}

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili il blocco di memoria restituita da questa
   funzione, quando non piu' utilizzata */
list *list_create(int val, list *t) {
    list *r = (list *)malloc(sizeof(list));
    r->val = val;
    r->next = t;
    return r;
}

/* Restituisce la lunghezza (numero di nodi) della lista L; se L e' la
   lista vuota, restituisce 0 */
int list_length(list *L) {
    if (NULL == L) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(list *L) {
    if (L != NULL) {
        list_destroy(L->next);
        L->next = NULL; /* non necessario... */
        free(L);
    }
}


/* Restituisce 1 sse L1 e L2 contengono gli stessi valori */
int list_equal(list *L1, list *L2) {
    if (L1 == NULL || L2 == NULL) {
        return (L1 == NULL && L2 == NULL);
    } else {
        return (L1->val == L2->val && list_equal(L1->next, L2->next));
    }
}

/* Stampa i valori contenuti nei nodi di L; si puo' avere L == NULL. */
void list_print(list *L) {
    printf("(");
    while (L != NULL) {
        printf("%d", L->val);
        if (L->next != NULL) {
            printf(" ");
        }
        L = L->next;
    }
    printf(")");
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(list *L) { return (L == NULL); }

/* Restituisce una lista con n nodi, in cui il nodo i-esimo contiene
   il valore v[i] (il nodo 0 è il primo nodo della lista). */
list *list_from_array(int v[], int n) {
    if (n > 0) {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    } else {
        return NULL;
    }
}

list_of_lists *lol_create(list* val, list_of_lists *t) { 
    list_of_lists *r = (list_of_lists *)malloc(sizeof(list_of_lists));
    r->val = val;
    r->next = t;
    return r;
}

list_of_lists *list_of_lists_create(int count, ...) {
    va_list args;
    va_start(args, count);
    list_of_lists *lol = NULL, *clol = NULL;
    for(int i=0; i<count; ++i) {
        list *l = va_arg(args, list*);
        if(clol != NULL) {
            clol->next = lol_create(l, NULL);
            clol = clol->next;
        } else {
            clol = lol_create(l, NULL);
            lol = clol;
        }
    }
    va_end(args);
    return lol;
}

void lol_print(list_of_lists *L) {
    printf("{ ");
    while (L != NULL) {
        list_print(L->val);
        if (L->next != NULL) {
            printf(" ");
        }
        L = L->next;
    }
    printf(" }");    
}

void lol_destroy(list_of_lists *L) {
    if (L != NULL) {
        list_destroy(L->val);
        lol_destroy(L->next);
    }
}


int i = 1, ok = 0, tot = 0;

void test(list_of_lists *A, char expect) {
    char ret = f(A);
    tot++;
    int success = ret == expect;
    if (success) ok++;
    printf("TEST %d: ", i++);
    // if(ret != expect) {
        printf("\n\tINPUT    = ");
        lol_print(A);        
        printf("\n\tACTUAL   = %d", ret);
        printf("\n\tEXPECTED = %d", expect);
        puts("");
    // }
    printf("%s\n---\n", success? "SUCCESS": "FAILURE");
}


int main(void) {
    list *l01 = list_from_array((int[]) { 1 }, 1), *l02 = list_from_array((int[]) { 2, 3 }, 2), *l03 = list_from_array((int[]) { 2, 5 }, 2);
    list_of_lists *l0 = list_of_lists_create(3, l01, l02, l03);
    test(l0, NON_DEC_LENGTHS | NON_DEC_SUMS);

    list *l11 = list_from_array((int[]) { 1,2,3 }, 3), *l12 = list_from_array((int[]) { 7,8 }, 2);
    list_of_lists *l1 = list_of_lists_create(2, l11, l12);
    test(l1, NON_DEC_SUMS);

    list *l21 = list_from_array((int[]) { 1,2,3 }, 3), *l22 = list_from_array((int[]) { 1,1 }, 2);
    list_of_lists *l2 = list_of_lists_create(2, l21, l22);
    test(l2, 0);


    list *l31 = list_from_array((int[]) { 1,2,3 }, 3), *l32 = list_from_array((int[]) { 1,1,1,1 }, 4);
    list_of_lists *l3 = list_of_lists_create(2, l31, l32);
    test(l3, NON_DEC_LENGTHS);

    list_of_lists* lists[] = { l0, l1, l2, l3}; 
    int nlists = sizeof(lists) / sizeof(list*);
    for(int i=0; i < nlists; i++) { lol_destroy(lists[i]); }

    printf("\n\n%d tests passed out of %d\n", ok, tot);
    return 0;
}
