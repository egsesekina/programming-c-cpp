/*
 * Задание 39. Найти сумму главной диагонали квадратной матрицы.
 * Ввод: N (1..100), затем N*N целых чисел.
 * Вывод: сумма элементов a[i][i].
 * Пример: 2 / 1 2 / 3 4 -> 5.
 */
#include <iostream>

int main() {
    int n;
    if (!(std::cin >> n) || n < 1 || n > 100) {
        std::cerr << "Error\n";
        return 1;
    }
    long long diagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            if (!(std::cin >> x)) {
                std::cerr << "Error\n";
                return 1;
            }
            if (i == j) diagonalSum += x;
        }
    }
    std::cout << diagonalSum << '\n';
    return 0;
}
