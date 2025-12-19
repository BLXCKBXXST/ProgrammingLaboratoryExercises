#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    scanf("%d", &N);
    int matrix[N][N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int det = 0;
    switch (N) {
        case 1:
            det = matrix[0][0];
            break;
        case 2:
            det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            break;
        case 3:
            det = matrix[0][0]*matrix[1][1]*matrix[2][2] + 
            matrix[0][1]*matrix[1][2]*matrix[2][0] + 
            matrix[0][2]*matrix[1][0]*matrix[2][1] - 
            matrix[0][2]*matrix[1][1]*matrix[2][0] - 
            matrix[0][0]*matrix[1][2]*matrix[2][1] - 
            matrix[0][1]*matrix[1][0]*matrix[2][2];
            break;
    }
    printf("Deter %d\n", det);
}