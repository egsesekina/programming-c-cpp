/*
 * Задание 35. Вычислить НОД двух неотрицательных целых чисел.
 * Ввод: два значения типа long long, не оба равны нулю.
 * Вывод: наибольший общий делитель.
 * Пример: 48 18 -> 6.
 */
#include <iostream>

// Алгоритм Евклида.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    long long a, b;
    if (!(std::cin >> a >> b) || a < 0 || b < 0 || (a == 0 && b == 0)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << gcd(a, b) << '\n';
    return 0;
}
