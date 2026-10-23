/*
 * Задание 21. Считать массив и с помощью арифметики указателей найти
 * сумму, минимум и максимум его элементов.
 * Ввод: N (1..1000), затем N целых чисел.
 * Вывод: сумма, минимум и максимум через пробел.
 * Пример: 5 / 4 -2 7 7 1 -> 17 -2 7.
 */
#include <stdio.h>

int main(void) {
    int values[1000];
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    for (int *p = values; p < values + n; ++p) {
        if (scanf("%d", p) != 1) {
            fprintf(stderr, "Error\n");
            return 1;
        }
    }

    long long sum = 0;
    int minimum = values[0];
    int maximum = values[0];
    for (const int *p = values; p < values + n; ++p) {
        sum += *p;
        if (*p < minimum) minimum = *p;
        if (*p > maximum) maximum = *p;
    }

    printf("%lld %d %d\n", sum, minimum, maximum);
    return 0;
}
