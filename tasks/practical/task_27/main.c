/*
 * Задание 27. Продемонстрировать статическую длительность хранения:
 * функция add хранит число вызовов, а файловая переменная — общую сумму.
 * Ввод: N (0..1000), затем N целых чисел.
 * Вывод: итоговая сумма и число вызовов add.
 * Пример: 3 / 5 -2 8 -> Sum: 11 / Calls: 3.
 */
#include <stdio.h>

static long long total = 0;

static unsigned int add(int value) {
    static unsigned int calls = 0;
    total += value;
    return ++calls;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    unsigned int calls = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Error\n");
            return 1;
        }
        calls = add(value);
    }

    printf("Sum: %lld\nCalls: %u\n", total, calls);
    return 0;
}
