/*
 * Задание 22. Выделить динамический массив через malloc, считать его,
 * вывести элементы в обратном порядке и освободить память через free.
 * Ввод: N (1..100000), затем N целых чисел.
 * Вывод: элементы в обратном порядке.
 * Пример: 4 / 10 20 30 40 -> 40 30 20 10.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100000) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    int *values = malloc((size_t)n * sizeof(*values));
    if (values == NULL) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            free(values);
            fprintf(stderr, "Error\n");
            return 1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        printf("%d%c", values[i], i == 0 ? '\n' : ' ');
    }
    free(values);
    return 0;
}
