#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int array_equals(char a[], char b[], int sizea, int sizeb);
void print_array(char *a, int size);
int matrix_equals(char **a, char **b, int a_rows, int a_cols, int b_rows, int b_cols); // controlla l'uguaglianza di due matrici
void free_matrix(char **a, int a_rows); // libera la memoria associata a una matrice
void print_matrix(char **a, int a_rows, int a_cols); // stampa in stdout una matrice
char **make_matrix(int rows, int cols, char elem); // costruisce una matrice di `rows` righe e `cols` colonne, con ogni cella inizializzata a `elem`
char **build_matrix(int rows, int cols, char *elems); // costruisce una matrice di `rows` righe e `cols` colonne, con contenuto fornito sequenzialmente dall'array `elems`
int check(char *s, char** input, char** actual, int N, int M, char* expectedN, char* expectedE, char* expectedS, char* expectedW, char* expectedI); // funzione di test

/*
Implementare una funzione f(matrix, N, M) che 

- accetta in ingresso una matrice N x M  di interi, e
- restituisce in uscita gli array corrispondenti ai 4 bordi della matrice (nell'ordine: nord-est-sud-ovest) e ai restanti elementi

In altre parole, un'invocazione f(matrix, 3, 3) con 
             | 1, 2, 3 |
    matrix = | 4, 5, 6 |
             | 7, 8, 9 |
deve restituire in output i 5 array: 
    1) bordo nord: [ 1, 2, 3 ]
    2) bordo est: [3, 6, 9]
    3) bordo sud: [7, 8, 9]
    4) bordo ovest: [1, 4, 7]
    5) interno: [5] (si noti che per matrici più grandi l'interno è composto da più elementi: si elenchino in ordine naturale, ovvero per righe e colonne)

Si impacchettino i puntatori a tali array in un array di puntatori.

Osservazioni e consigli:

* SUGGERIMENTO: Si faccia riferimento alle funzioni di test/verifica per esempi di funzionamento

* SUGGERIMENTO: si suggerisce di compilare con opzione -Wall per ottenere tutti i warning del compilatore: gcc -Wall source.c

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
char** f(char **matrix, int N, int M) {
    char **res = (char**) malloc(sizeof(char*) * 5);

    char *north = (char*) malloc(sizeof(char) * M);
    char *south = (char*) malloc(sizeof(char) * M);
    char *east = (char*) malloc(sizeof(char) * N);
    char *west = (char*) malloc(sizeof(char) * N);
    
    int num_interior = N-2 < 0 || M-2 < 0 ? 0 : (N-2) * (M-2);
    char *interior = (char*) malloc(sizeof(char) * num_interior);

    res[0] = north;
    res[1] = east;
    res[2] = south;
    res[3] = west;
    res[4] = interior;

    for(int i = 0; i < M; i++) {
        north[i] = matrix[0][i]; 
        south[i] = matrix[N-1][i];
    }

    for(int i = 0; i < N; i++) {
        west[i] = matrix[i][0]; 
        east[i] = matrix[i][M-1];
    }

    for(int k = 0, i = 1; i < N-1; i++) {
        for(int j = 1; j < M-1; j++) {
            interior[k++] = matrix[i][j];
        }
    }

    return res;
}
// STUDENT-SOLUTION-END

void test(){
    char** m0 = build_matrix(3, 3, (char[]) 
        { 1, 2, 3,
          4, 5, 6,
          7, 8, 9 }
    );
    char** p0 = f(m0, 3, 3);
    check("matrix 3 x 3", m0, p0, 3, 3, (char[]){ 1, 2, 3 }, (char[]){ 3, 6, 9 }, (char[]){ 7, 8, 9 }, (char[]){ 1, 4, 7 }, (char[]) { 5 });

    char** m1 = build_matrix(1, 1, (char[]) 
        { 77 }
    );
    char** p1 = f(m1, 1, 1);
    check("matrix 1 x 1", m1, p1, 1, 1, (char[]){ 77 }, (char[]){ 77 }, (char[]){ 77 }, (char[]){ 77 }, (char[]){ });

    char** m2 = build_matrix(4, 2, (char[]) 
        { 7, 5 ,
          2, 1 ,
          -5, 0,
          1, -8 }
    );
    char** p2 = f(m2, 4, 2);
    check("matrix 4 x 2", m2, p2, 4, 2, (char[]){ 7, 5 }, (char[]){ 5, 1, 0, -8 }, (char[]){ 1, -8 }, (char[]){ 7, 2, -5, 1 }, (char[]){ });

    char** m3 = build_matrix(2, 5, (char[]) 
        { 9, 8, 7, 6, 5,
          4, 3, 2, 1, 0 }
    );
    char** p3 = f(m3, 2, 5);
    check("matrix 2 x 5", m3, p3, 2, 5, (char[]){ 9, 8, 7, 6, 5 }, (char[]){ 5, 0 }, (char[]){ 4, 3, 2, 1, 0 }, (char[]){ 9, 4 }, (char[]){ });

    char** m4 = build_matrix(4, 5, (char[]) 
        { 9, 8, 7, 6, 5,
          4, 3, 2, 1, 0,
          1, 2, 3, 4, 5,
          6, 7, 8, 9, 10 }
    );
    char** p4 = f(m4, 4, 5);
    check("matrix 4 x 5", m4, p4, 4, 5, (char[]){ 9, 8, 7, 6, 5 }, (char[]){ 5, 0, 5, 10 }, (char[]){ 6, 7, 8, 9, 10 }, (char[]){ 9, 4, 1, 6 }, 
        (char[]){ 3, 2, 1, 2, 3, 4 });
}

int i = 0, success = 0;

int main(){
    test();
    printf("=== SUCCESS %d OUT OF %d TESTS ===\n", success , i);
    return 0;
}


int check(char* name, char** input, char** actual, int N, int M, char* expectedN, char* expectedE, char* expectedS, char* expectedW, char* expectedI) {
    printf("\n-----------------\nTEST %d: %s\n-----------------\n", i++, name);
    if(actual == NULL && expectedN != NULL) {
        printf("Result: FAIL\n");
        return 0;
    }
    int xyz = N-2 < 0 || M-2 < 0 ? 0 : (N-2) * (M-2);
    int equals = array_equals(actual[0], expectedN, M, M) && array_equals(actual[1], expectedE, N, N) && 
        array_equals(actual[2], expectedS, M, M) && array_equals(actual[3], expectedW, N, N) && array_equals(actual[4], expectedI, xyz, xyz);
    print_matrix(input, N, M);
    puts("");
    if(!equals){
        printf("Result: FAIL\n");
        printf("Actual:   ");
        print_array(actual[0], M);
        print_array(actual[1], N);
        print_array(actual[2], M);
        print_array(actual[3], N);
        print_array(actual[4], xyz);
        printf("\nExpected: ");
        print_array(expectedN, M);
        print_array(expectedE, N);
        print_array(expectedS, M);
        print_array(expectedW, N);
        print_array(expectedI, xyz);  
    } else {
        success++;
        printf("Result: OK\n");
    }
    printf("\n");
    free(actual[0]); free(actual[1]); free(actual[2]); free(actual[3]);
    free(actual);
    free_matrix(input, N);
    return equals;
}

char **make_matrix(int rows, int cols, char elem) {
    char** m = (char **) malloc(rows * sizeof(char*));
    for(int i=0; i<rows; i++){
        m[i] = (char *) malloc(cols * sizeof(char));
        for(int j=0; j<cols; j++){
            m[i][j] = elem;
        }
    }
    return m;
}

char **build_matrix(int rows, int cols, char *elems) {
    char** m = (char **) malloc(rows * sizeof(char*));
    for(int i=0; i<rows; i++){
        m[i] = (char *) malloc(cols * sizeof(char));
        for(int j=0; j<cols; j++){
            m[i][j] = elems[i * cols + j];
        }
    }
    return m;
}

int matrix_equals(char **a, char **b, int a_rows, int a_cols, int b_rows, int b_cols) {
    if(a_rows != b_rows || a_cols != b_cols) return FALSE;
    if(a == NULL) return b == NULL;
    for (int i=0; i<a_rows; i++) {
        for(int j=0; j<a_cols; j++) {
            if(a[i][j] != b[i][j]) return FALSE;
        }
    }
    return TRUE;
}


void free_matrix(char **a, int a_rows) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        free(a[i]);
    }
    free(a);
}

void print_matrix(char **a, int a_rows, int a_cols) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        printf("| ");
        for(int j=0; j<a_cols; j++) {
            printf("%2d ", a[i][j]);
        }
        printf(" |\n");
    }
}

int array_equals(char a[], char b[], int sizea, int sizeb){
    if(a == b) return FALSE;  // shouldn't pass the same array
    if(sizea != sizeb) return FALSE;
    for (; sizea--;)
        if (a[sizea] != b[sizea])
            return FALSE;
    return TRUE;
}

void print_array(char *a, int size){
    int i;
    printf("[");
    for (i=0; i<size; i++) printf("%d%s", a[i], i<size-1 ? "," : "");
    printf("]");
} 
