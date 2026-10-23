/*
 * Задание 24. Считать целые числа из input.txt средствами stdio.h и
 * записать их сумму в output.txt.
 * Ввод: файл input.txt с целыми числами, разделёнными пробелами.
 * Вывод: файл output.txt с одной суммой.
 * Пример: input.txt = "4 -1 7" -> output.txt = "10".
 */
#include <limits.h>
#include <stdio.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    long long sum = 0;
    long long value;
    int status;
    while ((status = fscanf(input, "%lld", &value)) == 1) {
        if ((value > 0 && sum > LLONG_MAX - value) ||
            (value < 0 && sum < LLONG_MIN - value)) {
            fclose(input);
            fprintf(stderr, "Error\n");
            return 1;
        }
        sum += value;
    }
    if (status != EOF) {
        fclose(input);
        fprintf(stderr, "Error\n");
        return 1;
    }
    fclose(input);

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fprintf(output, "%lld\n", sum);
    if (fclose(output) != 0) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    return 0;
}
