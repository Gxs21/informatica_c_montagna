#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int matrix_equals(int **a, int **b, int a_rows, int a_cols, int b_rows, int b_cols); // controlla l'uguaglianza di due matrici
void free_matrix(int **a, int a_rows); // libera la memoria associata a una matrice
void print_matrix(int **a, int a_rows, int a_cols); // stampa in stdout una matrice
int **make_matrix(int rows, int cols, int elem); // costruisce una matrice di `rows` righe e `cols` colonne, con ogni cella inizializzata a `elem`
int **build_matrix(int rows, int cols, int *elems); // costruisce una matrice di `rows` righe e `cols` colonne, con contenuto fornito sequenzialmente dall'array `elems`
int check_pattern_matrix(int **matrix, int N, int M, int expected); // funzione di test

/*
Implementare una funzione f(matrix, N) che

- accetta in ingresso una matrice quadrata N x N di interi, e
- restituisce 1 (TRUE) se la matrice rappresenta una "X", altrimenti FALSE.

Una matrice rappresenta una "X" se ha lo stesso elemento lungo le due diagonali principali e un altro elemento diverso negli altri spazi. Ad esempio:

        { 5, 0, 5,
          0, 5, 0
          5, 0, 5 }   (il 5 ripetuto nei segmenti diagonali disegna la forma X, mentre lo 'sfondo' del simbolo è uniformemente dato dallo 0)

        { 5 }   (questa è una forma triviale)

Si noti che nel caso di matrice quadrate dove N è pari, la forma 'X' può comunque realizzarsi in forma più "bombata".

        { 5, 5,
          5, 5 }          (anche questa è una forma X triviale)

        { 1, 2, 2, 1,
          2, 1, 1, 2,
          2, 1, 1, 2,
          1, 2, 2, 1 }    (la forma X è data dalle due diagonali che però non si intersecano)

Esempi negativi sono i seguenti:

        { 5, 5,
          5, 0 }

        { 5, 0, 5, 
          0, 8, 0,
          5, 0, 5 }      (elemento non uniforme nella forma X)

        { 5, 0, 5, 
          0, 5, 0,
          5, 8, 5 }      (elemento non uniforme nello sfondo)


NOTE GENERALI:
*) ATTENZIONE: la propria soluzione va inserita nella porzione del sorgente inclusa tra i commenti single-line
`// STUDENT-SOLUTION-START` e `// STUDENT-SOLUTION-END`.
Codice scritto al di fuori di tali commenti non sarà considerato durante la valutazione.
*) E' possibile definire più funzioni ausiliarie qualora lo si ritenga opportuno.
Ma lo si faccia all'interno dei commenti, come indicato nel punto precedente.
*) ATTENZIONE: la soluzione verrà confrontata con quella dei colleghi mediante strumenti automatici al fine
di rilevare potenziali copiature. Il controllo è resistente a rename di variabili, spezzamento di espressioni etc.
Qualora vengano riscontrate similarità importanti, è possibile che la prova possa venire annullata, e che ulteriori
modalità di verifica di competenze (ad es., prove orali) siano attuate.
*/
// STUDENT-SOLUTION-START
int f(int **matrix, int N) {
    if (N <= 1) return TRUE;
    
    int x_elem = matrix[0][0];
    int x_fill_elem = N > 2 ? matrix[1][0] : x_elem;

    // Check for "X" pattern
    int is_x = N>2 ? x_elem != x_fill_elem : x_elem == x_fill_elem;
    if(is_x) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i == j || i + j == N - 1)) {
                    if (matrix[i][j] != x_elem) {
                        is_x = FALSE;
                    }
                } else {
                    if (matrix[i][j] != x_fill_elem) {
                        is_x = FALSE;
                    }
                }
            }
        }
    }

    return is_x;
}
// STUDENT-SOLUTION-END

