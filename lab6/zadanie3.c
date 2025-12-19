#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

double** alloc_matrix(int r, int c) {
    double **a = (double**)malloc(r * sizeof(double*));
    if (!a) return NULL;
    for (int i = 0; i < r; i++) {
        a[i] = (double*)malloc(c * sizeof(double));
        if (!a[i]) {
            for (int k = 0; k < i; k++) free(a[k]);
            free(a);
            return NULL;
        }
    }
    return a;
}

void free_matrix(double **a, int r) {
    if (!a) return;
    for (int i = 0; i < r; i++) free(a[i]);
    free(a);
}

void copy_matrix(double **dst, double **src, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dst[i][j] = src[i][j];
}

void read_matrix(double **A, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lf", &A[i][j]);
}

void read_answers(double *b, int n) {
    for (int i = 0; i < n; i++)
        scanf("%lf", &b[i]);
}

void replace_colum(double **B, double **A, double *b, int n, int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = (j == col) ? b[i] : A[i][j];
        }
    }
}

double det_gauss(double **A, int n) {
    double **M = alloc_matrix(n, n);
    if (!M) return 0.0;
    copy_matrix(M, A, n, n);

    int swaps = 0;
    for (int col = 0; col < n; col++) {
        int pivot = col;
        double best = fabs(M[col][col]);
        for (int row = col + 1; row < n; row++) {
            double val = fabs(M[row][col]);
            if (val > best) { best = val; pivot = row; }
        }

        if (best < EPS) { free_matrix(M, n); return 0.0; }

        if (pivot != col) {
            double *tmp = M[pivot];
            M[pivot] = M[col];
            M[col] = tmp;
            swaps++;
        }

        for (int row = col + 1; row < n; row++) {
            double factor = M[row][col] / M[col][col];
            for (int k = col; k < n; k++) {
                M[row][k] -= factor * M[col][k];
            }
        }
    }

    double det = (swaps % 2 == 0) ? 1.0 : -1.0;
    for (int i = 0; i < n; i++) det *= M[i][i];

    free_matrix(M, n);
    return det;
}

int kramer(double **A, double *b, double *x, int n) {
    double detA = det_gauss(A, n);
    if (fabs(detA) < EPS) return 0;

    double **T = alloc_matrix(n, n);
    if (!T) return 0;

    for (int col = 0; col < n; col++) {
        replace_colum(T, A, b, n, col);
        double detTi = det_gauss(T, n);
        x[col] = detTi / detA;
    }

    free_matrix(T, n);
    return 1;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Bad N\n");
        return 0;
    }

    double **A = alloc_matrix(n, n);
    if (!A) return 0;

    double *b = (double*)malloc(n * sizeof(double));
    if (!b) { free_matrix(A, n); return 0; }

    double *x = (double*)calloc(n, sizeof(double));
    if (!x) { free(b); free_matrix(A, n); return 0; }

    read_matrix(A, n, n);
    read_answers(b, n);

    if (!kramer(A, b, x, n)) {
        printf("deter = 0\n");
        free(x); free(b); free_matrix(A, n);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.6f\n", i, x[i]);
    }

    free(x);
    free(b);
    free_matrix(A, n);

    return 0;
}
