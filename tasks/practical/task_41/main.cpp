/*
 * Задание 41. Считать целые числа из input.txt и записать сумму в output.txt.
 * Ввод: файл input.txt с целыми числами.
 * Вывод: файл output.txt с суммой; Error в stderr при любой ошибке.
 * Пример: input.txt = "2 3 -1" -> output.txt = "4".
 */
#include <climits>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Error\n";
        return 1;
    }
    long long sum = 0;
    long long x;
    while (input >> x) {
        if ((x > 0 && sum > LLONG_MAX - x) ||
            (x < 0 && sum < LLONG_MIN - x)) {
            std::cerr << "Error\n";
            return 1;
        }
        sum += x;
    }
    if (!input.eof()) {
        std::cerr << "Error\n";
        return 1;
    }
    std::ofstream output("output.txt");
    if (!output) {
        std::cerr << "Error\n";
        return 1;
    }
    output << sum << '\n';
    return 0;
}
