/*
 * Задание 12. Выполнить целочисленное деление и обработать нулевой делитель.
 * Ввод: два целых числа.
 * Вывод: частное либо Error при нулевом делителе.
 * Пример: 12 3 -> 4.
 */
#include <climits>
#include <iostream>
#include <stdexcept>

int divide(int numerator, int denominator) {
    if (denominator == 0) throw std::invalid_argument("division by zero");
    if (numerator == INT_MIN && denominator == -1) {
        throw std::overflow_error("integer overflow");
    }
    return numerator / denominator;
}

int main() {
    int numerator, denominator;
    if (!(std::cin >> numerator >> denominator)) {
        std::cerr << "Error\n";
        return 1;
    }
    try {
        std::cout << divide(numerator, denominator) << '\n';
    } catch (const std::exception&) {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}
