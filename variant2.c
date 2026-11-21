#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main(void) {
    double a[MAX], b[MAX];
    double sum_neg = 0, sum_pos = 0, mean_neg = 0, mean_pos = 0;
    int cnt_neg = 0, cnt_pos = 0, i, n;

    /* Розмір масиву вводиться з клавіатури */
    printf("Enter array size (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid array size\n");
        return 1;
    }

    /* Заповнення масиву випадковими числами від -20 до 20 */
    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 41 - 20;
    }

    /* Підрахунок сум і кількості від'ємних та додатних елементів */
    for (i = 0; i < n; i++) {
        b[i] = a[i];
        if (a[i] < 0) {
            sum_neg += a[i];
            cnt_neg++;
        } else if (a[i] > 0) {
            sum_pos += a[i];
            cnt_pos++;
        }
    }

    if (cnt_neg > 0) mean_neg = sum_neg / cnt_neg;
    if (cnt_pos > 0) mean_pos = sum_pos / cnt_pos;

    /* Особливі випадки: всі від'ємні -> 0, всі додатні -> 1 */
    if (cnt_pos == 0) {
        mean_pos = 0;
    } else if (cnt_neg == 0) {
        mean_pos = 1;
    }

    /* Нумерація місць з одиниці: парні місця мають індекси 1, 3, 5, ... */
    for (i = 0; i < n; i++) {
        int place = i + 1;
        if (place % 2 == 0) {
            if (a[i] < 0) {
                b[i] = mean_neg;
            }
        } else {
            b[i] = mean_pos;
        }
    }

    printf("Array A: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\nArray B: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");
    return 0;
}
