#include <stdio.h>

#define MAX 100

int main(void) {
    int a[MAX], n;
    double c[MAX];
    int i, odd_count = 0, idx = -1;

    /* Введення розміру та елементів масиву з клавіатури */
    printf("Enter array size (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid array size\n");
        return 1;
    }
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* Копіюємо A в C і шукаємо індекс другого непарного елемента */
    for (i = 0; i < n; i++) {
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
        for (i = idx + 1; i < n; i++) {
            c[i] = a[i] / (double)a[idx];
        }
    } else {
        printf("Fewer than two odd elements, C is a copy of A\n");
    }

    /* Форматований вивід у рядок: ширина поля 8, два знаки після коми */
    printf("Array A:\n");
    for (i = 0; i < n; i++) {
        printf("%8d", a[i]);
    }
    printf("\nArray C:\n");
    for (i = 0; i < n; i++) {
        printf("%8.2f", c[i]);
    }
    printf("\n");
    return 0;
}
