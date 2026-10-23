/*
 * Задание 34. Подсчитать чётные элементы массива.
 * Ввод: N (1..1000), затем N целых чисел.
 * Вывод: количество чётных элементов.
 * Пример: 5 / 1 2 4 7 8 -> 3.
 */
#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cerr << "Error\n";
        return 1;
    }
    int count = 0;
    for (int i = 0, x; i < n; ++i) {
        if (!(std::cin >> x)) {
            std::cerr << "Error\n";
            return 1;
        }
        if (x % 2 == 0) ++count;
    }
    std::cout << count << '\n';
    return 0;
}
