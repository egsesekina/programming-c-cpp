/*
 * Задание 5. Сравнить целочисленное и вещественное деление.
 * Ввод: два целых числа, второе не равно нулю.
 * Вывод: целая часть частного и точное частное типа double.
 * Пример: 7 2 -> 3 / 3.5.
 */
#include <iostream>

int main() {
    int left, right;
    if (!(std::cin >> left >> right) || right == 0) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << left / right << '\n'
              << static_cast<double>(left) / right << '\n';
    return 0;
}
