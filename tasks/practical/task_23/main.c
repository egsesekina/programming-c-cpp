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
