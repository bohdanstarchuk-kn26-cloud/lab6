#include <stdio.h>

#define N 12

int main(void) {
    int a[N] = {4, 3, 8, 5, 10, 6, 7, 2, 9, 12, 14, 1};
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

    /* Форматований вивід у рядок: ширина поля 8, два знаки після коми */
    printf("Array A:\n");
    for (i = 0; i < N; i++) {
        printf("%8d", a[i]);
    }
    printf("\nArray C:\n");
    for (i = 0; i < N; i++) {
        printf("%8.2f", c[i]);
    }
    printf("\n");
    return 0;
}
