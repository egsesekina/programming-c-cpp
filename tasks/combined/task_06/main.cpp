/*
 * Задание 6. Реализовать исправленный цикл, выводящий числа от 1 до N.
 * Ввод: N от 1 до 1000.
 * Вывод: числа 1..N через пробел.
 * Пример: 5 -> 1 2 3 4 5.
 */
#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cerr << "Error\n";
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << i << (i == n ? '\n' : ' ');
    }
    return 0;
}
