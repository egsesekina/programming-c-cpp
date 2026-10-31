/*
 * Задание 44. Перегрузить функцию maxValue для двух и трёх аргументов.
 * Ввод: три целых числа.
 * Вывод: максимум первых двух и максимум всех трёх чисел.
 * Пример: 4 7 2 -> 7 / 7.
 */
#include <algorithm>
#include <iostream>

long long maxValue(long long a, long long b) {
    return a > b ? a : b;
}

long long maxValue(long long a, long long b, long long c) {
    return std::max(maxValue(a, b), c);
}

int main() {
    long long a, b, c;
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << maxValue(a, b) << '\n';
    std::cout << maxValue(a, b, c) << '\n';
    return 0;
}
