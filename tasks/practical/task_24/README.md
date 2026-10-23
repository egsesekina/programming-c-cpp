### Задание 24. Файлы в C

**Условие.** Считать целые числа из input.txt средствами stdio.h и записать их сумму в output.txt.

#### Формат входных данных

файл input.txt с целыми числами, разделёнными пробелами.

#### Формат выходных данных

файл output.txt с одной суммой. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Файлы открываются через `fopen`, числа читаются функцией `fscanf`, результат записывается через `fprintf`. Код проверяет открытие файлов, формат данных, переполнение суммы и результат закрытия выходного файла.

#### Алгоритм

1. открыть `input.txt`.
2. читать и безопасно суммировать числа.
3. отклонить посторонние данные.
4. создать `output.txt`, записать сумму и закрыть файл.

#### Исходный код

[main.c](main.c)

```c
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

```

#### Пример работы

Ввод:

```text
input.txt: 4 -1 7
```

Вывод:

```text
output.txt: 10
```

#### Граничные случаи

Пустой файл даёт сумму 0; переполнение и нечисловой фрагмент дают `Error`.

#### Компиляция и запуск

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic main.c -o program
./program
```
