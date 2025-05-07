#include <stdio.h>
#include <stdlib.h> // for abs()

#define N 10

void print_matrix(int matrix[][N]);

void set_all_to(int matrix[][N], int value);
void set_top_right_half_to(int matrix[][N], int value);
void set_diagonal_to(int matrix[][N], int value, int thickness);
void set_antidiagonal_to(int matrix[][N], int value);

int main(void) {
    int matrix[N][N];

    printf("All zeros:\n");
    set_all_to(matrix, 0);
    print_matrix(matrix);
    printf("\n");

    printf("Top-right half to 1\n");
    set_all_to(matrix, 0);
    set_top_right_half_to(matrix, 1);
    print_matrix(matrix);
    printf("\n");

    printf("Thick diagonal to 1\n");
    set_all_to(matrix, 0);
    set_diagonal_to(matrix, 1, 1);
    print_matrix(matrix);
    printf("\n");

    printf("Antidiagonal to 1\n");
    set_all_to(matrix, 0);
    set_antidiagonal_to(matrix, 1);
    print_matrix(matrix);

}

void print_matrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < N; j++) {
            printf(", %d", matrix[i][j]);
        }
        printf("\n");
    }
}

void set_all_to(int matrix[][N], int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = value;
        }
    }
}

void set_top_right_half_to(int matrix[][N], int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < j) {
                matrix[i][j] = value;
            }
        }
    }
}

void set_diagonal_to(int matrix[][N], int value, int thickness) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(i - j) <= thickness) {
                matrix[i][j] = value;
            }
        }
    }
}

void set_antidiagonal_to(int matrix[][N], int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j == N - 1) {
                matrix[i][j] = value;
            }
        }
    }
}
