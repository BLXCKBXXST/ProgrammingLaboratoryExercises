#include <stdio.h>
#include <math.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isPrime(int num) {
    if (num < 2) 
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    int limit = (int)sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int countPrimes(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i]))
            count++;
    }
    return count;
}

double average(int arr[], int size) {
    if (size == 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    int X[] = {3, 8, 7, 10, 5, 6, 2, 9};
    int n = sizeof(X) / sizeof(X[0]);

    int Y[n / 2 + 1];
    int k = 0;

    for (int i = 1; i < n; i += 2) {
        Y[k++] = X[i];
    }

    printArray(X, n);
    printArray(Y, k);

    int primeCountX = countPrimes(X, n);
    int primeCountY = countPrimes(Y, k);

    printf("Количество простых чисел в X: %d\n", primeCountX);
    printf("Количество простых чисел в Y: %d\n", primeCountY);

    double avgX = average(X, n);
    double avgY = average(Y, k);

    printf("Среднее арифметическое элементов X: %.2f\n", avgX);
    printf("Среднее арифметическое элементов Y: %.2f\n", avgY);

    return 0;
}
