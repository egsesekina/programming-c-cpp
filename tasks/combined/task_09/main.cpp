/*
 * Задание 9. Получить третий элемент массива арифметикой указателей.
 * Ввод: пять целых чисел.
 * Вывод: третий элемент.
 * Пример: 4 8 15 16 23 -> 15.
 */
#include <iostream>

int main() {
    int values[5];
    for (int& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Error\n";
            return 1;
        }
    }
    const int* first = values;
    std::cout << *(first + 2) << '\n';
    return 0;
}
