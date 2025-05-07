#include <stdio.h>

#define M 3
#define N 2
#define P 4

void matrix_product(double m1[M][N], double m2[N][P], double result[M][P]);
void print(double result[M][P]);

int main(void) {
    double matrix1[M][N] = {{1, 2}, {3, 4}, {5, 6}};

    double matrix2[N][P] = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    double product[M][P];

    matrix_product(matrix1, matrix2, product);
    print(product);
}

void matrix_product(double m1[M][N], double m2[N][P], double result[M][P]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void print(double result[M][P]) {
    for (int i = 0; i < M; i++) {
        printf("%g", result[i][0]);
        for (int j = 1; j < P; j++) {
            printf(", %g", result[i][j]);
        }
        printf("\n");
    }
}
