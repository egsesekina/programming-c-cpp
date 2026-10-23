/*
 * Задание 10. Управлять динамическим массивом с помощью unique_ptr.
 * Ввод: N (1..100000), затем N целых чисел.
 * Вывод: сумма элементов.
 * Пример: 4 / 1 2 3 4 -> 10.
 */
#include <iostream>
#include <memory>

int main() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 100000) {
        std::cerr << "Error\n";
        return 1;
    }
    auto values = std::make_unique<int[]>(static_cast<std::size_t>(n));
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> values[i])) {
            std::cerr << "Error\n";
            return 1;
        }
        sum += values[i];
    }
    std::cout << sum << '\n';
    return 0;
}
