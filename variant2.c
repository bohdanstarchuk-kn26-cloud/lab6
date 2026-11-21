#include <stdio.h>

#define N 14

int main(void) {
    double a[N] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -1, -2, -3, -4, -5};
    double b[N];
    double sum_neg = 0, sum_pos = 0, mean_neg = 0, mean_pos = 0;
    int cnt_neg = 0, cnt_pos = 0, i;

    /* Підрахунок сум і кількості від'ємних та додатних елементів */
    for (i = 0; i < N; i++) {
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
    for (i = 0; i < N; i++) {
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
    for (i = 0; i < N; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\nArray B: ");
    for (i = 0; i < N; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");
    return 0;
}
