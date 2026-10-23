### Задание 23. Строки в C

**Условие.** Найти первое вхождение подстроки в C-строке средствами библиотеки string.h.

#### Формат входных данных

первая строка — текст, вторая — искомая подстрока (UTF-8, до 255 байт).

#### Формат выходных данных

байтовый индекс первого вхождения или -1. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

`fgets` читает строку в массив `char`, `strcspn` удаляет перевод строки, а `strstr` возвращает указатель на первое вхождение. Разность двух указателей внутри одного массива даёт байтовый индекс.

#### Алгоритм

1. считать две строки и удалить переводы строк.
2. отклонить пустую подстроку.
3. вызвать `strstr`.
4. вывести разность указателей либо `-1`.

#### Исходный код

[main.c](main.c)

```c
/*
 * Задание 23. Найти первое вхождение подстроки в C-строке средствами
 * библиотеки string.h.
 * Ввод: первая строка — текст, вторая — искомая подстрока (UTF-8, до 255 байт).
 * Вывод: байтовый индекс первого вхождения или -1.
 * Пример: abracadabra / cada -> 4.
 */
#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum { BUFFER_SIZE = 256 };

static int read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) return 0;
    size_t end = strcspn(buffer, "\r\n");
    if (buffer[end] == '\0' && end == size - 1) return 0;
    buffer[end] = '\0';
    return 1;
}

int main(void) {
    char text[BUFFER_SIZE];
    char pattern[BUFFER_SIZE];
    if (!read_line(text, sizeof(text)) || !read_line(pattern, sizeof(pattern)) ||
        pattern[0] == '\0') {
        fprintf(stderr, "Error\n");
        return 1;
    }

    const char *position = strstr(text, pattern);
    printf("%td\n", position == NULL ? (ptrdiff_t)-1 : position - text);
    return 0;
}

```

#### Пример работы

Ввод:

```text
abracadabra
cada
```

Вывод:

```text
4
```

#### Граничные случаи

Индекс измеряется в байтах UTF-8; пустая искомая строка намеренно считается ошибкой.

#### Компиляция и запуск

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic main.c -o program
./program
```
