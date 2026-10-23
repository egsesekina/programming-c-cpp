/*
 * Задание 8. Изменить исходную переменную через ссылочный параметр.
 * Ввод: одно целое число меньше INT_MAX.
 * Вывод: число, увеличенное на единицу.
 * Пример: 10 -> 11.
 */
#include <climits>
#include <iostream>

void increment(int& value) {
    ++value;
}

int main() {
    int number;
    if (!(std::cin >> number) || number == INT_MAX) {
        std::cerr << "Error\n";
        return 1;
    }
    increment(number);
    std::cout << number << '\n';
    return 0;
}