void test(){
    int** m00 = build_matrix(1, 1, (int[]) 
        { 1 }
    );
    check_pattern_matrix(m00, 1, 1, TRUE);


    int** m03 = build_matrix(2, 2, (int[]) 
        { 5, 5, 
          5, 5 }
    );
    check_pattern_matrix(m03, 2, 2, TRUE);

    int** m04 = build_matrix(3, 3, (int[]) 
        { 5, 0, 5,
          0, 5, 0, 
          5, 0, 5 }
    );
    check_pattern_matrix(m04, 3, 3, TRUE);

    int** m05 = build_matrix(3, 3, (int[]) 
        { 5, 0, 5,
          0, 8, 0, 
          5, 0, 5 }
    );
    check_pattern_matrix(m05, 3, 3, FALSE);

    int** m06 = build_matrix(3, 3, (int[]) 
        { 5, 0, 5,
          0, 5, 0, 
          5, 8, 5 }
    );
    check_pattern_matrix(m06, 3, 3, FALSE);


    int** m0 = build_matrix(5, 5, (int[]) 
        { 1, 2, 2, 2, 1,
          2, 1, 2, 1, 2,
          2, 2, 1, 2, 2,
          2, 1, 2, 1, 2,
          1, 2, 2, 2, 1 }
    );
    check_pattern_matrix(m0, 5, 5, TRUE);

    int** m1 = build_matrix(5, 5, (int[]) 
        { 1, 0, 0, 0, 1,
          0, 1, 0, 1, 0,
          0, 0, 1, 0, 0,
          0, 1, 0, 1, 0,
          1, 0, 0, 0, 1 }
    );
    check_pattern_matrix(m1, 5, 5, TRUE);

    int** m2 = build_matrix(5, 5, (int[]) 
        { 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1,
          1, 1, 1, 1, 1,
          1, 1, 1, 1, 1,
          1, 1, 1, 1, 1 }
    );
    check_pattern_matrix(m2, 5, 5, FALSE);

    int** m3 = build_matrix(5, 5, (int[]) 
        { 0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          1, 1, 1, 1, 1,
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0 }
    );
    check_pattern_matrix(m3, 5, 5, FALSE);

    int** m4 = build_matrix(4, 4, (int[]) 
        { 1, 2, 2, 1,
          2, 1, 1, 2,
          2, 1, 1, 2,
          1, 2, 2, 1 }
    );
    check_pattern_matrix(m4, 4, 4, TRUE);
}

int i = 0, success = 0;

int main(){
    test();
    printf("=== SUCCESS %d OUT OF %d TESTS ===\n", success , i);
    return 0;
}

int check_pattern_matrix(int **matrix, int N, int M, int expected) {
    printf("\n-----------------\nTEST %d\n-----------------\n", i++);
    int result = f(matrix, N);
    int equals = (result == expected);
    print_matrix(matrix, N, M);
    puts("");
    printf("Actual:   %d\n", result);
    printf("Expected: %d\n", expected);
    printf("Result: %s\n", equals ? "OK" : "FAIL");
    if (equals) {
        success++;
    }
    printf("\n");
    free_matrix(matrix, N);
    return equals;
}

int **make_matrix(int rows, int cols, int elem) {
    int** m = (int **) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        m[i] = (int *) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            m[i][j] = elem;
        }
    }
    return m;
}

int **build_matrix(int rows, int cols, int *elems) {
    int** m = (int **) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        m[i] = (int *) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++){
            m[i][j] = elems[i * cols + j];
        }
    }
    return m;
}

int matrix_equals(int **a, int **b, int a_rows, int a_cols, int b_rows, int b_cols) {
    if(a_rows != b_rows || a_cols != b_cols) return FALSE;
    if(a == NULL) return b == NULL;
    for (int i=0; i<a_rows; i++) {
        for(int j=0; j<a_cols; j++) {
            if(a[i][j] != b[i][j]) return FALSE;
        }
    }
    return TRUE;
}

void free_matrix(int **a, int a_rows) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        free(a[i]);
    }
    free(a);
}

void print_matrix(int **a, int a_rows, int a_cols) { 
    if(a == NULL) return;
    for (int i=0; i<a_rows; i++) {
        printf("| ");
        for(int j=0; j<a_cols; j++) {
            printf("%2d ", a[i][j]);
        }
        printf(" |\n");
    }
}
