/*
 * Задание 45. Реализовать шаблон функции maxValue для сравнимых типов.
 * Ввод: отсутствует.
 * Вывод: 8 и 2.5 на отдельных строках.
 * Пример запуска: program -> 8 / 2.5.
 */
#include <iostream>

template <typename T>
T maxValue(const T& a, const T& b) {
    // Тип T должен поддерживать операцию сравнения.
    return (a < b) ? b : a;
}

int main() {
    std::cout << maxValue(3, 8) << '\n';
    std::cout << maxValue(2.5, 1.7) << '\n';
    return 0;
}
