/*
 * Задание 33. Найти индекс первого вхождения заданного числа в массив.
 * Ввод: N (1..1000), N целых чисел и искомое число.
 * Вывод: индекс с нуля либо -1.
 * Пример: 5 / 8 3 8 1 0 / 8 -> 0.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cerr << "Error\n";
        return 1;
    }
    std::vector<int> a(n);
    for (int& x : a) {
        if (!(std::cin >> x)) {
            std::cerr << "Error\n";
            return 1;
        }
    }
    int target;
    if (!(std::cin >> target)) {
        std::cerr << "Error\n";
        return 1;
    }
    auto it = std::find(a.begin(), a.end(), target);
    std::cout << (it == a.end() ? -1 : int(it - a.begin())) << '\n';
    return 0;
}
