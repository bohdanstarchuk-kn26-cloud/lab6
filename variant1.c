#include <stdio.h>

#define N 12

int main(void) {
    int a[N] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 3};
    double c[N];
    int i, odd_count = 0, idx = -1;

    /* Копіюємо A в C і шукаємо індекс другого непарного елемента */
    for (i = 0; i < N; i++) {
        c[i] = a[i];
        if (a[i] % 2 != 0) {
            odd_count++;
            if (odd_count == 2) {
                idx = i;
            }
        }
    }

    /* Якщо знайдено другий непарний, ділимо на нього всі наступні елементи */
    if (idx != -1) {
        for (i = idx + 1; i < N; i++) {
            c[i] = a[i] / (double)a[idx];
        }
    } else {
        printf("Fewer than two odd elements, C is a copy of A\n");
    }

    printf("Array A: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\nArray C: ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");
    return 0;
}
