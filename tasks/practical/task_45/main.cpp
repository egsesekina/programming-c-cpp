/*
 * Задание 45. Реализовать шаблон функции maxValue для сравнимых типов.
 * Ввод: два целых и два вещественных числа.
 * Вывод: максимум целой и максимум вещественной пары.
 * Пример: 3 8 / 2.5 1.7 -> 8 / 2.5.
 */
#include <cmath>
#include <iostream>

template <typename T>
T maxValue(const T& a, const T& b) {
    // Тип T должен поддерживать операцию сравнения.
    return (a < b) ? b : a;
}

int main() {
    long long first_integer, second_integer;
    double first_real, second_real;
    if (!(std::cin >> first_integer >> second_integer >>
          first_real >> second_real) ||
        !std::isfinite(first_real) || !std::isfinite(second_real)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << maxValue(first_integer, second_integer) << '\n';
    std::cout << maxValue(first_real, second_real) << '\n';
    return 0;
}
