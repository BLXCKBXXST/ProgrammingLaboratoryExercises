#include <stdio.h>

int main() {
    int N;
    printf("2 или 3: ");
    scanf("%d", &N);
    
    int matrix[N][N], otvet[N], t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &matrix[i][j]);
    
    printf("Индексы уравнения: \n");
    for (int i = 0; i < N; i++)
        scanf("%d", &otvet[i]);
    
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

    if (det == 0) {
        printf("Система не имеет единственного решения\n");
        return 0;
    }
    
    printf("Решение:\n");
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                t[i][j] = (j == k) ? otvet[i] : matrix[i][j];
        
        int det2 = 0;
        switch (N) {
            case 1:
                det2 = t[0][0];
                break;
            case 2:
                det2 = t[0][0] * t[1][1] - t[0][1] * t[1][0];
                break;
            case 3:
                det2 = t[0][0]*t[1][1]*t[2][2] + 
                t[0][1]*t[1][2]*t[2][0] + 
                t[0][2]*t[1][0]*t[2][1] - 
                t[0][2]*t[1][1]*t[2][0] - 
                t[0][0]*t[1][2]*t[2][1] - 
                t[0][1]*t[1][0]*t[2][2];
                break;
        }
        printf("%.2f\n", (float)det2/det);
    }
    
    return 0;
}