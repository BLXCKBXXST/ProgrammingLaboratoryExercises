#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    scanf("%d", &N);

    float re[N], im[N];

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        re[i] = (float)(rand() % 65536 - 32768);
        im[i] = (float)(rand() % 65536 - 32768);
    }

    for (int i = 0; i < N; i++) {
        printf("s[%d] = %.1f + j*(%.1f)\n", i, re[i], im[i]);
    }

    float energy = 0;
    for (int i = 0; i < N; i++) {
        energy += re[i] * re[i] + im[i] * im[i];
    }
        printf("energy %.1f\n", energy);

    if (N > 0) {
        float max_re = re[0];
        for (int i = 1; i < N; i++) {
            if (re[i] > max_re) {
                max_re = re[i];
            }
        }
    printf("max %.1f\n", max_re);

    return 0;
    }
}