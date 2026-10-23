/*
 * Задание 44. Перегрузить функцию maxValue для двух и трёх аргументов.
 * Ввод: отсутствует.
 * Вывод: 7 и 7 на отдельных строках.
 * Пример запуска: program -> 7 / 7.
 */
#include <algorithm>
#include <iostream>

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int maxValue(int a, int b, int c) {
    return std::max(maxValue(a, b), c);
}

int main() {
    std::cout << maxValue(4, 7) << '\n';
    std::cout << maxValue(4, 7, 2) << '\n';
    return 0;
}
