/*
 * Задание 28. Создать безопасно заключённый в скобки макрос SQUARE и
 * использовать условную компиляцию для диагностического сообщения.
 * Ввод: целое X, |X| <= 3037000499.
 * Вывод: квадрат X.
 * Пример: -12 -> 144.
 */
#include <stdio.h>

#define SQUARE(value) ((value) * (value))

int main(void) {
    long long x;
    if (scanf("%lld", &x) != 1 || x < -3037000499LL || x > 3037000499LL) {
        fprintf(stderr, "Error\n");
        return 1;
    }
#ifdef DEBUG
    fprintf(stderr, "DEBUG: x=%lld\n", x);
#endif
    printf("%lld\n", SQUARE(x));
    return 0;
}
